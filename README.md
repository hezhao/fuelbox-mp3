Fuelbox MP3
===========
* v1v2: An mp3 player controller board with LM386 op-amp, using touch sensor, push button and light sensor as trigger.
* v3: An mp3 player + Arduino + PAM8403 amp all-in-one triggered only by SPST-NC reed switch (SPDT will do too, just choose NC pair). Once triggered, Arduino checks the EEPROM flag, plays the audio once, and sleeps forever.

Power Consumption
=================
* Arduino Pro Mini 5V + MP3 module + PAM8403 amp = 45mA @ 7.4v
* Arduino Pro Mini 5V = 15mA @ 5V
* MP3 module = 85mA @ 3.7v
* Sleep Mode: Arduino Pro Mini 5V = 0.58mA @ 9V
* 2032 Battery max discharge= = 10mA @ 3V

Notes
=====
* When using LiPo battery, there is a large inrust current. A 30Ω current limiting resistor is placed in serial with reed switch
* R = U / Switching Current = 7.4V / 0.25A = 29.6Ω, for absolute safety, use R = 8.2 / 0.25A = 32.8Ω since fully charged LiPo battery can reach 4.2V

TODO
====
* v2: TOUCH sensor is not supposed to be grounded (GND plane may cause problem)
* v2: Remove vias that connect to TOUCH sensor
