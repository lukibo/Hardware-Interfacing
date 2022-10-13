//bron: Thomas Schijvenaars
#include <Servo.h>

Servo myservo;
int servoPin = 8;
int btnPin2 = 2;
int btnPin12 = 12;

int angle = 0;
int lastButtonState1;
int lastButtonState2;      
int currentButtonState1; 
int currentButtonState2;

void setup() {
  myservo.attach(servoPin);
  pinMode(btnPin2, INPUT_PULLUP);
  pinMode(btnPin12, INPUT_PULLUP);
  myservo.write(angle);
}


void loop() {
  delay(100);
  boolean btn2 = false;
  boolean btn12 = false;
  
  lastButtonState1    = currentButtonState1;      
  currentButtonState1 = digitalRead(btnPin2);
  
  lastButtonState2    = currentButtonState2;      
  currentButtonState2 = digitalRead(btnPin12);

  if(lastButtonState1 == HIGH && currentButtonState1 == LOW){
    btn2 = true;
  }

  if (lastButtonState2 == HIGH && currentButtonState2 == LOW){
    btn12= true;
  }
  
  if(btn2 == false && btn12 == true){
	for(int pos = 0; pos <= 120; pos += 24){
     myservo.write(pos);
     delay(100);
    }
    for(int pos = 120; pos >= 0; pos -= 24){
     myservo.write(pos);
     delay(100);
    }
  }
  if(btn2 == true && btn12 == false){
 	for(int pos = 0; pos <= 120; pos += 12){
     myservo.write(pos);
     delay(100);
    }
    for(int pos = 120; pos >= 0; pos -= 12){
     myservo.write(pos);
     delay(100);
    }
  }
  if(btn2 == true && btn12 == true){
	for(int pos = 0; pos <= 120; pos += 12){
     myservo.write(pos);
     delay(100);
    }
    delay(2000);
    for(int pos = 120; pos >= 0; pos -= 12){
     myservo.write(pos);
     delay(100);
    }
  }
}

