#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static char led_state = 0;

void SWone(){
  red_on = 1;
  green_on = 1;
  led_changed = 1;
  led_update();
  buzzer_set_period(5000);
}

void SWtwo(){
 red_on ^= 1;
 led_changed = 1;
 led_update();
}

void SWtree(){
  green_on ^= 1;
  led_changed = 1;
  led_update();
  buzzer_set_period(7500);
}

void SWfour(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
  buzzer_set_period(0);
}




