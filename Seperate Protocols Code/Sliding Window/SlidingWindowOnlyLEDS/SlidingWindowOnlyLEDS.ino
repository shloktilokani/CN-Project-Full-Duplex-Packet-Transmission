#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(52, 0, NEO_GRB + NEO_KHZ800);  //led declare syntax

int r = 0;
int g = 0;
int b = 0;

LiquidCrystal_I2C lcd(32,16,2);  //lcd declaration
int t=3000;
void setup() 
{
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("Input 1st Number");
  int i, index;
  
  for(i=0;i<=23;i++)
  {
    if(i<=11)
    {
      green();
      pixels.setPixelColor(i, pixels.Color(r,g,b));
      pixels.show();
    }
    if(i>11)
    {
      blue();
      pixels.setPixelColor(i, pixels.Color(r,g,b));
      pixels.show();
    }
    delay(100);
  }
  
  for(i=24;i<=35;i++)
  {
    
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
    
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(100);
  }
  
  for(i=36;i<=43;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
    
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(100);
    
    blue();
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  
  for(i=44;i<=51;i++)
  {
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(100);
    
    red();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
    
    blue();
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
}
for(i=40;i<=43;i++)
  {
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(100);
    
    blue();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  
    red();
    pixels.setPixelColor(i-40, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  
}
 for(i=32;i<=43;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(100);
   
   red(); 
   pixels.setPixelColor(i-28, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
   
 }
  for(i=44;i<=51;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(100);
   
   red(); 
   pixels.setPixelColor(i-28, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
   
 }
  for(i=0;i<=23;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(100);
  }
  delay(100000000000000000);
}  
//--------------------------------------------
void red()
{
  r = random(255);
  g = random(0);
  b = random(0);
}
//--------------------------------------------
void green()
{
  r = random(0);
  g = random(255);
  b = random(0);
}
//--------------------------------------------
void blue()
{
  r = random(0);
  g = random(0);
  b = random(255);
}
