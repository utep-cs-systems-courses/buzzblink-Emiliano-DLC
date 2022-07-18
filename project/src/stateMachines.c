#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }			/* always changes an led */
}

void toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
}

//Buzz
void SWone(){


}

void SWtwo(){

}

void SWtree(){

}

void SWfour(){

}


void state_advance(c)		/* alternate between toggling red & green */
{
  switch (c){
    case 0:
    SWone();
    break;
    case 1:
    SWtwo();
    break;
    case 2:
    SWtree();
    break;
    case 3:
    SWfour();
    break;
  }
  {
  case /* constant-expression */:
    /* code */
    break;
  
  default:
    break;
  }
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}



