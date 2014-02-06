Fuelbox MP3
===========
* v1v2: An mp3 player controller board with LM386 op-amp, using touch sensor, push button and light sensor as trigger.
* v3: An mp3 player + Arduino + TPA2005D1 amp all-in-one triggered only by SPST-NC reed switch (SPDT will do too, just choose NC pair). Once triggered, Arduino checks the EEPROM flag, plays the audio once, and sleeps forever.

![circuit](https://github.com/hezhao/fuelbox-mp3/raw/master/v3/circuit.png)@600
![prototype](https://github.com/hezhao/fuelbox-mp3/raw/master/v3/prototype.png)@600

Power Consumption
=================
* Arduino Pro Mini 5V + MP3 module + TPA2005D1 amp = 50mA @ 7.4V
* Arduino Pro Mini 5V = 15mA @ 5V
* TPA2005D1 = 15mA @ 5V
* Sleep Mode: Arduino Pro Mini 5V = 0.58mA @ 9V
* Sleep Mode: TPA2005D1 = 0.5µA @ 5V (datasheet)
* Limits: 2032 Battery max discharge = 10mA @ 3V
* Limits: Arduino digital pin max output current = 40mA
* Limits: Arduino VCC-GNC max output current = 200mA

Notes
=====
* When using LiPo battery, there is a large inrust current. A 30Ω current limiting resistor is placed in serial with reed switch. However, limiting resistor is not necessary with for TPA2005D1
* <del> R = U / Switching Current = 7.4V / 0.25A = 29.6Ω; For absolute safety, use R = 8.2V / 0.25A = 32.8Ω since fully charged LiPo battery can reach 4.2V </del>
* TPA2005D1 amp produces a short bust sound if triggered by the arduino digital pin, so instead it is directly powered by VCC and digital pin 9 shutsdown amp after audio finishes

TODO
====
* v2: TOUCH sensor is not supposed to be grounded (GND plane may cause problem)
* v2: Remove vias that connect to TOUCH sensor
