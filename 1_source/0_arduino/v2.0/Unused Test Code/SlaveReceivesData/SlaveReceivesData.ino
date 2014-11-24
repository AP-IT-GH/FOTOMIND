int analogpin = 0;
int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
}

void loop()
{
  val = analogRead(analogpin);
  Serial.println(val);
  if(val == 0)
  {
    digitalWrite(12,LOW);
  }
  else if(val ==1023)
  {
    digitalWrite(12,HIGH);
  }
}
