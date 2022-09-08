
void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {

  for(int i = 0; i < 8; i++){
    int ledPinLow = i + 1;
    int ledPinHigh = i + 2;
    digitalWrite(ledPinLow, LOW);
    digitalWrite(ledPinHigh, HIGH);
    delay(100);
  }

  for(int i = 6; i > -1; i--){
    int ledPinLow = i + 2;
    int ledPinHigh = i + 1;
    digitalWrite(ledPinLow, LOW);
    digitalWrite(ledPinHigh, HIGH);
    delay(100);
  }
}
