#include "buzzer.h"

unsigned long temp_buzzer = 0;

void millis_buzzer(void)
{
    if ((millis() - temp_buzzer) >= 1000)
    {
        BUZZER_TOGGLE();
        temp_buzzer = millis();
    }
}