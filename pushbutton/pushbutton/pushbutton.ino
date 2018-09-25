
int button = D0;
int buttonState=0;
void setup() {
  Serial.begin(9600);
 pinMode(button, INPUT);
}
void loop() {
 buttonState=digitalRead(button); // put your main code here, to run repeatedly:
 Serial.println(buttonState);
 delay(1000);
}
