#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_state(_Bool S1B, _Bool S2B, _Bool S3B, _Bool S4B);

#endif // included
