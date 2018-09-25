#include <Arduino.h>
void setup()
{
    pinMode(D0, OUTPUT); // Initialize the LED_BUILTIN pin as an output
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
    digitalWrite(D0, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    delay(1000); // Wait for a second
    digitalWrite(D0, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    delay(1000);
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    delay(1000);
    digitalWrite(D0, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    delay(1000);
    digitalWrite(D0, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    delay(1000);
    digitalWrite(D0, LOW);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    delay(1000);
    digitalWrite(D0, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    delay(1000);
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    for (int i = 0; i < 1023; i += 10)
    {
        analogWrite(D0, i);
        delay(100);
    }
    analogWrite(D0, 0);
    for (int i = 0; i < 1023; i += 10)
    {
        analogWrite(D1, i);
        delay(100);
    }
    analogWrite(D1, 0);
    for (int i = 0; i < 1023; i += 10)
    {
        analogWrite(D2, i);
        delay(100);
    }
    analogWrite(D2, 0);
    for (int i = 0; i < 1023; i += 10)
    {
        analogWrite(D0, i);
        analogWrite(D1, i);
        delay(100);
    }
    analogWrite(D0, 0);
    analogWrite(D1, 0);
    for (int i = 0; i < 1023; i += 10)
    {
        analogWrite(D1, i);
        analogWrite(D2, i);
        delay(100);
    }
    analogWrite(D1, 0);
    analogWrite(D2, 0);
    for (int i = 0; i < 1023; i += 10)
    {
        analogWrite(D2, i);
        analogWrite(D3, i);
        delay(100);
    }
    analogWrite(D2, 0);
    analogWrite(D3, 0);
    for (int i = 0; i < 1023; i += 10)
    {
        analogWrite(D0, i);
        analogWrite(D1, i);
        analogWrite(D2, i);

        delay(100);
    }
    analogWrite(D0, 0);
    analogWrite(D1, 0);
    analogWrite(D2, 0);
}