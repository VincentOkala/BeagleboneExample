/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: pwm.c
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 20:52:11
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 21:22:03
 * @Description: pwm definition file.
 */

#include <pwm.h>

#define MAX_BUF 100

void export_pwms(char pwm_id){
	int fd, len;
	char buf[MAX_BUF];

 	fd = open("/sys/class/pwm/pwmchip0/export", O_WRONLY);
 	if (fd < 0) {
 		perror("pwm/export");
 		return;
 	} 

 	len = snprintf(buf, sizeof(buf), "%d", pwm_id);
 	write(fd, buf, len);
 	close(fd);
 } 

 void set_period(char pwm_id, unsigned long int period){
 	int fd, len;
 	char buf[MAX_BUF]; 

	set_duties(pwm_id, 0);

 	snprintf(buf, sizeof(buf), "/sys/class/pwm/pwm-0:%d/period", pwm_id);
 	fd = open(buf, O_WRONLY);
 	if (fd < 0) {
 		perror("pwm/period");
 		return;
 	}

	len = snprintf(buf, sizeof(buf), "%lu", period); 
	write(fd, buf, len);
	close(fd);
} 

void set_duties(char pwm_id, unsigned long int duty){
	int fd, len;
	
	char buf[MAX_BUF]; 
	
	snprintf(buf, sizeof(buf), "/sys/class/pwm/pwm-0:%d/duty_cycle", pwm_id);
	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("pwm0/duty");
		return;
	}

	len = snprintf(buf, sizeof(buf), "%lu", duty);
	write(fd, buf, len);
	close(fd); 

	return;
}

void start_pwms(char pwm_id){
	int fd, len;
	char buf[MAX_BUF];
	snprintf(buf, sizeof(buf), "/sys/class/pwm/pwm-0:%d/enable", pwm_id);
	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("pwm/run");
		return;
	} 
	len = snprintf(buf, sizeof(buf), "%d", 1);
	write(fd, buf, len);
	close(fd);

	return;
}
      
void stop_pwms(char pwm_id){
	int fd, len;
	char buf[MAX_BUF];
	snprintf(buf, sizeof(buf), "/sys/class/pwm/pwm-0:%d/enable", pwm_id);
	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("pwm/run");
		return;
	} 
	len = snprintf(buf, sizeof(buf), "%d", 0);
	write(fd, buf, len);
	close(fd);
	return;
}