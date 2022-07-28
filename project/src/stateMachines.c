#include <msp430.h>
#include <time.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void toggle_red()		/* always toggle! */
{
  static char state = 0;
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void toggle_green()	/* only toggle green if red is on!  */
{
  red_on = 0;
  green_on = 1;
  led_changed = 1;
  led_update();
}

void turnOff(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void turnOn(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
  buzzer_set_period(0);
}


void SWone(){
  red_on = 1;
  green_on = 1;
  led_changed = 1;
  led_update();
  buzzer_set_period(5000);

}

void SWtwo(){
 red_on ^= 1;
 green_on ^= 1;
 led_changed = 1;
 led_update();
}

void SWtree(){
  buzzer_set_period(1000);
}

void SWfour(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
  buzzer_set_period(0);
}




