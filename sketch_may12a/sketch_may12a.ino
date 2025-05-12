#include "pitches.h"
#include "melodies.h"
#include "PiezoLedManager.h"
#include <LiquidCrystal.h>

const int RS = 9, E = 8, D4 = 6, D5 = 5, D6 = 4, D7 = 3;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup()
{
  // led pin
  pinMode(12, OUTPUT);
  
    // lcd screen
  lcd.clear();
  lcd.begin(20, 4);
}

void loop()
{ 
  const int currentMillis = millis();

  // check if PIEZO and LED needs an update
  piezoLed.updateState(currentMillis);
  
// update lcd screen text
  lcd.setCursor(0, 1);
  lcd.print("I");
  
  lcd.setCursor(2, 1);
  lcd.print("AM...");

  lcd.setCursor(8, 2);
  lcd.print("IRON");

  lcd.setCursor(13, 2);
  lcd.print("MANNNN");
};
