// Copyright (c) 2022 Tobias Himmler
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Arduino.h"
#include "i2c.h"
#include "display.h"

bool firstRun=true;

TaskHandle_t task_handle_i2c = NULL;
TaskHandle_t task_handle_display = NULL;


void task_i2c(void *param)
{
  // init i2c
  initI2C();

  for (;;)
  {
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}


void task_display(void *param)
{
  // init Display
  displayInit();

  for (;;)
  {
    vTaskDelay(pdMS_TO_TICKS(5));
    displayNewBscData();

    displayRunCyclic();
  }
}


void setup(void)
{
  Serial.begin(115200);

  // init Tasks
  xTaskCreate(task_display, "display", 30000, nullptr, 5, &task_handle_display);
  xTaskCreate(task_i2c, "i2c", 3000, nullptr, 4, &task_handle_i2c);
}


void loop()
{
  ;
}
