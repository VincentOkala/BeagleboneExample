/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: adc.h
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 20:46:08
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 20:47:24
 * @Description: ADC header file.
 */

#ifndef __ADC__H__
#define __ADC__H__

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
 * @brief Read ADC value from a pin 
 * @param pin Pin number, range from 0 to 6
 * @return ADC value, range from 0 to 4096
 */
int readADC(char pin);

#endif
