/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: serialib.h
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 20:56:48
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 21:12:00
 * @Description: serial header file.
 */

#ifndef _SERIALIB_H
#define _SERIALIB_H

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
 * @brief Define an serial object
 */
typedef struct serial_s {
	speed_t baud;
	char* port;
	int fd;
} serial;

/**
 * @brief 
 * @param s Pointer to a pointer of a serial obect
 * @param port Link to a serial deive ex: "/dev/tty***"
 * @param baud Serial baund rate, can be 9600, 115000,...
 * @return  0 every thing is OK
 * 		   -1 some things go wrong
 */
int serial_open(serial **s, char* port, const unsigned int baud);

/**
 * @brief Read a character from a file
 * @param s Pointer to a serial obect
 * @param p Read character
 * @return  0 every thing is OK
 * 		   -1 some things go wrong
 */
int serial_read_char(serial *s, char *p);

/**
 * @brief Blocking function, it will not return until it receive
 * a number of len character or the end of line character
 * @param s Pointer to a serial obect
 * @param buf Buffer to the a string
 * @param eol End of line ex: '\r'
 * @param len Length of the buffer
 * @return  0 every thing is OK
 * 		   -1 some things go wrong
 */
int serial_read(serial *s, char *buf, char eol, unsigned int len);

/**
 * @brief Send a character via serial port
 * @param s Pointer to a serial obect
 * @param p Sent character
 * @return  0 every thing is OK
 * 		   -1 some things go wrong
 */
int serial_write_char(serial *s, char p);

/**
 * @brief Send a array via serial port
 * @param s Pointer to a serial obect
 * @param str Array to send
 * @return  0 every thing is OK
 * 		   -1 some things go wrong
 */
int serial_write(serial *s, char* str);

#endif
