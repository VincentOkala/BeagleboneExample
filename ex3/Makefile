PROJECT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

CROSS_COMPLIER = arm-linux-gnueabihf-
#CROSS_COMPLIER = 
BUID_DIR = $(PROJECT_DIR)/build
INCLUDE_DIR = $(PROJECT_DIR)

CC = $(CROSS_COMPLIER)gcc

all: $(BUID_DIR)/main.o $(BUID_DIR)/serialib.o $(BUID_DIR)/pwm.o $(BUID_DIR)/led.o $(BUID_DIR)/adc.o
	$(CC) $(BUID_DIR)/*.o -o $(BUID_DIR)/main

$(BUID_DIR)/main.o: main.c | $(BUID_DIR)
	$(CC) -I $(INCLUDE_DIR) -c main.c -o $(BUID_DIR)/main.o

$(BUID_DIR)/serialib.o:  serialib.c | $(BUID_DIR)
	$(CC) -I $(INCLUDE_DIR) -c serialib.c -o $(BUID_DIR)/serialib.o

$(BUID_DIR)/pwm.o:  pwm.c | $(BUID_DIR)
	$(CC) -I $(INCLUDE_DIR) -c pwm.c -o $(BUID_DIR)/pwm.o

$(BUID_DIR)/led.o: led.c | $(BUID_DIR)
	$(CC) -I $(INCLUDE_DIR) -c led.c -o $(BUID_DIR)/led.o

$(BUID_DIR)/adc.o: adc.c | $(BUID_DIR)
	$(CC) -I $(INCLUDE_DIR) -c adc.c -o $(BUID_DIR)/adc.o

$(BUID_DIR):
	mkdir $(BUID_DIR)