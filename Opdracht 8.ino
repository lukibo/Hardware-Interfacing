//Bron powerpoint brigthspace les 4 en Eloi Bastien
#include <IRremote.h>
const int ledPins[] = {3, 4, 5, 6};
const int ledTimes[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
const int IrPin = 2;
IRrecv infraredPin(IrPin);
decode_results Result;
unsigned long lastTimes[] = {0, 0, 0, 0};
int ledStatus[] = {LOW, LOW, LOW, LOW};
int ledTiming[] = {0, 0, 0, 0};
int ledHistory[] = {0, 0, 0, 0};
int chosenLED = -1;

void setup() {
    for (int pin: ledPins) {
        pinMode(pin, OUTPUT);
    }
    infraredPin.enableIRIn();
    //Led 1 en 2 aanzetten
    setLed(0, 3);
    setLed(1, 7);
}
//infrarood data
int IRValue() {
    if (infraredPin.decode(&Result)) {
        infraredPin.resume();
        if (Result.value != 0) {
            return (Result.value);
        }
    }
}
//bepaalt wat er gebeurt nadat je op een knop gedrukt hebt
void loop() {
    if (chosenLED == -1) {
        chosenLED = selectLED(IRValue());
    } else {
        if (chosenLED >= 0) {
            flashTime(chosenLED);
        }
    }
    for (int i = 0; i < 4; i++) {
        updateLED(i);
    }
}
//voor het altijd laten knipperen van 2 leds
void setLed(int l, int L) {
    chosenLED = -1;
    if (ledHistory[l] == 0) {
        int counter = 0;
        for (int i: ledHistory) {
            if (i == 1) {
                ledHistory[counter] = 2;
            }
            if (i == 2) {
                ledStatus[counter] = LOW;
                ledHistory[counter] = 0;
                digitalWrite(ledPins[counter], LOW);
            }
            counter++;
        }
        ledStatus[l] = HIGH;
        ledHistory[l] = 1;
        digitalWrite(ledPins[l], HIGH);
    }
    ledTiming[l] = ledTimes[L];
    updateLED(l);
}
//veranderen van led knipperwaardes
void updateLED(int t) {
    unsigned long currentTime = millis();
    if (currentTime - lastTimes[t] >= ledTiming[t] && ledHistory[t] >= 1) {
        lastTimes[t] = currentTime;
        ledStatus[t] = (ledStatus[t] == LOW) ? HIGH : LOW;
        digitalWrite(ledPins[t], ledStatus[t]);
    }
}
//selecteer de led die je wilt laten veranderen
int selectLED(int decInt) {
    switch (decInt) {
        case 16724175:
            return (0);
            break;
        case 16718055:
            return (1);
            break;
        case 16743045:
            return (2);
            break;
        case 16716015:
            return (3);
            break;
    }
    return -1;
}
//bepaal de knippertijd die je wilt meegeven aan de LED
void flashTime(int led) {
    int decInt = IRValue();
    switch (decInt) {
        case 16724175:
            setLed(led, 1);
            break;
        case 16718055:
            setLed(led, 2);
            break;
        case 16743045:
            setLed(led, 3);
            break;
        case 16716015:
            setLed(led, 4);
            break;
        case 16726215:
            setLed(led, 5);
            break;
        case 16734885:
            setLed(led, 6);
            break;
        case 16728765:
            setLed(led, 7);
            break;
        case 16730805:
            setLed(led, 8);
            break;
        case 16732845:
            setLed(led, 9);
            break;
    }
}