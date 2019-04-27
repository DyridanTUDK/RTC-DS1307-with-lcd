#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
void setup() {
 while (!Serial);

 Serial.begin(57600);
 if (!rtc.begin()){
    Serial.println("no RTC");
    while(1);
 }
 if (! rtc.isrunning()){
  Serial.println("RTC no run");
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  rtc.adjust(DateTime(2019, 4, 26, 23, 32, 00));
 }
 lcd.begin(16,2);
 }
    

void loop() {
  DateTime now = rtc.now();
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(" (");
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    delay(3000); //Print date and time every 3 sec
    lcd.setCursor(0, 0);
    lcd.print("Time:-");
    lcd.print(now.hour(), DEC);
    lcd.print(":");
    lcd.print(now.minute(), DEC);
    lcd.print(":");
    lcd.print(now.second(), DEC);

    lcd.setCursor(0,1);
    lcd.print("Date:-");
    lcd.print(now.day(), DEC);
    lcd.print("/");
    lcd.print(now.month(),DEC);
    lcd.print("/");
    lcd.print(now.year(), DEC);
    delay(5000);
    lcd.clear();

}
