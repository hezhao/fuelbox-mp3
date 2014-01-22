fuelbox-mp3
===========
* v1v2: An mp3 player controller board with LM386 op-amp, using touch sensor, push button and light sensor as trigger.
* v3: An mp3 player + Arduino + PAM8403 amp all-in-one triggered only by SPDT reed switch. Once triggered, Arduino checks the EEPROM flag, plays the audio once, and sleeps forever.

POWER CONSUMPTION
=================
* Arduino Pro Mini 5V + MP3 module + PAM8403 amp = 45mA @ 9v
* Arduino Pro Mini 5V = 15mA @ 5V
* MP3 module = 85mA @ 3.7v
* 2032 Battery max discharge= = 10mA @ 3V.

TODO
====
* v2: TOUCH sensor is not supposed to be grounded (GND plane may cause problem)
* v2: Remove vias that connect to TOUCH sensor
