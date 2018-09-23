/*
 * Copyright (c) 2018 Ngo Van Tuan
 *
 * @Source: adc.c
 * @Author: Ngo Van Tuan
 * @Email: tuanngo0898@gmail.com
 * @Create At: 2018-09-16 20:41:12
 * @Last Modified By: Ngo Van Tuan
 * @Last Modified At: 2018-09-16 20:46:44
 * @Description: adc definition file.
 */

 #include <adc.h>

#define MAX_BUF 150

int readADC(char pin)  
{  
      int fd;                 //file pointer  
      char buf[MAX_BUF];      //file buffer  
      char val[4];            //holds up to 4 digits for ADC value  
      
      //Create the file path by concatenating the ADC pin number to the end of the string  
      //Stores the file path name string into "buf"  
      snprintf(buf, sizeof(buf), "/sys/bus/iio/devices/iio:device0/in_voltage%d_raw", pin);     //Concatenate ADC file name  

      fd = open(buf, O_RDONLY);     //open ADC as read only  
      
      //Will trigger if the ADC is not enabled  
      if (fd < 0) {  
           perror("ADC - problem opening ADC");  
      }//end if  
      
      read(fd, &val, 4);      //read ADC ing val
      close(fd);              //close file and stop reading  
      
      return atoi(val);     //returns an integer value (rather than ascii)  
 }
