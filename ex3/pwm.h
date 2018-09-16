/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: pwm.h
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 20:52:35
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 20:56:10
 * @Description: pwm header files.
 */

#ifndef __PWM__H__
#define __PWM__H__

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
 * @brief make a pwm available
 * @param pwm_id can be either 0 or 1
 */
void export_pwms(char pwm_id);

/**
 * @brief Set the period 
 * @param pwm_id can be either 0 or 1
 * @param period Period for pwm 
 */
void set_period(char pwm_id, unsigned long int period);

/**
 * @brief Set the duties 
 * @param pwm_id Can be either 0 or 1
 * @param duty Duty for pwm
 */
void set_duties(char pwm_id, unsigned long int duty);

/**
 * @brief enable a pwm module
 * @param pwm_id Can be either 0 or 1
 */
void start_pwms(char pwm_id);    

/**
 * @brief disable a pwm module
 * @param pwm_id Can be either 0 or 1
 */
void stop_pwms(char pwm_id);

#endif