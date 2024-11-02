// Copyright (c) 2022 Tobias Himmler
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "i2c.h"
#include "defines.h"
#include "Arduino.h"
#include "data.h"
#include "display.h"
#include "Wire.h"


void onReceive(int len);
void processRxData();

TwoWire I2C = TwoWire(0);

static struct data_s *lData;
uint8_t i2cRxBuf[128];
uint8_t u8_mI2cRxBufLen;
bool newDisplayData;

void initI2C()
{
  newDisplayData=false;
  lData=getData();

  I2C.onReceive(onReceive);
  //I2C.onRequest(onRequest);
  Serial.println(I2C.begin((uint8_t)I2C_DEV_ADDR,32,33,1000000));
}


/*void onRequest()
{
  I2C.print(i++);
  I2C.print(" Packets.");
  Serial.println("onRequest");
}*/


void IRAM_ATTR onReceive(int len)
{
  u8_mI2cRxBufLen=0;

  while(I2C.available()){
    i2cRxBuf[u8_mI2cRxBufLen]=I2C.read();
    u8_mI2cRxBufLen++;
  }

  processRxData();
}

void IRAM_ATTR processRxData()
{
  if(u8_mI2cRxBufLen<4) return;

  uint8_t u8_lData0 = i2cRxBuf[0];
  uint8_t u8_lData1 = i2cRxBuf[1];
  uint8_t u8_lBmsNr=0;

  switch (u8_lData0)
  {
    case BMS_DATA:
      u8_lBmsNr=i2cRxBuf[2];
      switch (u8_lData1)
      {
        case BMS_CELL_VOLTAGE:
          memcpy(&lData->bmsCellVoltage[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 48);
          break;

        case BMS_TOTAL_VOLTAGE:
          memcpy(&lData->bmsTotalVoltage[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 2);
          break;

        case BMS_MAX_CELL_DIFFERENCE_VOLTAGE:
          memcpy(&lData->bmsMaxCellDifferenceVoltage[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 2);
          break;

        case BMS_AVG_VOLTAGE:
          memcpy(&lData->bmsAvgVoltage[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 2);
          break;

        case BMS_TOTAL_CURRENT:
          memcpy(&lData->bmsTotalCurrent[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 2);
          break;

        case BMS_MAX_CELL_VOLTAGE:
          memcpy(&lData->bmsMaxCellVoltage[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 2);
          break;

        case BMS_MIN_CELL_VOLTAGE:
          memcpy(&lData->bmsMinCellVoltage[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 2);
          break;

        case BMS_MAX_VOLTAGE_CELL_NUMBER:
          memcpy(&lData->bmsMaxVoltageCellNumber[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 1);
          break;

        case BMS_MIN_VOLTAGE_CELL_NUMBER:
          memcpy(&lData->bmsMinVoltageCellNumber[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 1);
          break;

        case BMS_IS_BALANCING_ACTIVE:
          memcpy(&lData->bmsIsBalancingActive[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 1);
          break;

        case BMS_BALANCING_CURRENT:
          memcpy(&lData->bmsBalancingCurrent[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 2);
          break;

        case BMS_TEMPERATURE:
          memcpy(&lData->bmsTempature[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 6);
          break;

        case BMS_CHARGE_PERCENT:
          memcpy(&lData->bmsChargePercentage[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 1);
          break;

        case BMS_ERRORS:
          memcpy(&lData->bmsErrors[u8_lBmsNr], &i2cRxBuf[RXBUFF_OFFSET], 4);
          break;

        default:
          break;
      }
      break;

    case INVERTER_DATA:
      switch (u8_lData1)
        {
          case INVERTER_VOLTAGE:
            memcpy(&lData->inverterVoltage, &i2cRxBuf[RXBUFF_OFFSET], 2);
            break;
          case INVERTER_CURRENT:
            memcpy(&lData->inverterCurrent, &i2cRxBuf[RXBUFF_OFFSET], 2);
            break;
          case INVERTER_SOC:
            memcpy(&lData->inverterSoc, &i2cRxBuf[RXBUFF_OFFSET], 2);
            break;
          case INVERTER_CHARGE_CURRENT:
            memcpy(&lData->inverterChargeCurrent, &i2cRxBuf[RXBUFF_OFFSET], 2);
            break;
          case INVERTER_DISCHARG_CURRENT:
            memcpy(&lData->inverterDischargeCurrent, &i2cRxBuf[RXBUFF_OFFSET], 2);
            break;
        }
        break;

    case BSC_DATA:
      switch (u8_lData1)
        {
          case BSC_ALARMS:
            memcpy(&lData->bscAlarms, &i2cRxBuf[RXBUFF_OFFSET], 2);
            break;

          case BSC_IP_ADDR:
            memcpy(&lData->bscIpAdr, &i2cRxBuf[RXBUFF_OFFSET], 16);
            break;
            
          case BSC_RELAIS:
            memcpy(&lData->bscRelais, &i2cRxBuf[RXBUFF_OFFSET], 1);
            break;

          case BSC_DISPLAY_TIMEOUT:
            memcpy(&lData->displayTimeout, &i2cRxBuf[RXBUFF_OFFSET], 1);
            newDisplayData=true; //Immer das letzte empfangene Element meldet "newDisplayData"
            break;
        }
        break;

    default:
      break;
  }

}

bool hasNewDisplayData()
{
  return newDisplayData;
}

