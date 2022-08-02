#include <msp430.h>
//#include <time.h>
//#include "led.h"
//#include "buzzer.h"
//#include "switches.h"
#include "stateMachines.h"
#include "state_advance.h"

void state_advance(switchSM)		/* alternate between toggling red & green */
{
  switch (switchSM){
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
}
