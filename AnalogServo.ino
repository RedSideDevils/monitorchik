/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
#include <Servo.h>
#define trigPin 5
#define echoPin 4

Servo myservo1;
Servo myservo2;

bool isClick = false;
int Mod = 0;
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() 
{
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo1.attach(9);
  myservo2.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void Manual(){
  int Y = analogRead(A7);
  int X = analogRead(A0);
  int val1 = map(X, 0, 906, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo1.write(val1);
  int val2 = map(Y, 0, 906, 0, 90);     // scale it to use it with the servo (value between 0 and 180)
  myservo2.write(val2);// sets the servo position according to the scaled value  
  Serial.print("X=");
  Serial.println(X);
  Serial.print("Y=");
  Serial.println(Y);
}
void Auto(){
  myservo1.write(0);
  delay(500);
  myservo1.write(120);
  delay(500);  
}

// the loop routine runs over and over again forever:
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; 
  Serial.print(distance);
  Serial.println(" cm");
  // read the input on analog pin 0:
   buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    isClick = true;
    digitalWrite(ledPin, HIGH);
  } else 
  {
    // turn LED off:
    isClick = false;
    digitalWrite(ledPin, LOW);
  }
  if(isClick){
    Manual();
  }else{
    Auto();
  }
  /*  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 255;
  blueValue = 255;
 */ 

}
