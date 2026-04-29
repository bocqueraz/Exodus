const char PinA = 2;
const char PinB = 4;
const char PinZ = 3;

int NumPulse = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PinA, INPUT);
  pinMode(PinB, INPUT);
  pinMode(PinZ, INPUT);

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(PinA), OnPulse, RISING);
  attachInterrupt(digitalPinToInterrupt(PinZ), OnCylce, RISING);
}

void OnPulse() {
  bool dir = digitalRead(PinB) == HIGH;

  if (dir == false) NumPulse += 1;
  else NumPulse -= 1;
}

void OnCylce() {
  Serial.println("tour complet");
}

void loop() {
}
