#include <LiquidCrystal.h>
//#include "IRremote.h"
#include "musical_notes.h"

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int magneticSensor = 8;
int shittyButton = 10;
int theRed = 11;
int theGreen = 13;
int theBlue = 12;
int ok;
int ok1;

int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

int melody2[] = {
  NOTE_C5, NOTE_B4, NOTE_AS4, 0, 0, 0, 0, 0};

int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

int noteDurations2[] = {
  2, 2, 1, 0,0,0,0,0 };

//int RECV_PIN = 11;
//
//IRrecv irrecv(RECV_PIN);
//
//decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(magneticSensor, INPUT);
  pinMode(shittyButton, INPUT);
  pinMode(theRed, OUTPUT);
  pinMode(theGreen, OUTPUT);
  pinMode(theBlue, OUTPUT);
  ok = ok1 = 0;

  digitalWrite(theBlue, 255);
  
//  irrecv.enableIRIn(); // Start the receiver
}

void  playSound(int value)
{
  if (value == 1)
  {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(9, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(9);
  }
  }
  if (value == 2)
  {
  for (int thisNote = 0; thisNote < 3; thisNote++) {
    int noteDuration = 1000/noteDurations2[thisNote];
    tone(9, melody2[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(9);
  }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
//
// irrecv.decode(&results);
// Serial.println(results.value, HEX);
//    irrecv.resume(); // Receive the next value
//  //}
  
  //Serial.println(digitalRead(shittyButton));
  if (digitalRead(magneticSensor) == 0 && digitalRead(shittyButton) == 1)
  {
    
    ok = 1;
  }
  else if (digitalRead(magneticSensor) == 1)
  {
    ok = 0;
  }
  if (ok == 0 && ok1 == 1)
  {
    lcd.clear();
    delay(5);
    lcd.print("Happy shitting");
    digitalWrite(theBlue, 0);
    digitalWrite(theRed, 0);
    digitalWrite(theGreen, 255);
    playSound(1);
    ok1 = 0;
  }
  if (ok == 1 && ok1 == 0)
  {
    lcd.clear();
    delay(5);
    digitalWrite(theBlue, 0);
    digitalWrite(theRed, 255);
    digitalWrite(theGreen, 0);
    lcd.print("You shit out.");
    playSound(2);
    ok1 = 1;
  }
//  delay(500);

}
