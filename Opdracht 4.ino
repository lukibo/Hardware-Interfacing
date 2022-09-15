//https://create.arduino.cc/projecthub/infoelectorials/project-003-arduino-lm35-temperature-sensor-project-0a43ba
int val;
int tempPin = 1;

void setup()
{
  //Om de serial connectie te maken
  Serial.begin(9600);
}

void loop()
{
  //berekenen van de temperatuur
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float celsius = mv/10;
  //printen van de gemeten temperatuur
  Serial.print("Temperatuur = ");
  Serial.print(celsius);
  Serial.print("*C");
  Serial.println();
  delay(1000);

}