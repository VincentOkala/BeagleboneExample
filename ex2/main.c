#include <stdio.h>
#include <string.h>
#include <time.h>

#include <serialib.h>
#include <led.h>
#include <adc.h>
#include <pwm.h>

#define MAX_BUF 100

void delay(unsigned int milliseconds){
    clock_t start = clock();
    while((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

int main(int argc, char *argv[]){

    serial *s;
    if (serial_open(&s, "/dev/ttyO5", 115200) == 0){
        printf("Port opened.\n");

    } else {
        printf("Problem with port opening\n");
        return -1;
    }
    printf("%s -> %d\n", s->port, s->fd);

    char cmd[128];
    serial_read(s, cmd, '\r', 128);
    char adc_pin = atoi(cmd);
    printf("adc_pin: %d\n", adc_pin);
    
    int adc_value;

    char buf[MAX_BUF]; 

    while(1){
        adc_value = readADC(adc_pin);
        snprintf(buf, sizeof(buf), "adc: %d \r\n", adc_value);
        serial_write(s, buf);
        delay(500);
    }

   return 0;
}
