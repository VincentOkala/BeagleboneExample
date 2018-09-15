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

int readADC(char pin);

#endif
