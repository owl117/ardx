const int PHTSR_APIN = 0;
const int BTN_DPIN = 8;
const int SPKR_DPIN = 7;
const int L1_DPIN = 13;
const int L2_DPIN = 12;
const int L3_DPIN = 11;
const int L4_DPIN = 10;
const int L5_DPIN = 9;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(BTN_DPIN, INPUT);
  pinMode(SPKR_DPIN, OUTPUT);
  
  pinMode(L1_DPIN, OUTPUT);
  pinMode(L2_DPIN, OUTPUT);
  pinMode(L3_DPIN, OUTPUT);
  pinMode(L4_DPIN, OUTPUT);
  pinMode(L5_DPIN, OUTPUT);
}

void loop() 
{
  double photoSensorValue = analogRead(PHTSR_APIN);
  Serial.println(photoSensorValue);

  int tone = 0;
  
  if (photoSensorValue > 65)
  {
    digitalWrite(L5_DPIN, HIGH);
    tone = 12000;
  }
  else
  {
    digitalWrite(L5_DPIN, LOW);
  }

  if (photoSensorValue > 95)
  {
    digitalWrite(L4_DPIN, HIGH);
    tone = 9000;
  }
  else
  {
    digitalWrite(L4_DPIN, LOW);
  }

  if (photoSensorValue > 125)
  {
    digitalWrite(L3_DPIN, HIGH);
    tone = 6000;
  }
  else
  {
    digitalWrite(L3_DPIN, LOW);
  }

  if (photoSensorValue > 155)
  {
    digitalWrite(L2_DPIN, HIGH);
    tone = 3000;
  }
  else
  {
    digitalWrite(L2_DPIN, LOW);
  }

  if (photoSensorValue > 185)
  {
    digitalWrite(L1_DPIN, HIGH);
    tone = 500;
  }
  else
  {
    digitalWrite(L1_DPIN, LOW);
  }

  if (tone > 0 && digitalRead(BTN_DPIN) == HIGH)
  {
    for (int i = 1; i < 2; ++i)
    {
      digitalWrite(SPKR_DPIN, HIGH);
      delayMicroseconds(tone);
      digitalWrite(SPKR_DPIN, LOW);
      delayMicroseconds(tone);
    }
  }
}
