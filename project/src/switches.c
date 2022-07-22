#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"

//TODO: Change P1 and p1 to P2 and p2 respectively

//Status for each button
//set status to false
/*sw1_curr_stat = 0;
sw2_curr_stat = 0;
sw3_curr_stat = 0;
sw4_curr_stat = 0;*/

//char switch_state_down, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  //switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  //switch_state_changed = 1;
  //led_update();

  //
  char sw1_curr_stat = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  char sw2_curr_stat = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  char sw3_curr_stat = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  char sw4_curr_stat = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */
  
  char switchSM;

  //Reset buttons

  //reset sw1
  if (sw1_curr_stat == 1)                             
   switchSM = 1;
  // reset sw2
  else if(sw2_curr_stat == 1)
    switchSM = 2;
  // reset sw3
  else if(sw3_curr_stat == 1)
    switchSM = 3;
  // reset sw4
  else if(sw4_curr_stat == 1)
    switchSM = 4;
  state_advance(switchSM);
  
}
