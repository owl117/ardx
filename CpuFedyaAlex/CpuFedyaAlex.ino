const int DAT_DPIN = 2;
const int CLK_DPIN = 3;
const int LTC_DPIN = 4;

const int LDAT_DPIN = 10;
const int LCLK_DPIN = 11;
const int LLTC_DPIN = 12;

const int L1_DPIN = 13;
const int L2_DPIN = 12;
const int L3_DPIN = 11;
const int L4_DPIN = 10;
const int L5_DPIN = 9;
const int L6_DPIN = 8;
const int L7_DPIN = 7;
const int L8_DPIN = 6;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(DAT_DPIN, OUTPUT);
  pinMode(CLK_DPIN, OUTPUT);
  pinMode(LTC_DPIN, OUTPUT);

  pinMode(LDAT_DPIN, OUTPUT);
  pinMode(LCLK_DPIN, OUTPUT);
  pinMode(LLTC_DPIN, OUTPUT);

  pinMode(L1_DPIN, OUTPUT);
  pinMode(L2_DPIN, OUTPUT);
  pinMode(L3_DPIN, OUTPUT);
  pinMode(L4_DPIN, OUTPUT);
  pinMode(L5_DPIN, OUTPUT);
  pinMode(L6_DPIN, OUTPUT);
  pinMode(L7_DPIN, OUTPUT);
  pinMode(L8_DPIN, OUTPUT);
}

int counter = 0;
void loop() 
{
  int bit1 = (counter & 1) ? 1 : 0;
  int bit2 = (counter & 2) ? 1 : 0;
  int bit3 = (counter & 4) ? 1 : 0;
  int bit4 = (counter & 8) ? 1 : 0;
  int bit5 = (counter & 16) ? 1 : 0;
  int bit6 = (counter & 32) ? 1 : 0;
  int bit7 = (counter & 64) ? 1 : 0;
  int bit8 = (counter & 128) ? 1 : 0;
  
  Serial.print(bit1);
  Serial.print(bit2);
  Serial.print(bit3);
  Serial.print(bit4);
  Serial.print(bit5);
  Serial.print(bit6);
  Serial.print(bit7);
  Serial.print(bit8);
  Serial.print(" ");
  Serial.println(counter);

  Latch(LOW); // close latch before updating chip
  {
    ClockIn(bit1);
    ClockIn(bit2);
    ClockIn(bit3);
    ClockIn(bit4);
    ClockIn(bit5);
    ClockIn(bit6);
    ClockIn(bit7);
    ClockIn(bit8);
  }
  Latch(HIGH); // open latch after updating chip

  delay(200);
  ++counter;
}

void Latch(int signal)
{
  digitalWrite(LTC_DPIN, signal);
  digitalWrite(LLTC_DPIN, signal);
}

void Clock(int signal)
{
  digitalWrite(CLK_DPIN, signal);
  digitalWrite(LCLK_DPIN, signal);
}

void Data(int signal)
{
  digitalWrite(DAT_DPIN, signal);
  digitalWrite(LDAT_DPIN, signal);
}

void ClockIn(int bit)
{
  // Write data bit.
  Data(bit ? HIGH : LOW);

  // Pulse the clock.
  Clock(HIGH);
  delay(1);
  Clock(LOW);
}
