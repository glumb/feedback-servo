#define SERVO_PIN 9


void setup() {
  Serial.begin(9600);
  Serial.println("press enter to set position 0-2");
  delay(2000);
}

int getPosition(unsigned int pin) {
  writeUs(pin, 50); // send a 50 us pulse to get the current position
  pinMode(pin, INPUT);
  return pulseIn(pin, HIGH);
}

void writeUs(unsigned int pin, int us) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delayMicroseconds(us); // send a 50 us pulse to get the current position
  digitalWrite(pin, LOW);
}

int counter = 0;
int STATE = 0;
int positions[3];
int posIndex = 0;

void loop() {
  
  if (Serial.available() > 0 && Serial.read() == '\r') { // wait for enter pres on serial monitor
    switch (STATE) {
      case 0:
        positions[0] = getPosition(SERVO_PIN);
        Serial.print("position 0 set to ");
        Serial.println(positions[0]);
        break;
      case 1:
        positions[1] = getPosition(SERVO_PIN);
        Serial.print("position 1 set to ");
        Serial.println(positions[1]);
        break;
      case 2:
        positions[2] = getPosition(SERVO_PIN);
        Serial.print("position 2 set to ");
        Serial.println(positions[2]);
        break;
    }
    STATE++;
    STATE %= 4;
  }

  switch (STATE) {
    case 3:
      Serial.print("moving to position ");
      Serial.print(posIndex);
      Serial.print(" - ");
      Serial.println(positions[posIndex]);
      delay(10);
      for (int i = 0; i < 10; i++) {
        writeUs(SERVO_PIN, positions[posIndex]);
        delay(1);
      }
      posIndex++;
      posIndex = posIndex % 3;
      delay(2000);
      break;
  }

  counter++;
  if (counter >= 100) {
    counter = 0;
    
    int pwm_value = getPosition(SERVO_PIN);
    for (int i = 500; i < pwm_value; i += 50) {
      Serial.print("|");
      delay(1);
    }
    Serial.println("");
    delay(1000);
  }
}

