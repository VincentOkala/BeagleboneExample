/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: led.h
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 20:48:31
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 20:49:37
 * @Description: led header file.
 */

 #ifndef __LED__H__
#define __LED__H__

#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h> 
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * @brief Turn on a led
 * @param led_id Range from 0 to 3
 */
void led_on(char led_id);

/**
 * @brief Turn of a led
 * @param led_id Range form 0 to 3
 */
void led_off(char led_id);

/**
 * @brief Turn the led on follow the binary format of the input number
 * @param num Input number
 */
void led_num(unsigned char num);

#endif