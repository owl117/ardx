const int BTN_PIN = 4;
const int RED_PIN = 12;

void setup() 
{
  Serial.begin(9600);
  pinMode(BTN_PIN, INPUT);
  pinMode(5, INPUT);
  pinMode(RED_PIN, OUTPUT);
//  pinMode(LED_BUILTIN, OUTPUT);
}

const double MA_N = 100;
double _ma4 = 0;
double _ma5 = 0;

void loop() 
{
  _ma4 = _ma4 + (double)analogRead(BTN_PIN) - _ma4/MA_N;
  _ma5 = _ma5 + (double)analogRead(5) - _ma5/MA_N;
  
  Serial.print((int)(_ma4 / MA_N));
  Serial.print(" ");
  Serial.println((int)(_ma5 / MA_N));
  if (digitalRead(BTN_PIN) == HIGH)
  {
    digitalWrite(RED_PIN, HIGH);
  }
  else
  {
    digitalWrite(RED_PIN, LOW);
  }
}
