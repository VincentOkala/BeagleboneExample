#include <stdio.h>
#include <string.h>
#include <time.h>

#include <serialib.h>
#include <led.h>
#include <adc.h>
#include <pwm.h>

void delay(unsigned int milliseconds){
    clock_t start = clock();
    while((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

int main(int argc, char *argv[]){

    // init serial interface
    serial *s;
    if (serial_open(&s, "/dev/ttyO5", 115200) == 0){
        printf("Port opened.\n");

    } else {
        printf("Problem with port opening\n");
        return -1;
    }
    printf("%s -> %d\n", s->port, s->fd);

    // get two number and print it out
    char cmd[128];
    serial_read(s, cmd, '\r', 128);
    int number_A = atoi(cmd);
    serial_read(s, cmd, '\r', 128);
    int number_B = atoi(cmd);
    printf("number_A: %d\n", number_A);
    printf("number_B: %d\n", number_B);

    int i;
    // infinite loop for counting number with led
    while(1){
    	for(i = number_A; i <= number_B; i++){
    		led_num(i);
    		delay(1000);
    	}
    }

   return 0;
}
