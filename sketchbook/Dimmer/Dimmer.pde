// Dimming only works on pins 3, 5, 6, 9, 10, 11

const int LED = 11;

void setup()
{
    //    pinMode(LED, OUTPUT);
    //    digitalWrite(LED, LOW);
}

void loop()
{
    analogWrite(LED, 255);
    delay(2000);
    analogWrite(LED, 127);
    delay(2000);
    analogWrite(LED, 64);
    delay(2000);
}
