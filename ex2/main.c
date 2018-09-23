/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: main.c
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 21:18:37
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 21:20:45
 * @Description: Read a number, print out the adc value at such pin.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#include <serialib.h>
#include <led.h>
#include <adc.h>
#include <pwm.h>

#define MAX_BUF 100

/**
 * @brief Pause the system in milliseconds
 * @param milliseconds Time to pause in mini seconds
 */
void delay(unsigned int milliseconds){
    clock_t start = clock();
    while((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

int main(int argc, char *argv[]){

	// init serial interface
    serial *s;
    if (serial_open(&s, "/dev/ttyO5", 115200) == 0){ //define macro of com port. Ex : #define COM_PORT_SYSFS "/dev/ttyO5"
	    								//Define baudrate use macro 
        printf("Port opened.\n");

    } else {
        printf("Problem with port opening\n");
        return -1;
    }
    printf("%s -> %d\n", s->port, s->fd);

    // get adc pin at which we need to read the adc value
    char cmd[128]; // can use define macro the size of buffer here. #define MAXIMUM_SIZE_BUFFER 128
    serial_read(s, cmd, '\r', 128);
    char adc_pin = atoi(cmd);
    printf("adc_pin: %d\n", adc_pin);
    
    int adc_value; // should initial variable in the top of function
    char buf[MAX_BUF];  //good job!!!
    // infinite loop for printing out the adc value of the input pin
    while(1){
        adc_value = readADC(adc_pin);
        snprintf(buf, sizeof(buf), "adc: %d \r\n", adc_value);
        serial_write(s, buf);
        delay(500);
    }

   return 0;
}
