/*
 * TODO
 * - Perf board (dipmicro.com & radioshack)
 * - Digikey reed switch (WebID 50506821, Access ID 14620)
 *
 * See http://playground.arduino.cc/Learning/arduinoSleepCode
 *
 * Wakes up for 10 seconds, sends HIGH to mp3Pin, and then sleeps 
 * forever, in sleep mode, arduino Pro Mini 5V consumes 0.58mA on a 
 * 9V battery.
 *
 * Uncomment code for interrupt wake up upon pin2 going LOW. Use a
 * pull-up 10K resistor between VCC and pin2. When pin2 goes LOW
 * it activates INT0 external interrupt, bringing the MCU back to life.
 */

#include <EEPROM.h>
#include <avr/sleep.h>

const int addr           = 209;    // EEPROM address to store flag
const int audioDuration  = 10;     // audio duration in seconds

//const int wakePin = 2;           // interrupt pin to wake up arduino
const int mp3Pin         = 4;      // pin that sources power to mp3 player
const int ampShutdownPin = 9;      // TPA2005D1 audio amplifier SDN pin (<0.8V off, >2V on)
const int ledPin         = 13;     // led indicator

void setup()
{
//    Serial.begin(9600);
    //  pinMode(wakePin, INPUT);
    pinMode(mp3Pin, OUTPUT);
    pinMode(ampShutdownPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    //  attachInterrupt(0, wakeUpNow, LOW);
    play();
}

void loop()
{
    sleepNow();
    delay(100);
}

void EEPROMReset()
{
    // Locations that have never been written to have the value of 255
    for (int i = 0; i < 512; i++) {
        EEPROM.write(i, 255);
    }
}

int EEPROMCheck()
{
    bool shouldPlay = false;
    
    int val = EEPROM.read(addr);
//    Serial.print("val: ");
//    Serial.println(val);
    
    // start counter if addr has never been written
    if (val >= 255) {
        val == 0;
    }
    
    // play every other time
    if (val % 2 == 0) {
        shouldPlay = true;
    }
    
    EEPROM.write(addr, ++val);
    return shouldPlay;
}

void wakeUpNow()        // here the interrupt is handled after wakeup
{
    // execute code here after wake-up before returning to the loop() function
    // timers and code using timers (serial.print and more...) will not work here.
    // we don't really need to execute any special functions here, since we
    // just want the thing to wake up
}

void play()
{
    if (EEPROMCheck() == false) 
    {
        return;
    }
    
    int count = 0;
    while (count < audioDuration)
    {
        digitalWrite(mp3Pin, HIGH);
        digitalWrite(ampShutdownPin, HIGH);
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
        count++;
//        Serial.print("playing: ");
//        Serial.println(count);
    }
    
    // Entering Sleep mode after 10 seconds
    if (count >= audioDuration)
    {
        digitalWrite(mp3Pin, LOW);
        digitalWrite(ampShutdownPin, LOW);
        digitalWrite(ledPin, LOW);
        // this delay is needed, the sleep function will provoke a Serial error otherwise!!
        delay(100);
    }
}

void sleepNow()
{
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here
    sleep_enable();          // enables the sleep bit in the mcucr register
    // so sleep is possible. just a safety pin
    //    attachInterrupt(0, wakeUpNow, LOW); // use interrupt 0 (pin 2) and run function
    // wakeUpNow when pin 2 gets LOW
    sleep_mode();            // here the device is actually put to sleep!!
    // THE PROGRAM CONTINUES FROM HERE AFTER WAKING UP
    sleep_disable();         // first thing after waking from sleep:
    // disable sleep...
    //    detachInterrupt(0);      // disables interrupt 0 on pin 2 so the
    // wakeUpNow code will not be executed
    // during normal running time.
}

