// Copyright (c) 2022 Tobias Himmler
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#ifndef BMSDATA_H
#define BMSDATA_H

#include <Arduino.h>
#include "defines.h"


struct bmsData_s
{
  //                                                                                 // NEEY 4A | JbdBms | JK-BMS | 
  uint16_t   bmsCellVoltage[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT][24];          //    x    |   x    |   x    |
  //float    bmsCellResistance[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT][24];       //    x    |        |        |
  int16_t    bmsTotalVoltage[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];             //    x    |   x    |   x    |
  uint16_t   bmsMaxCellDifferenceVoltage[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT]; //    x    |   x    |   x    |
  uint16_t   bmsAvgVoltage[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];               //    x    |   x    |   x    |
  int16_t    bmsTotalCurrent[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];             //         |   x    |   x    |
  uint16_t   bmsMaxCellVoltage[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];           //    x    |   x    |   x    |
  uint16_t   bmsMinCellVoltage[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];           //    x    |   x    |   x    |
  uint8_t    bmsMaxVoltageCellNumber[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];     //    x    |        |        |
  uint8_t    bmsMinVoltageCellNumber[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];     //    x    |        |        |
  uint8_t    bmsIsBalancingActive[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];        //    x    |        |        |
  int16_t    bmsBalancingCurrent[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];         //    x    |        |        |
  int16_t    bmsTempature[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT][3];             //    2    |   3    |   3    |
  uint8_t    bmsChargePercentage[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];         //         |   x    |   x    |
  uint32_t   bmsErrors[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];                   //    *    |   x    |   x    |
  unsigned long bmsLastDataMillis[BT_DEVICES_COUNT+SERIAL_BMS_DEVICES_COUNT];        //    x    |   x    |   x    |
  //                                                                                 // *=Teilweise
};


struct bmsData_s * getBmsData();


#endif