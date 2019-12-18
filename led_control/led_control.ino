void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
}
int i=0;
int k;
void loop() {
  // put your main code here, to run repeatedly:
  /*analogWrite(3,2*i);
  analogWrite(5,i);
  if(k==1) i++;
  if(k==2) i--;
  if(i>=50) k=2;
  if(i<=0) k=1;

  delay(50);*/
  analogWrite(3,1);
  analogWrite(5,1);
}
