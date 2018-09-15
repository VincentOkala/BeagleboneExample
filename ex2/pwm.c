#include <pwm.h>

#define MAX_BUF 100

/* *************** EXPORT PWMS ********************* */ 
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

/* *************** SET PERIOD ********************* */ 
 void set_period(char pwm_id, unsigned long int period){
 	int fd, len;
 	char buf[MAX_BUF]; 

 	snprintf(buf, sizeof(buf), "/sys/class/pwm/pwm-0:%d/period", pwm_id);
 	fd = open(buf, O_WRONLY);
 	if (fd < 0) {
 		perror("pwm/period");
 		return;
 	}

	len = snprintf(buf, sizeof(buf), "%lu", period); //20ms period for servo
	write(fd, buf, len);
	close(fd);
} 

/* ****************SETTING DUTIES******************  */
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

/* *********START the PWMS at the output ******* */
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

/* *******************Stop the PWMS*****************   */       
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