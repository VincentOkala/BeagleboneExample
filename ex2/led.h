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

void led_on(char led_id);
void led_off(char led_id);
void led_num(unsigned char num);

#endif