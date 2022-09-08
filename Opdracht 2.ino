//bron https://roboticsbackend.com/arduino-turn-led-on-and-off-with-button/
//samenwerking met Viktor

const int ledPin11 = 11;
const int butPin5 = 5;

byte lastButtonState = LOW;
byte ledState = LOW;
//zorgt ervoor dat na 50 milliseconden de veranderingen worden genegeerd
unsigned long debounceDuration = 50; 
unsigned long lastTimeButtonStateChanged = 0;

void setup() {
  pinMode(ledPin11, OUTPUT);
  pinMode(butPin5, INPUT);  
}
//functie voor het aan en uit zetten van de led
void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
    byte buttonState = digitalRead(butPin5);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        ledState = (ledState == HIGH) ? LOW: HIGH;
        digitalWrite(ledPin11, ledState);
      }
    }
  }
}
