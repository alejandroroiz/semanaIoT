int LED = D6;
int PIR_INPUT = D1;

void setup(){
 Serial.begin(9600);
 pinMode(PIR_INPUT,INPUT);
 pinMode(LED,OUTPUT);
}

void loop() {
 int sensor = digitalRead(PIR_INPUT);
 Serial.println(sensor);
 digitalWrite(LED, sensor);
 delay(1000);
}

