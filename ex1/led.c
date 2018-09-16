/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: led.c
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 20:50:13
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 20:50:13
 * @Description: Led definition file.
 */

#include <led.h>

#define MAX_BUF 100

 void led_on(char led_id){
 	int fd, len;
 	char buf[MAX_BUF]; 

 	snprintf(buf, sizeof(buf), "/sys/class/leds/beaglebone:green:usr%d/brightness", led_id);
 	fd = open(buf, O_WRONLY);
 	if (fd < 0) {
 		perror("led error");
 		return;
 	}

	len = snprintf(buf, sizeof(buf), "%d", 1);
	write(fd, buf, len);
	close(fd);
} 

void led_off(char led_id){
	int fd, len;
	
	char buf[MAX_BUF]; 
	
	snprintf(buf, sizeof(buf), "/sys/class/leds/beaglebone:green:usr%d/brightness", led_id);
	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("led error");
		return;
	}

	len = snprintf(buf, sizeof(buf), "%d", 0);
	write(fd, buf, len);
	close(fd); 

	return;
}

void led_num(unsigned char num){
	int i;
	for(i = 0; i < 4; i++){
		if(num & (0x01 << i)){
			led_on(i);
		}
		else{
			led_off(i);
		}
	}
}
