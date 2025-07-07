#include <Wire.h> 
#include <CapacitiveSensor.h> 
#include <LiquidCrystal_I2C.h> 

//Provided by Burak Akazawa

LiquidCrystal_I2C lcd(0x27, 16, 2); 
 
CapacitiveSensor note1 = CapacitiveSensor(4,2); //do 
CapacitiveSensor note2 = CapacitiveSensor(4,3); //re 
CapacitiveSensor note3 = CapacitiveSensor(4,5); //mi 
CapacitiveSensor note4 = CapacitiveSensor(4,6); //fa 
CapacitiveSensor note5 = CapacitiveSensor(4,7); //sol 
CapacitiveSensor note6 = CapacitiveSensor(4,8); //la 
CapacitiveSensor note7 = CapacitiveSensor(4,9); //si 
CapacitiveSensor note8 = CapacitiveSensor(4,10); //do 
void setup() { 
Serial.begin(9600); 
 
lcd.init(); 
lcd.backlight(); 
lcd.clear(); 
} 
 
void loop() { 
  long val_do = note1.capacitiveSensor(30); 
  long val_re = note2.capacitiveSensor(30); 
  long val_mi = note3.capacitiveSensor(30); 
  long val_fa = note4.capacitiveSensor(30); 
  long val_sol = note5.capacitiveSensor(30); 
  long val_la = note6.capacitiveSensor(30); 
  long val_si = note7.capacitiveSensor(30); 
  long val_do2 = note8.capacitiveSensor(30); 
 
  if (val_do>999) { tone(12, 131); 
  displayNote("       Do"); 
    lcd.setCursor(0, 0); 
    lcd.print("  Current Note"); } else 
  if (val_re>999) { tone(12, 147); 
  displayNote("       Re"); 
    lcd.setCursor(0, 0); 
    lcd.print("  Current Note"); } else 
  if (val_mi>999) { tone(12, 165); 
  displayNote("       Mi"); 
    lcd.setCursor(0, 0); 
    lcd.print("  Current Note"); } else 
  if (val_fa>999) { tone(12, 175); 
  displayNote("       Fa"); 
    lcd.setCursor(0, 0); 
    lcd.print("  Current Note"); } else 
  if (val_sol>999) { tone(12, 196); 
  displayNote("       Sol"); 
    lcd.setCursor(0, 0); 
    lcd.print("  Current Note"); } else 
  if (val_la>999) { tone(12, 220); 
  displayNote("       La"); 
    lcd.setCursor(0, 0); 
    lcd.print("  Current Note"); } else 
  if (val_si>999) { tone(12, 247); 
  displayNote("       Si"); 
    lcd.setCursor(0, 0); 
    lcd.print("  Current Note"); } else 
  if (val_do2>999) { tone(12, 262); 
  displayNote("       Do"); 
    lcd.setCursor(0, 0); 
    lcd.print("  Current Note"); } else { noTone(12); } 
} 
void displayNote(String note) { 
  lcd.clear(); 
  lcd.setCursor(0, 1); 
  lcd.print(note); 
}