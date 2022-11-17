// Copyright (c) 2022 Tobias Himmler
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT



//Bluetooth
#define BT_DEVICES_COUNT             5

//Serial
#define SERIAL_BMS_DEVICES_COUNT     3


//i2c
#define I2C_DEV_ADDR    0x55
#define I2C_PIN_SDA        4
#define I2C_PIN_SCL        2


#define RXBUFF_OFFSET                     0x04

#define BMS_DATA                          0x01  //BMS-Daten
#define INVERTER_DATA                     0x02  //Inverter-Daten
#define BSC_DATA                          0x03  //

//BMSDATA 0x01
#define BMS_CELL_VOLTAGE                  0x01  
#define BMS_TOTAL_VOLTAGE                 0x02
#define BMS_MAX_CELL_DIFFERENCE_VOLTAGE   0x03
#define BMS_AVG_VOLTAGE                   0x04
#define BMS_TOTAL_CURRENT                 0x05
#define BMS_MAX_CELL_VOLTAGE              0x06
#define BMS_MIN_CELL_VOLTAGE              0x07
#define BMS_MAX_VOLTAGE_CELL_NUMBER       0x08
#define BMS_MIN_VOLTAGE_CELL_NUMBER       0x09
#define BMS_IS_BALANCING_ACTIVE           0x0A
#define BMS_BALANCING_CURRENT             0x0B
#define BMS_TEMPERATURE                   0x0C
#define BMS_CHARGE_PERCENT                0x0D
#define BMS_ERRORS                        0x0E

//INVERTER_DATA 0x02
#define INVERTER_VOLTAGE                  0x01 
#define INVERTER_CURRENT                  0x02 
#define INVERTER_SOC                      0x03 
#define INVERTER_CHARGE_CURRENT           0x04 
#define INVERTER_DISCHARG_CURRENT         0x05 

//BSC_DATA 0x03
#define BSC_ALARMS                        0x01 
#define BSC_IP_ADDR                       0x02