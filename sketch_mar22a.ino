#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
 
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("IRRIGATION");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM IS ON ");
  lcd.print("");
  delay(3000);
  lcd.clear();
}
 
void loop() {
  int value = analogRead(A1);
  Serial.println(value);
  if (value > 950) {
    digitalWrite(2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Water Pump: ON ");
  } else {
    digitalWrite(2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Water Pump: OFF");
  }
 
  if (value < 300) {
    lcd.setCursor(0, 1);
    lcd.print("Analog value:");
    lcd.print(value);
  
  } else if (value > 950) {
    lcd.setCursor(0, 1);
    lcd.print("Analog value:");
    lcd.print(value);
  }
}