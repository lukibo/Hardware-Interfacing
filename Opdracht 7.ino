//Bron Eloi en sheets van Brightpace
#include <Servo.h>

Servo myservo;
const int triggerPin = 4;
const int echoPin = 7;
const int servoPin = 8;

float time;
float distance;

void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
}

void loop()
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  time = pulseIn(echoPin, HIGH);
  
  distance = time/58;
  
  //kijken of het binnen of gelijk aan 10cm staat
  if (distance <= 10) {
    //kijken of het binnen of gelijk aan 4cm staat
    if (distance <= 4) {
      myservo.write(0);
      }
        int degree = map((distance - 4) * 10, 0, 60, 0, 180);
        myservo.write(degree);

    } else myservo.write(180);

    delay(100);
}