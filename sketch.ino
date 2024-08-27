// Now turn this trash into treasure!
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const float BETA = 3950;
int temperature = 0;
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  //Serial1.println("Hello, Raspberry Pi Pico W!");
  lcd.begin(16, 2);
  lcd.println("Detecting");
  lcd.setCursor(0, 2);
  lcd.println("temperature...");
  delay(1500);
}
void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  //Serial1.println(celsius);
  if (temperature != celsius) {
    temperature = celsius;
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print(temperature);
    lcd.print(" degrees");
  }
  delay(3000); // this speeds up the simulation
}