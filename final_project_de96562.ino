#include <LiquidCrystal.h>  // includes the LiquidCrystal Library\

  int buttonState = 0;
  const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2 ;
  LiquidCrystal lcd(rs,en,d4,d5,d6,d7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
  const int trigPin = 10;
  const int echoPin = 13;
  long duration;//LONG VARIABLE
  float distanceCm, distanceMeter;
  int buzzer = 8;
  int LEDalert = A3;
  int LEDMeter = A4;
  int LEDcm = A5;
//declaration of all pin we used

void setup()
{
  lcd.begin(16,2); // Initializes the interface to the LCD
  lcd.print(" SOCIAL DISTANCE ");
  lcd.setCursor(0,1);//FOR SECOND LINE OF LCD
  lcd.print(" FINAL PROJECT");
  delay(2000);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(9, INPUT);
  pinMode(8,OUTPUT);
  pinMode(LEDalert, OUTPUT);
  pinMode(LEDMeter, OUTPUT);
  pinMode(LEDcm, OUTPUT);
}

void sound()
{
	if(distanceMeter <= 1)//less than or equal 1m, buzzer will beep
  { 
    digitalWrite(buzzer, HIGH);
    delay(2);
    digitalWrite(buzzer, LOW);
    analogWrite(LEDalert, 255);//brightness of LED 
    delay(20);
    analogWrite(LEDalert, 0);  
  }
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  buttonState = digitalRead(9);  // read the state of the pushbutton
  
  
  if (buttonState == HIGH)   // check if pushbutton is pressed. if it is, the
  {
   	distanceMeter = duration*0.000344/2; //value in meter
    lcd.setCursor(0,0);
    lcd.print(" SOCIAL DISTANCE ");
    delay(2);
    lcd.setCursor(0,1);//FOR SECOND LINE OF LCD
    lcd.print("Distance:");
    lcd.print(distanceMeter);
    lcd.print("  m");
    delay(10);
    sound();
    analogWrite(LEDMeter, 255);
    delay(20);
    analogWrite(LEDMeter, 0);
    Serial.println("distanceMeter= ");
  } 
  else 
  {
    distanceCm= duration*0.0344/2; //value in centimeter
    lcd.setCursor(0,1);//FOR SECOND LINE OF LCD
    lcd.print("YOUR MEASUREMENT ");
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Distance:"); // Prints string "Distance" on the LCD
    lcd.print(distanceCm); // Prints the distance value from the sensor
    lcd.print("cm");
    analogWrite(LEDcm, 255);
    delay(10);
    analogWrite(LEDcm, 0);
  }
  delay(10); // Delay a little bit to improve simulation performance

}
