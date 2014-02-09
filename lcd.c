#include <stdio.h>
#include "jhd_162A.h"
#include <string.h>
#include <stdlib.h>

#define MAX_CMD 100

void pins_init(char * pin_conf[], int size)
{
     int i = 0;
     static char cmd[MAX_CMD];
     static char buf[10];
     char * c; char * tmp;
     for( i = 0 ; i < size ; i++) {
	  strncpy(buf, pin_conf[i], 10);
	  c = strtok(buf, "_");
	  if(c != NULL) {
	       tmp = strtok(NULL, "_");
	       sprintf(cmd, "echo %s > /sys/class/gpio/export", tmp);

#ifdef BEAGLEBONE
	       system(cmd);
#endif
	  }
#ifdef DEBUG
	  printf("\n %s", cmd);
#endif
	  /* reset cmd */
	  strncpy(cmd, " ", MAX_CMD);
	  /* Initialize output direction on the pins */
	  sprintf(cmd,"echo out > /sys/class/gpio/gpio%s/direction",tmp);
#ifdef BEAGLEBONE
	  system(cmd);
#endif
     }
}

int jhd_162A_init()
{
     /* int delay=0; */
     /* int nbr_selectedPins=6; */
     /* unsigned int data_to_write; */

/* The order is  MSB -> LSB */
     char * d_gpio[8] = {"GPIO_77", "GPIO_76", "GPIO_75", "GPIO_74", "GPIO_73", "GPIO_72", "GPIO_71", "GPIO_70"};
     char * ctrl_gpio[3] = {"GPIO_66", "GPIO_67", "GPIO_68"};

     pins_init(&ctrl_gpio, 3);
     pins_init(&d_gpio, 8);
     /* pinMode_multiple(enabled_gpio,selectedPins,nbr_selectedPins,"out"); */

     /* //E RS DB4 DB5 DB6 DB7 = 001100 (2) = 12 (10) */
     /* data_to_write=12;     */
     /* digitalWrite_multiple(enabled_gpio,6,data_to_write);   */
     /* pulsePin(enabled_gpio,data_to_write,6,5,delay); */
     /* delayms(delay); */

     /* //E RS DB4 DB5 DB6 DB7 = 000100 (2) = 4 (10) : 4 bit mode */
     /* data_to_write=4;  */
     /* digitalWrite_multiple(enabled_gpio,6,data_to_write);   */
     /* pulsePin(enabled_gpio,data_to_write,6,5,delay); */
     /* delayms(delay); */

     /* //enable display part 1 - Display ON/OFF & Cursor */
     /* //E RS DB4 DB5 DB6 DB7 = 000000 (2) = 0 (10) */
     /* data_to_write=0;  */
     /* digitalWrite_multiple(enabled_gpio,6,data_to_write);   */
     /* pulsePin(enabled_gpio,data_to_write,6,5,delay); */
     /* delayms(delay); */

     /* //enable display part 2 - Display ON/OFF & Cursor */
     /* //E RS DB4 DB5 DB6 DB7 = 000011 (2) = 3 (10) */
     /* data_to_write=3;  */
     /* digitalWrite_multiple(enabled_gpio,6,data_to_write);   */
     /* pulsePin(enabled_gpio,data_to_write,6,5,delay); */
     /* delayms(delay); */
  	
     /* //two line mode 5x7 part 1  */
     /* //E RS DB4 DB5 DB6 DB7 = 000100 (2) = 4 (10) */
     /* data_to_write=4;  */
     /* digitalWrite_multiple(enabled_gpio,6,data_to_write);   */
     /* pulsePin(enabled_gpio,data_to_write,6,5,delay); */
     /* delayms(delay); */

     /* //two line mode 5x7 part 2 (the 0 next to the 1 specifies the 5x7) */
     /* //E RS DB4 DB5 DB6 DB7 = 000001 (2) = 1 (10) */
     /* data_to_write=1;  */
     /* digitalWrite_multiple(enabled_gpio,6,data_to_write);   */
     /* pulsePin(enabled_gpio,data_to_write,6,5,delay); */
     /* delayms(delay); */
     return 0;
}

int main()
{
     jhd_162A_init();
     return 0;
}
