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
    int period_1 = atoi(cmd);
    serial_read(s, cmd, '\r', 128);
    int duty_1 = atoi(cmd);
    serial_read(s, cmd, '\r', 128);
    int period_2 = atoi(cmd);
    serial_read(s, cmd, '\r', 128);
    int duty_2 = atoi(cmd);

    printf("period_1: %d\n", period_1);
    printf("duty_1: %d\n", duty_1);
    printf("period_2: %d\n", period_2);
    printf("duty_2: %d\n", duty_2);

    export_pwms(0);
    set_period(0, period_1);
    set_duties(0, duty_1);
    start_pwms(0);
    
    export_pwms(1);
    set_period(1, period_2);
    set_duties(1, duty_2);
    start_pwms(1);

    while(1);

   return 0;
}
