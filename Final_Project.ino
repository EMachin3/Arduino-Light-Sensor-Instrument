 int lightSensorPin = A1;
 int speakerPin = 8;
 int buttonPin = 6;
 int onBoardLED = 13;
 int led1 = 9;
 int led2 = 10;
 int led3 = 11;
 int led4 = 12;
 int val;
 //initialize variables with global scope for some reason
void setup() {
 Serial.begin(9600);
 //serial port for bug fixing
  pinMode(buttonPin, INPUT);
  pinMode(onBoardLED, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  //initializing LEDs
}

void loop() {
while (digitalRead(buttonPin) == HIGH) {
  digitalWrite(onBoardLED, LOW);
  val = 1023 - analogRead(lightSensorPin);
  //record value from light sensor
  //val = map(val, 0, 1023, 261.63, 493.88);
  val = map(val, 0, 1023, 130.81, 987.77);
  //map light sensor value to a range of three octaves around middle C
  //val = map(val, 0, 1023, 0, 512);
  tone(8, val, 1000);
  //play tone on piezo with frequency of mapped value
  Serial.println(val);
  //turn on different amount of LEDs based on pitch with if statements
  if (val < 345){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (val >= 345 && val < 559){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (val >= 559 && val < 773){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if (val >= 773 && val < 988){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    Serial.println("this shouldn't be happening");
  }
  delay(1000);
}
digitalWrite(onBoardLED, HIGH);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
}
