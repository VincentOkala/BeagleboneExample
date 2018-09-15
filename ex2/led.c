#include <led.h>

#define MAX_BUF 100

/* *************** SET PERIOD ********************* */ 
 void led_on(char led_id){
 	int fd, len;
 	char buf[MAX_BUF]; 

 	snprintf(buf, sizeof(buf), "/sys/class/leds/beaglebone:green:usr%d/brightness", led_id);
 	fd = open(buf, O_WRONLY);
 	if (fd < 0) {
 		perror("led error");
 		return;
 	}

	len = snprintf(buf, sizeof(buf), "%d", 1); //20ms period for servo
	write(fd, buf, len);
	close(fd);
} 

/* ****************SETTING DUTIES******************  */
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
