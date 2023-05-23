#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
int sensorVal=0;
int mg=0;
const int buttonPin=2;
int buttonState=0;
SoftwareSerial MyBlue(0, 1  ); // RX |  TX

LiquidCrystal_I2C lcd(0x3F,16,2);
int cal;
void setup() {
lcd.init();
lcd.backlight();
  MyBlue.begin(9600);
  Serial.begin(9600);
pinMode(buttonPin,INPUT);
pinMode(3,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,OUTPUT);
cal=callibration();
lcd.begin(16,2);
digitalWrite(3,HIGH);
digitalWrite(A1,HIGH);

}

void loop() {
buttonState=digitalRead(buttonPin);

if (buttonState==HIGH)
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Gluco Meter!");
  lcd.print("Sensor init...");
  delay(1000);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0 , 1600);
  int glucose = (0.000009) * (sensorValue) * (sensorValue) + (0.1788) * (sensorValue) + 49.454;
  analogWrite(analogoutPin, OutputValue);
  lcd.setCursor(0,0);
  lcd.print("Glu: ");
  lcd.setCursor(0,1);
  lcd.print(int(glucose));
  Serial.println(int(glucose));
  lcd.setCursor(5,1);
  lcd.print("mg/dl");
  int haemoglobin = (458.33) * (sensorValue) + 1.14436;
  lcd.println("H: ");
  lcd.print(int(haemoglobin));
  Serial.println(int(haemoglobin));
  lcd.setCursor(5,1);
  lcd.print("g/dl");
  }
  else
  return;
}
int callibration()  //the sensor calliberation part 
{
  int s=0;
  int call=0;
  for (int i=0;i<20;i++)
  {
    s=analogRead(A0);
    call=call+s;
    delay(1000);
    }
call=call/20;
  return call;
  }
  

