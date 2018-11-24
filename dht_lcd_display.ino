#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
dht DHT;

#define DHT11_PIN 2

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  displayText(1,0,"MATEUSZ BRYL");
  delay(2000);
  lcd.clear();
  displayText(1,0,"TEMP:");
  displayText(1,1,"WILG:");
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(11, 0);
  lcd.print((char)223);
  displayText(12, 0, "C");
  displayText(12, 1, "%");
  displayText(9, 0, String(DHT.temperature, 0));
  displayText(9, 1, String(DHT.humidity, 0));
  delay(500);
}

void displayText(int x, int y, String text)
{
  lcd.setCursor(x, y);
  lcd.print(text);
}
