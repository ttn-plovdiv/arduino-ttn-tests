# arduino-ttn-tests

Arduino + RN2483 test sketch to connect to [The Things Network](https://www.thethingsnetwork.org/)

## Install
`rn2xx3` library is used. You can get it from [github](https://github.com/jpmeijers/RN2483-Arduino-Library).

## Wiring

|arduino|rn2483|cable|
|-------|------|-----|
|3.3v|34|red|
|GND|33|white|
|12|32(reset)|yellow|
|11 (software TX)|7(RX)|blue
|10 (software RX)|6(TX)|green|

![rn2483 pin diagram](https://github.com/ttn-plovdiv/arduino-ttn-tests/blob/master/rn2483_diagram.png)
![arduno - rn2483 wiring](https://github.com/ttn-plovdiv/arduino-ttn-tests/blob/master/arduino_rn2483_wiring.jpg)
