int delayMS = 1000;
int incomingByte = 0;  
// the setup function runs once when you press reset or power the board
void setup() 
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  // send data only when you receive data:
  if (Serial.available() > 0) {
          // read the incoming byte:
          incomingByte = Serial.read();

          // say what you got:
          Serial.print("I received: ");
          Serial.println(incomingByte, DEC);
          
          if(incomingByte == 49)
          {
            digitalWrite(3, HIGH);
            delay(delayMS);
            digitalWrite(3, LOW);
            incomingByte = -10;
          }
  }
  /*
  Serial.println("High");
  digitalWrite(3, HIGH);
  delay(delayMS);
  Serial.println("Low");
  digitalWrite(3, LOW);
  delay(delayMS);*/
}
