#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "buzzer.h"

static char count_state = 0;

char toggle_red()/* always toggle! */

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

  }

  return 1;/* always changes an led */

}



char toggle_green()/* always on or off*/

{

  static char state = 0;

  switch(state){
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }
  return 1;   //always changes an led

}


void toggle_green_25(){
  static char state = 0;
  switch(state){
  case 0:
    green_on = 0;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 2;
    break;
  case 2:
    green_on = 1;
    state = 3;
    break;
  case 3:
    green_on = 0;
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}



void state_advance()/* alternate between toggling red & green */

{

  char changed = 0;



  static enum {R=0, G=1} color = G;

  switch (color) {

  case R: changed = toggle_red(); color = G; break;

  case G: changed = toggle_green(); color = R; break;

  }



  led_changed = changed;

  led_update();

}

void count_to_three(){
  static char state = 0;
  switch(state){
  case 0:
    red_on = 0;
    green_on = 0;
    buzzer_set_period(350-20);
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    state = 2;
    buzzer_set_period(300-6);
    break;
  case 2:
    red_on = 1;
    green_on = 0;
    state = 3;
    buzzer_set_period(280-18);
    break;
  case 3:
    red_on = 1;
    green_on = 1;
    buzzer_set_period(300-6);
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}
