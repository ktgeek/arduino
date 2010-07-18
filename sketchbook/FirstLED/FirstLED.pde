const int LED_PIN10 = 10;
const int LED_PIN11 = 11;
const int LED_PIN12 = 12;
const int PAUSE = 500;

void setup()
{
  pinMode(LED_PIN10, OUTPUT);
  pinMode(LED_PIN11, OUTPUT);
  pinMode(LED_PIN12, OUTPUT);
  digitalWrite(LED_PIN10, LOW);
  digitalWrite(LED_PIN11, LOW);
  digitalWrite(LED_PIN12, LOW);
}

void loop()
{
  digitalWrite(LED_PIN10, HIGH);
  delay(PAUSE);
  digitalWrite(LED_PIN10, LOW);
  digitalWrite(LED_PIN11, HIGH);
  delay(PAUSE);
  digitalWrite(LED_PIN11, LOW);
  digitalWrite(LED_PIN12, HIGH);
  delay(PAUSE);
  digitalWrite(LED_PIN12, LOW);
}
