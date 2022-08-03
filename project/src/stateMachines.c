#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static char state = 0;

void SWone(){
  switch(state){
  case 0:
    red_on = 1;
    green_on = 1;
    led_changed = 1;
    led_update();
    buzzer_set_period(20000);
    state = 1;
    break;
  case 1:
    red_on = 1;
    green_on = 1;
    led_changed = 1;
    led_update();
      buzzer_set_period(10000);
      state = 2;
    break;
  case 2:
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
      buzzer_set_period(0);
      state = 0;
    break;
    }
    SWone();
}

void SWtwo(){
 red_on ^= 1;
 green_on ^= 1;
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




