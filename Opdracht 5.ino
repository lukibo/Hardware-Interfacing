//Bron Eloi
const int ledR = 11;
const int ledG = 10;
const int ledB = 9;
//kan je gebruiken voor het sneller doorlopen van alle mogelijke kleuren
const int boost = 0;

void setup() {
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
}

void loop() {
    //doorlopen van alle rode kleuren
    for (int redValue = 0; redValue < 255; redValue++) {
        analogWrite(ledR, redValue);
      	redValue = redValue + boost;
        //doorlopen van alle groene kleuren
        for (int greenValue = 0; greenValue < 255; greenValue++) {
            analogWrite(ledG, greenValue);
            greenValue = greenValue + boost;
            //doorlopen van alle blauwe kleuren
            for (int blueValue = 0; blueValue < 255; blueValue++) {
                analogWrite(ledB, blueValue);
                blueValue = blueValue + boost;
            }
        }
    }
  delay(10000);
}