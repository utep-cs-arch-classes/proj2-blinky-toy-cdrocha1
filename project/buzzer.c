#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}
void buzzer_state(_Bool S1B, _Bool S2B, _Bool S3B, _Bool S4B){
  if(S1B){
    buzzer_set_period(600);
  }
  if(S2B){
    buzzer_set_period(300);
  }
  if(S3B){
    buzzer_set_period(150);
  }
  if(S4B){
    buzzer_set_period(0);
  }
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

