#ifndef switches_included
#define switches_included

//P2DIR
//define buttons on external board (p2)
#define SW1 BIT0 //p2.0
#define SW2 BIT1 //p2.1
#define SW3 BIT2 //p2.2
#define SW4 BIT3 //p2.3
#define SWITCHES (SW1 | SW2 | SW3 | SW4) //Switches for external board (p2)

//P1DIR
//#define SW0 BIT4		/* switch1 is p1.3 */
//#define P1SWITCHES(SW0)		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

//variables (Not needed)
//extern char switch_state_down, switch_state_changed; /* effectively boolean */


extern char switch_state_changed;

//extern char switchSM;


#endif // included
