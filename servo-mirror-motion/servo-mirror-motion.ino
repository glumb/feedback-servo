#define SERVO1_PIN 9
#define SERVO2_PIN 10

void setup() {
  Serial.begin(9600);
}

int getPosition(unsigned int pin) {
  writeUs(pin, 50); // send a 50 us pulse to get the current position
  pinMode(pin, INPUT);
  return pulseIn(pin, HIGH); // count us until the servo pulls the pin high
}

// write a microsecond pulse to the specified pin
void writeUs(unsigned int pin, int us) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delayMicroseconds(us);
  digitalWrite(pin, LOW);
}

void loop() {
  int us = getPosition(SERVO1_PIN);
  writeUs(SERVO2_PIN, us);

  Serial.print("500,2600,");
  Serial.println(us);
}

