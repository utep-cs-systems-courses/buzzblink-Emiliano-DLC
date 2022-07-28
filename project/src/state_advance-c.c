#include <msp430.h>
#include <time.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachines.h"
#include "state_advance.h"

void state_advance(switchSM)		/* alternate between toggling red & green */
{
  switch (switchSM){
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
