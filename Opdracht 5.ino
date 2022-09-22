const int led11 = 11;
const int led10 = 10;
const int led9 = 9;
const int boost = 0;

void setup() {
    pinMode(led11, OUTPUT);
    pinMode(led10, OUTPUT);
    pinMode(led9, OUTPUT);
    //nodig voor het noteren van alle kleuren
    Serial.begin(9600);
}

void loop() {
  //door lopen van alle mogelijke rode kleuren
    for (int rValue = 0; rValue < 255; rValue++) {
        analogWrite(led11, rValue);
        rValue += boost;
        Serial.print("Red");
        Serial.print(rValue);
        Serial.print("\n");
        //door lopen van alle mogelijke groene kleuren
        for (int gValue = 0; gValue < 255; gValue++) {
            analogWrite(led10, gValue);
            gValue += boost;
            Serial.print("\t");
            Serial.print("Green");
            Serial.print(gValue);
            Serial.print("\n \t \t");
            //door lopen van alle mogelijke blauwe kleuren
            for (int bValue = 0; bValue < 255; bValue++) {
                analogWrite(led9, bValue);
                bValue += boost;
                Serial.print("Blue");
                Serial.print(bValue);
                Serial.print("\t");
            }
            Serial.print("\n");
        }
    }
  delay(10000);
}