# Statusdisplay für den Battery safety controller (BSC) 
![Picture_BSC_Display_Home](https://github.com/shining-man/bsc_display/blob/main/img/Disp_Home.jpg?raw=true)<br>

Das Display zeigt den Status des Battery safety controllers (BSC).<br>
Als Display wird ein WT32-SC01 genutzt. Voraussetzung für das Display ist ein Softwarestand vom BSC >= V0.2.0.

* Daten von den verbundenen BMSen (5x Bluetooth, 3x Serial)
  * Spannung, Strom, SoC
  * Zellspannungen
  * Balancer ein/aus, Fehler
* Wechselrichterdaten (CAN)
  * Spannung, Strom, SoC
  * Max. Lade/Entlade Strom
* Status der Alarme vom BSC

## Verbinden des Displays mit dem BSC
Verbunden wird das Display über den I2C-Bus mit dem BSC.<br>
Der I2C-Bus ist je nach PCB Version des BSC auf folgenden Steckern zu finden:<br>
PCB V1.0: X1<br>
PCB >= V2.0: Extension-Port J11 (2x5 pol. Pfostenleiste)<br>
<br>
Am Display ist der I2C-Bus auf folgenden GPIOs:<br>
SDA: GPIO32<br>
SCL: GPIO33<br>
<br>
![Picture_BSC_Display_BMS](https://github.com/shining-man/bsc_display/blob/main/img/Disp_BMS.jpg?raw=true)
![Picture_BSC_Display_Cellspgannungen](https://github.com/shining-man/bsc_display/blob/main/img/Disp_Cell.jpg?raw=true)
