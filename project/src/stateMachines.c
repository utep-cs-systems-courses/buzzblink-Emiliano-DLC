#include <msp430.h>
#include <time.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void toggle_red()		/* always toggle! */
{
  static char state = 0;

  /*switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }			/* always changes an led */

  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void toggle_green()	/* only toggle green if red is on!  */
{
  /*char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }*/
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
  red_on = 1;
  green_on = 1;
  led_changed = 1;
  led_update();
}


//Buzz
void SWone(){
  toggle_red();

}

void SWtwo(){
  int i = 0;
  int something[] = {1,2,3,4,4,3,2,1,3,4,2,1,2,3};
  for(i < 0; i < sizeof(something); i++){
   if(something[i] == 1){toggle_red();}
   if(something[i] == 2){toggle_green();}
   if(something[i] == 3){turnOff();}
   if(something[i] == 4){turnOn();}
   turnOn();
  }

}

void SWtree(){
  buzzer_set_period(1000);
}

void SWfour(){
  turnOff();
  buzzer_set_period(0);
}


void state_advance(c)		/* alternate between toggling red & green */
{
  switch (c){
    case 1:
    SWone();
    break;

    case 2:
    SWtwo();
    break;

    case 3:
    SWtree();
    break;

    case 4:
    SWfour();
    break;
  }
}



