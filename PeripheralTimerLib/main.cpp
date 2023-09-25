#include <Arduino.h>
#include "11_Valve.h"

Valve _Valve;
uint32_t time1 = 0;

void setup()
{
  _Valve.init();
  _Valve.Setduration(2000000);
}

void loop()
{
  if(millis() - time1 > 10000)
  {
       _Valve.ValveTrigger();
       time1 = millis();
  }
  
  
}
