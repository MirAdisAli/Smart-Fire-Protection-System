#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

//Constants 

const int dinPin = 3;

const int numOfLeds = 16;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numOfLeds, dinPin, NEO_GRB + NEO_KHZ800);
int Gas_Sensor_Value = 0;
int Light_bulb = A1;
int Gas_sensor = A0;
int Piezo = 7;
int RGB_red = 6;
int RGB_green = 5;
int exhaust_motor = 4;
int sprinkler_motor = 2;

void setup() 
{
  pixels.begin();
  pixels.setBrightness(80);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  pinMode(Gas_sensor, INPUT);
  pinMode(Piezo, OUTPUT);
  pinMode(RGB_red, OUTPUT);
  pinMode(RGB_green, OUTPUT);
  pinMode(exhaust_motor,OUTPUT);
  pinMode(sprinkler_motor,OUTPUT);
  pinMode(Light_bulb, OUTPUT);
}
void loop() 
{
   lcd.clear();
   Gas_Sensor_Value = analogRead(A0);

   if( Gas_Sensor_Value >= 700)
   {
  for(int i=0;i<numOfLeds;i++){
  pixels.setPixelColor(i, pixels.Color(0,255,0));
  pixels.show();
  }
    digitalWrite(sprinkler_motor, HIGH);
    digitalWrite(Piezo, HIGH);
    digitalWrite(exhaust_motor, HIGH);
    digitalWrite(RGB_red, HIGH);
    digitalWrite(RGB_green, LOW);
    digitalWrite(Light_bulb, HIGH);
    lcd.print("City Centre is"); // Print a message to the LCD.
    lcd.setCursor(0,1); 
    lcd.print("on fire!");
    delay(1000);
   }
  else
  {
   digitalWrite(exhaust_motor, LOW);
   digitalWrite(sprinkler_motor, LOW);
   digitalWrite(Piezo, LOW);
   digitalWrite(RGB_red, LOW);
   digitalWrite(RGB_green, HIGH);
   digitalWrite(Light_bulb, LOW);
   lcd.print("City Centre"); // Print a message to the LCD.
   lcd.setCursor(0,1); 
   lcd.print("is Safe"); 
   delay(1000);
  }
  }