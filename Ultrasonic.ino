#define trigPin 10
#define echoPin 11
#define led 13

#define RED 3
#define GREEN 2

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
}

void loop()
{
/*  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 255;
  blueValue = 255;
 */ 
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance<30)
  { 
   digitalWrite(RED, HIGH);
   digitalWrite(GREEN, LOW);
   Serial.println("Red");
  }
  if (distance>=30)
  {
   digitalWrite(RED, LOW);
   digitalWrite(GREEN,HIGH);
   Serial.println("Green");
  }
  
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
}
