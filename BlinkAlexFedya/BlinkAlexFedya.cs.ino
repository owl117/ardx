// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

int _direction = 0;
int _delay = 1000;

// the loop function runs over and over again forever
void loop() {
  Serial.println("www");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(_delay);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(_delay); // wait for a second

  if (_direction == 0)
  {
    _delay = _delay - 50;
    if (_delay <= 0)
    {
      Serial.println("qqq");
      _direction = 1;
    }
  }
  else
  {
    _delay = _delay + 50;
    if (_delay >= 1000)
    {
      Serial.println("aaa");
      _direction = 0;
    }
  }
}
