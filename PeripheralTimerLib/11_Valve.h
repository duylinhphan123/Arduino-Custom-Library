/*
  TODO:Thư viện cho Valve

  Người viết: Nguyễn Trung Thảo

*/


#ifndef _Valve_H_
#define _Valve_H_

// #if defined(KING_INCU_BOARD) || defined(KING_INCU_CO2_BOARD) || defined(KING_SHAK_INCU_BOARD) || defined(KING_SHAK_INCU_PLATE_BOARD)

#include "esp_timer.h"


#define PIN_Valve_1 13
#define PIN_Valve_2 (void *)0  // not use
#define PIN_Valve_3 26
#define PIN_Valve_4 (void *)0  // not use

#define AC_CROSS 36

class Valve {
public:
  Valve();
  void init();
  void Setduration(uint32_t duration);
  
  void _Delay_Callback(void* pvParameter);
  void ValveTrigger();
  uint32_t GetDuration();
  unsigned long int counter;
  

protected:
  uint32_t duration;
  esp_timer_handle_t tValveHandle;
};
extern Valve _Valve;
#endif 
// _Valve_H_
