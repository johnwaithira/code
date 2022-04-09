//https://meet.google.com/ohx-gpni-tpw

int R,C,L;
void setup()
{
  int i;
  for(i=8;i<=10;i++)
    pinMode(i, INPUT);  
  Serial.begin(9600);      
  Serial.println("IR");
}


void loop(void)
{
  C = digitalRead(9);
  R = digitalRead(8);
  L = digitalRead(10);
  Serial.print("Right - ");
  Serial.println(R);
  Serial.print("Center - ");
  Serial.println(C);
  Serial.print("Left - ");
  Serial.println(L);
  Serial.println();
  


}
