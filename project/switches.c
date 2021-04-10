#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed, S1B, S2B, S3B, S4B; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p1val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  buzzer_init();
  //led_update();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  S1B = (p1val & S1) ? 0 : 1; /* 0 when SW1 is up */
  S2B = (p1val & S2) ? 0 : 1;
  S3B = (p1val & S3) ? 0 : 1;
  S4B = (p1val & S4) ? 0 : 1;

  buzzer_state(S1B, S2B, S3B, S4B);
}
