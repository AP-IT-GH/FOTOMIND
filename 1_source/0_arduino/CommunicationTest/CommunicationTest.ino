byte incomingByte;   // for incoming serial data
const int testLed = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(testLed, OUTPUT);
}

void loop()
{
if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                if(incomingByte == 56)
                {
                  digitalWrite(testLed, HIGH);
                }
                // say what you got:
                //Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
        }}
