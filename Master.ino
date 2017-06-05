#include<Wire.h>
#include<LiquidCrystal.h>
#define MAXword 40
#define ROW(x) (x / 2)
#define COL(x) (x % 20)

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int t = 0;
int wordn = 0;

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
  lcd.begin(20, 2); 

lcd.cursor();
}

void loop() 
{
   Wire.requestFrom(8, 20);

   while(Wire.available())
   {
    char val = Wire.read();
    Serial.print(val);
       if(32 <= val && val <= 126)
       {
          if(wordn == MAXword)
          {
            wordn = 0;
            lcd.clear();
          }
        lcd.write(val);
        wordn++;
        lcd.setCursor((wordn%20),(wordn/20));
        }
   }

    Serial.println("");
    delay(2000);
}

