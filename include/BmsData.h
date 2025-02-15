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
  uint16_t   bmsCellVoltage[DATA_DEVICE_DEVICES_COUNT][24];          //    x    |   x    |   x    |
  //float    bmsCellResistance[DATA_DEVICE_DEVICES_COUNT][24];       //    x    |        |        |
  int16_t    bmsTotalVoltage[DATA_DEVICE_DEVICES_COUNT];             //    x    |   x    |   x    |
  uint16_t   bmsMaxCellDifferenceVoltage[DATA_DEVICE_DEVICES_COUNT]; //    x    |   x    |   x    |
  uint16_t   bmsAvgVoltage[DATA_DEVICE_DEVICES_COUNT];               //    x    |   x    |   x    |
  int16_t    bmsTotalCurrent[DATA_DEVICE_DEVICES_COUNT];             //         |   x    |   x    |
  uint16_t   bmsMaxCellVoltage[DATA_DEVICE_DEVICES_COUNT];           //    x    |   x    |   x    |
  uint16_t   bmsMinCellVoltage[DATA_DEVICE_DEVICES_COUNT];           //    x    |   x    |   x    |
  uint8_t    bmsMaxVoltageCellNumber[DATA_DEVICE_DEVICES_COUNT];     //    x    |        |        |
  uint8_t    bmsMinVoltageCellNumber[DATA_DEVICE_DEVICES_COUNT];     //    x    |        |        |
  uint8_t    bmsIsBalancingActive[DATA_DEVICE_DEVICES_COUNT];        //    x    |        |        |
  int16_t    bmsBalancingCurrent[DATA_DEVICE_DEVICES_COUNT];         //    x    |        |        |
  int16_t    bmsTempature[DATA_DEVICE_DEVICES_COUNT][3];             //    2    |   3    |   3    |
  uint8_t    bmsChargePercentage[DATA_DEVICE_DEVICES_COUNT];         //         |   x    |   x    |
  uint32_t   bmsErrors[DATA_DEVICE_DEVICES_COUNT];                   //    *    |   x    |   x    |
  unsigned long bmsLastDataMillis[DATA_DEVICE_DEVICES_COUNT];        //    x    |   x    |   x    |
  //                                                                                 // *=Teilweise
};


struct bmsData_s * getBmsData();


#endif