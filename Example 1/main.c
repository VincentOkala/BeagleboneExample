/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: main.c
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 20:31:29
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 20:40:41
 * @Description: input two pwm period and two pwm .
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#include <serialib.h>
#include <led.h>
#include <adc.h>
#include <pwm.h>

#define UART_PORT       "/dev/ttyO5"
#define UART_BAUD       115200
#define CMD_BUFF_LEN    128
/**
 * @brief Pause the system in milliseconds
 * @param milliseconds Time to pause in mini seconds
 */
void delay(unsigned int milliseconds)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

int main(int argc, char *argv[])
{

    // init serial interface
    serial *s;
    if (serial_open(&s, UART_PORT, UART_BAUD) == 0)
    {
        printf("Port opened.\n");
    }
    else
    {
        printf("Problem with port opening\n");
        return -1;
    }
    printf("%s -> %d\n", s->port, s->fd);

    // get two periods and two duty circles
    char cmd[CMD_BUFF_LEN];
    serial_read(s, cmd, '\r', CMD_BUFF_LEN);
    int period_1 = atoi(cmd);
    serial_read(s, cmd, '\r', CMD_BUFF_LEN);
    int duty_1 = atoi(cmd);
    serial_read(s, cmd, '\r', CMD_BUFF_LEN);
    int period_2 = atoi(cmd);
    serial_read(s, cmd, '\r', CMD_BUFF_LEN);
    int duty_2 = atoi(cmd);

    // print out the input
    printf("period_1: %d\n", period_1);
    printf("duty_1: %d\n", duty_1);
    printf("period_2: %d\n", period_2);
    printf("duty_2: %d\n", duty_2);

    // make changes to two pwm
    export_pwms(0);
    set_period(0, period_1);
    set_duties(0, duty_1);
    start_pwms(0);

    export_pwms(1);
    set_period(1, period_2);
    set_duties(1, duty_2);
    start_pwms(1);

    // run into a infinite loop which does nothing
    while (1);

    return 0;
}
