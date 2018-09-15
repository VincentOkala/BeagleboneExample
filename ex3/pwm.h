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

void export_pwms(char pwm_id);
void set_period(char pwm_id, unsigned long int period);
void set_duties(char pwm_id, unsigned long int duty);
void start_pwms(char pwm_id);     
void stop_pwms(char pwm_id);

#endif