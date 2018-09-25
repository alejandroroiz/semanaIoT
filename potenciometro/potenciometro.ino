const int pin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int x = analogRead(pin);
  delay(100);

  Serial.println("valor:  ");
  Serial.println(x);
}
