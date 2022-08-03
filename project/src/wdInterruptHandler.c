#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 150) {
    SWone();
    }
    else{
      blink_count = 0;
      }
  }//
}
