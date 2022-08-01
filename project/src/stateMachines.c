#include <msp430.h>
#include <time.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void SWone(){
  red_on = 1;
  green_on = 1;
  led_changed = 1;
  led_update();
  buzzer_set_period(5000);
}

void SWtwo(){
 red_on = 0;
 green_on = 1;
 led_changed = 1;
 led_update();
}

void SWtree(){
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
  buzzer_set_period(2500);
}

void SWfour(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
  buzzer_set_period(0);
}




