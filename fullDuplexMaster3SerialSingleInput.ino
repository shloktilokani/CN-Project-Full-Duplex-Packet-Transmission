#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(52, 2, NEO_GRB + NEO_KHZ800);  //led declare syntax
LiquidCrystal_I2C lcd(0x27,16,2);

int r = 0;
int g = 0;
int b = 0;
int ByteReceived;

void setup() 
{
  Serial.flush();
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  pinMode(2,OUTPUT);
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("Select a");
  lcd.setCursor(0,1);
  lcd.print("Protocol :");
  for(int i=0;i<=100;i++)
  {
    Serial.println(" ");
  }
  Serial.println("List of Protocols :-");
  Serial.println(" 1. For Sliding Window.");
  Serial.println(" 2. For Go-Back-N.");
  Serial.println(" 3. For Selective Repeat.");
  Serial.println("Enter a protocol : ");

  while(Serial.available() == 0){
  }

  int choice=Serial.parseInt();

  if(choice==1)
  {
    Serial.println("slidingWindow()InExecution....");
    lcd.clear();
    pixels.clear();
    slidingWindow();
    lcd.clear();
    Serial.println(" ");
  }

  if(choice==2)
  {
    Serial.println("goBackN()InExecution....");
    lcd.clear();
    pixels.clear();
    goBackN();
    lcd.clear();
    Serial.println(" ");
  }

  if(choice==3)
  {
    Serial.println("selectiveRepeat()InExecution....");
    lcd.clear();
    pixels.clear();
    selectiveRepeat();
    lcd.clear();
    Serial.println(" ");
  }

  else
  {
    Serial.println(" ");
  }

}
//--------------------------------------------
void slidingWindow()
{
  int i,j;
  lcd.setCursor(0,0);
  lcd.print("Sliding");
  lcd.setCursor(0,1);
  lcd.print("Window");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 1 : ");
  lcd.setCursor(0,1);
  lcd.print("PINK");
  for(i=0;i<=5;i++)
  {
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 2 : ");
  lcd.setCursor(0,1);
  lcd.print("BLUE");
  for(i=6;i<=11;i++)
  {
    blue();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 3 : ");
  lcd.setCursor(0,1);
  lcd.print("WHITE");
  for(i=12;i<=17;i++)
  {
    white();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 4 : ");
  lcd.setCursor(0,1);
  lcd.print("YELLOW");
  for(i=18;i<=23;i++)
  {
    yellow();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Transmitting");
  lcd.setCursor(0,1);
  lcd.print("PKTs...");
  for(i=24;i<=29;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=30;i<=35;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Receiving");
  lcd.setCursor(0,1);
  lcd.print("PKT 1...");
  for(i=36;i<=37;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    white();
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 1");
  for(i=32;i<=37;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 2");
  for(i=44;i<=49;i++)
  {
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    if(i>=48)
    {
      yellow();
      pixels.setPixelColor(i-30, pixels.Color(0,0,0));
      pixels.show();
      delay(200);
      pixels.setPixelColor(i-24, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
      white();
      pixels.setPixelColor(i-18, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
    }
    else
    {
      white();
      pixels.setPixelColor(i-30, pixels.Color(0,0,0));
      pixels.show();
      delay(200);
      pixels.setPixelColor(i-18, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 2");
  for(i=38;i<=43;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 3");
  for(i=50;i<=55;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-30, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i-24, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    white();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 3");
  for(i=32;i<=37;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 4");
  for(i=56;i<=61;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-30, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 4");
  for(i=38;i<=43;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK...");
  for(i=62;i<=63;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=64;i<=69;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=70;i<=75;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("< ACK Received >");
  delay(2000);
  for(i=0;i<=23;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(10);
  }
  lcd.clear();
}
//------------------------------------------------
void goBackN()
{
  int i,j;
  lcd.setCursor(0,0);
  lcd.print("Go-Back-N");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 1 : ");
  lcd.setCursor(0,1);
  lcd.print("PINK");
  for(i=0;i<=5;i++)
  {
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 2 : ");
  lcd.setCursor(0,1);
  lcd.print("BLUE");
  for(i=6;i<=11;i++)
  for(i=6;i<=11;i++)
  {
    blue();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 3 : ");
  lcd.setCursor(0,1);
  lcd.print("WHITE");
  for(i=12;i<=17;i++)
  {
    white();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 4 : ");
  lcd.setCursor(0,1);
  lcd.print("YELLOW");
  for(i=18;i<=23;i++)
  {
    yellow();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Transmitting");
  lcd.setCursor(0,1);
  lcd.print("PKTs...");
  for(i=24;i<=29;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=30;i<=35;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Receiving");
  lcd.setCursor(0,1);
  lcd.print("PKT 1...");
  for(i=36;i<=37;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    white();
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 1");
  for(i=32;i<=37;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 2");
  for(i=44;i<=49;i++)
  {
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    if(i>=48)
    {
      yellow();
      pixels.setPixelColor(i-30, pixels.Color(0,0,0));
      pixels.show();
      delay(200);
      pixels.setPixelColor(i-24, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
      white();
      pixels.setPixelColor(i-18, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
    }
    else
    {
      white();
      pixels.setPixelColor(i-30, pixels.Color(0,0,0));
      pixels.show();
      delay(200);
      pixels.setPixelColor(i-18, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 2");
  for(i=38;i<=43;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 3");
  for(i=50;i<=55;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-30, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i-24, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    white();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 3");
  for(i=32;i<=37;i++)
  {
    red();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 4");
  for(i=56;i<=61;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-30, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    red();
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 4");
  for(i=38;i<=43;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK...");
  for(i=62;i<=63;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    red();
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=64;i<=69;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    red();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=70;i<=75;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("< ACK Received >");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Error in : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 3");
  delay(2000);
  lcd.clear();
  for(i=0;i<=23;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(10);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Retransmitting :");
  lcd.setCursor(0,1);
  lcd.print("PKT 3-4");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 3 : ");
  lcd.setCursor(0,1);
  lcd.print("WHITE");
  for(i=12;i<=17;i++)
  {
    white();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 4 : ");
  lcd.setCursor(0,1);
  lcd.print("YELLOW");
  for(i=18;i<=23;i++)
  {
    yellow();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Transmitting");
  lcd.setCursor(0,1);
  lcd.print("PKTs...");
  for(i=24;i<=29;i++)
  {
    white();
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=30;i<=35;i++)
  {
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    white();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Receiving");
  lcd.setCursor(0,1);
  lcd.print("PKT 3...");
  for(i=36;i<=37;i++)
  {
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    white();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 3");
  for(i=32;i<=37;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 4");
  for(i=44;i<=49;i++)
  {
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-18, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 4");
  for(i=38;i<=43;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK...");
  for(i=50;i<=51;i++)
  {
    green();
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=64;i<=75;i++)
  {
    j=i%52;
    green();
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("< ACK Received >");
  delay(2000);
  for(i=0;i<=23;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(10);
  }
  lcd.clear();
}
//--------------------------------------------
void selectiveRepeat()
{
  int i,j;
  lcd.setCursor(0,0);
  lcd.print("Selective");
  lcd.setCursor(0,1);
  lcd.print("Repeat");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 1 : ");
  lcd.setCursor(0,1);
  lcd.print("PINK");
  for(i=0;i<=5;i++)
  {
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 2 : ");
  lcd.setCursor(0,1);
  lcd.print("BLUE");
  for(i=6;i<=11;i++)
  for(i=6;i<=11;i++)
  {
    blue();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 3 : ");
  lcd.setCursor(0,1);
  lcd.print("WHITE");
  for(i=12;i<=17;i++)
  {
    white();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 4 : ");
  lcd.setCursor(0,1);
  lcd.print("YELLOW");
  for(i=18;i<=23;i++)
  {
    yellow();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Transmitting");
  lcd.setCursor(0,1);
  lcd.print("PKTs...");
  for(i=24;i<=29;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=30;i<=35;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Receiving");
  lcd.setCursor(0,1);
  lcd.print("PKT 1...");
  for(i=36;i<=37;i++)
  {
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pink();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    white();
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 1");
  for(i=32;i<=37;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 2");
  for(i=44;i<=49;i++)
  {
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    blue();
    pixels.setPixelColor(i-6, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    if(i>=48)
    {
      yellow();
      pixels.setPixelColor(i-30, pixels.Color(0,0,0));
      pixels.show();
      delay(200);
      pixels.setPixelColor(i-24, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
      white();
      pixels.setPixelColor(i-18, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
    }
    else
    {
      white();
      pixels.setPixelColor(i-30, pixels.Color(0,0,0));
      pixels.show();
      delay(200);
      pixels.setPixelColor(i-18, pixels.Color(r,g,b));
      pixels.show();
      delay(200);
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 2");
  for(i=38;i<=43;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 3");
  for(i=50;i<=55;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-30, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i-24, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    white();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 3");
  for(i=32;i<=37;i++)
  {
    red();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK &");
  lcd.setCursor(0,1);
  lcd.print("Receiving PKT 4");
  for(i=56;i<=61;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-30, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    yellow();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    red();
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 4");
  for(i=38;i<=43;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK...");
  for(i=62;i<=63;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    red();
    pixels.setPixelColor(i-12, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=64;i<=69;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(i-18, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
    red();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=70;i<=75;i++)
  {
    j=i%52;
    pixels.setPixelColor(i-24, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    green();
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("< ACK Received >");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Error in : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 3");
  delay(2000);
  lcd.clear();
  for(i=0;i<=23;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(10);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Retransmitting :");
  lcd.setCursor(0,1);
  lcd.print("PKT 3 'ONLY'");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PKT 3 : ");
  lcd.setCursor(0,1);
  lcd.print("WHITE");
  for(i=12;i<=17;i++)
  {
    white();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Transmitting");
  lcd.setCursor(0,1);
  lcd.print("PKTs...");
  for(i=24;i<=29;i++)
  {
    white();
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Receiving");
  lcd.setCursor(0,1);
  lcd.print("PKT 3...");
  for(i=30;i<=37;i++)
  {
    white();
    pixels.setPixelColor(i-6, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Preparing ACK : ");
  lcd.setCursor(0,1);
  lcd.print("PKT 3");
  for(i=32;i<=37;i++)
  {
    green();
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending ACK...");
  for(i=44;i<=49;i++)
  {
    green();
    pixels.setPixelColor(i-12, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=50;i<=51;i++)
  {
    green();
    pixels.setPixelColor(i-6, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  for(i=64;i<=69;i++)
  {
    j=i%52;
    green();
    pixels.setPixelColor(i-18, pixels.Color(0,0,0));
    pixels.show();
    delay(200);
    pixels.setPixelColor(j, pixels.Color(r,g,b));
    pixels.show();
    delay(200);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("< ACK Received >");
  delay(2000);
  for(i=0;i<=23;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(10);
  }
  lcd.clear();
}
//--------------------------------------------
void white()
{
  r = 255;
  g = 255;
  b = 255;
}
//--------------------------------------------
void yellow()
{
  r = 255;
  g = 255;
  b = 0;
}
//--------------------------------------------
void green()
{
  r = 0;
  g = 255;
  b = 0;
}
//--------------------------------------------
void blue()
{
  r = 0;
  g = 0;
  b = 255;
}
//--------------------------------------------
void red()
{
  r = 255;
  g = 0;
  b = 0;
}
//--------------------------------------------
void pink()
{
  r = 255;
  g = 0;
  b = 255;
}