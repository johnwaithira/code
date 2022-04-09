
int URECHO = 3;         // PWM Output 0-50000US,Every 50US represent 1cm
int URTRIG = 5;         // trigger pin

unsigned int DistanceMeasured = 0;

void setup()
{
  //Serial initialization
  Serial.begin(9600);                        // Sets the baud rate to 9600
  pinMode(URTRIG, OUTPUT);                   // A low pull on pin COMP/TRIG
  digitalWrite(URTRIG, HIGH);                // Set to HIGH
  pinMode(URECHO, INPUT);                    // Sending Enable PWM mode command
  delay(500);
  Serial.println("Init the sensor");

}
void loop()
{
  Serial.print("Distance=");
  digitalWrite(URTRIG, LOW);
  digitalWrite(URTRIG, HIGH);              

  unsigned long LowLevelTime = pulseIn(URECHO, LOW) ;
  if (LowLevelTime >= 50000)              
  {
    Serial.println("Invalid");
  }
  else
  {
    DistanceMeasured = LowLevelTime / 50;  
    Serial.print(DistanceMeasured);
    Serial.println("cm");
  }

  delay(200);
}
