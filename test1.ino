#include <LiquidCrystal.h>
//#include "IRremote.h"

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int magneticSensor = 8;
int theSound = 9;
int ok;
int ok1;

//int RECV_PIN = 11;
//
//IRrecv irrecv(RECV_PIN);
//
//decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(magneticSensor, INPUT);
  ok = ok1 = 0;
  
//  irrecv.enableIRIn(); // Start the receiver
}

void  playSound(void)
{
  tone(9, 1000, 10);
}

void loop() {
  // put your main code here, to run repeatedly:
//
// irrecv.decode(&results);
// Serial.println(results.value, HEX);
//    irrecv.resume(); // Receive the next value
//  //}
  
  //Serial.println(digitalRead(magneticSensor));
  if (digitalRead(magneticSensor) == 0)
  {
    playSound();
    ok = 1;
  }
  else
  {
    ok = 0;
  }
  if (ok == 0 && ok1 == 1)
  {
    lcd.clear();
    delay(5);
    lcd.print("Happy shitting");
    ok1 = 0;
  }
  if (ok == 1 && ok1 == 0)
  {
    lcd.clear();
    delay(5);
    lcd.print("You shit out.");
    ok1 = 1;
  }
//  delay(500);

}
