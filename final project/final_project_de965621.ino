#include <LiquidCrystal.h> // includes the LiquidCrystal Library

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2 ;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 10;
const int echoPin = 13;
long duration;//LONG VARIABLE
float distanceCm, distanceMeter;
const int cmbuttonPin = 7;
//declaration of all pin we used

void setup(){
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
lcd.print(" SOCIAL DISTANCE ");
lcd.setCursor(0,1);//FOR SECOND LINE OF LCD
lcd.print(" FINAL PROJECT");
delay(2);
pinMode(cmbuttonPin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}


void loop(){
  int value = digitalRead(cmbuttonPin); 
    digitalWrite(trigPin, LOW);
    delay(2);
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
  
  if (value == HIGH){
	distanceCm= duration*0.0344/2;
    lcd.setCursor(0,1);//FOR SECOND LINE OF LCD
    lcd.print("YOUR MEASUREMENT ");
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Distance:"); // Prints string "Distance" on the LCD
    lcd.print(distanceCm); // Prints the distance value from the sensor
    lcd.print("cm");
    delay(10);
 }
  else
  {
	distanceMeter = duration*0.000344/2;
    lcd.setCursor(0,0);//FOR SECOND LINE OF LCD
    lcd.print(" SOCIAL DISTANCE ");
    delay(2);
    lcd.setCursor(0,1);
    lcd.print("Distance:");
    lcd.print(distanceMeter);
    lcd.print("  m");
    delay(10);
    Serial.println("distanceInch= ");
  }
}