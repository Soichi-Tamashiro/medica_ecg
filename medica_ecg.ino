const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0

int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value to output to a PWM pin

void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
}

void loop() {
  // read the analog in value
  sensorValue = analogRead(analogInPin);
  
  // read the value from the sensor:
  float voltage = (sensorValue * 3.3) / 1024.0;// ADC of 10 bits
  float mV = voltage*1000;
  Serial.println(mV);
  delay(1000);
}
