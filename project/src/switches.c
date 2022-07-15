#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"

//TODO: Change P1 and p1 to P2 and p2 respectively

//Status for each button
//set status to false
char sw1_curr_stat = 0;
char sw2_curr_stat = 0;
char sw3_curr_stat = 0;
char sw4_curr_stat = 0;

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

  //Temporary variables to store the precious state
  sw1_temp = sw1_curr_stat;
  sw2_temp = sw2_curr_stat;
  sw3_temp = sw3_curr_stat;
  sw4_temp = sw4_curr_stat;

  //
  sw1_curr_stat = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  sw2_curr_stat = (p2val & SW2) ? 0 : 1; /* 0 when SW1 is up */
  sw3_curr_stat = (p2val & SW3) ? 0 : 1; /* 0 when SW1 is up */
  sw4_curr_stat = (p2val & SW4) ? 0 : 1; /* 0 when SW1 is up */

  //Reset buttons

  //reset sw1
  if ((sw1_temp != sw1_curr_stat) && sw1_curr_stat)//first parentesis check if there is a change in state
  {                                                //If previous and current are not equal there is a change in the button state                                                   
    sw1_press ^= 1;                               //if condition is true reset the buttons
    sw2_press = 0;
    sw3_press = 0;
    sw4_press = 0;
  }
  // reset sw2
  elif((sw2_temp != sw2curr_stat)  && sw2_curr_stat)
  {
    sw1_press = 0;
    sw2_press = ^= 1;//Reset sw2 using an inverter
    sw3_press = 0;
    sw4_press = 0;
  }
  // reset sw3
  elif((sw3_temp != sw3_curr_stat) && sw2_curr_stat)
  {
    sw1_press = 0;
    sw2_press = 0;
    sw3_press = ^= 1;//Reset sw3 using an inverter
    sw4_press = 0;
  }
  // reset sw4
  elif((sw4_temp != sw4_curr_stat) && sw2_curr_stat)
  {
    sw1_press = 0;
    sw2_press = 0;
    sw3_press = 0;
    sw4_press = ^= 1;//Reset sw4 using an inverter
  }
  led_update();
  
}
