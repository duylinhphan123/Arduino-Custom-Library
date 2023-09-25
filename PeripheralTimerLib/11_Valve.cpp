#include "11_Valve.h"
#include <Arduino.h>
#include "esp_timer.h"
// #if defined(KING_INCU_BOARD) || defined(KING_INCU_CO2_BOARD) || defined(KING_SHAK_INCU_BOARD) || defined(KING_SHAK_INCU_PLATE_BOARD)
#define _VALVE_PIN_1 13
#define _VALVE_PIN_2 26


void Delay_Callback(void* pvParameter);
Valve::Valve()
{
    duration = 2000;
}
void Valve::init()
{
    
    pinMode(_VALVE_PIN_1, OUTPUT);
    pinMode(_VALVE_PIN_2, OUTPUT);
    digitalWrite(_VALVE_PIN_1, LOW);
    digitalWrite(_VALVE_PIN_2, LOW);

    esp_timer_create_args_t timer_arg = {
    .callback = Delay_Callback,
    .dispatch_method = ESP_TIMER_TASK,
    .name = "TimerValve",
    .skip_unhandled_events = 1,
  };
  esp_timer_create(&timer_arg, &tValveHandle);
  esp_timer_stop(tValveHandle);
}
 


void Valve::_Delay_Callback(void* pvParameter)
{
      digitalWrite(_VALVE_PIN_1, LOW);
      digitalWrite(_VALVE_PIN_2, LOW);
}
void Valve::ValveTrigger() {
    digitalWrite(_VALVE_PIN_1, HIGH);
    digitalWrite(_VALVE_PIN_2, HIGH);
    esp_timer_start_once(tValveHandle, GetDuration());
}
uint32_t Valve::GetDuration() {
  return duration;
}

void Valve::Setduration(uint32_t time) {
  if (time < 0) {
    time = 0;  
  }
  duration = time;
}
void Delay_Callback(void* pvParameter) {
  _Valve._Delay_Callback(pvParameter);
}
