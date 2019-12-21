#include <AFMotor.h>

 

int s0=3,s1=9,s2=5,s3=6,i=0,j=0,k=0;

 

int OutPut=2;

 

unsigned int frequency = 0;

//unsigned int frequency2 = 0;

//unsigned int frequency3 = 0;
 

AF_DCMotor st1(1);

 

AF_DCMotor st2(2);


int x=10,y=10;

void setup()

{
   Serial.begin(9600);


    pinMode(s0, OUTPUT);

    pinMode(s1, OUTPUT);//PINS 3, 4, 5, 6 as OUTPUT

    pinMode(s2, OUTPUT);

    pinMode(s3, OUTPUT);

    pinMode(OutPut, INPUT);//PIN 10 as input
 

    digitalWrite(s0,HIGH);

    digitalWrite(s1,LOW);//setting frequency selection to 20%

    

   st1.setSpeed(1);

   st2.setSpeed(1);
}

 int u=0,v=1;

void loop()

{
  if(v==1){
    for(int i=1;i<=12;i++)
    {
      st1.run(FORWARD);
      delay(84);
      st1.run(RELEASE);
      Serial.write(1);
      delay(1000);

      digitalWrite(s2,LOW);
 
    digitalWrite(s3,LOW);//setting for RED color sensor
 
    frequency = pulseIn(OutPut, LOW);//reading frequency
 
    if(frequency<1000) Serial.write(10);
    Serial.print(frequency);
 
    digitalWrite(s2,HIGH);
 
    digitalWrite(s3,HIGH);// setting for GREEN color sensor
 
    frequency = pulseIn(OutPut, LOW);// reading frequency
    //Serial.print(frequency2);
    Serial.println();
 
    if(frequency<1000) Serial.write(20);

    
    digitalWrite(s2,LOW);
    
    digitalWrite(s3,HIGH);// setting for BLUE color sensor
    
    frequency = pulseIn(OutPut, LOW);// reading frequency
    
    if(frequency<1000) Serial.write(30);
    }}
    if(v==2)
    {
    for(int i=1;i<=12;i++)
    {
      st1.run(BACKWARD);
      delay(84);
      st1.run(RELEASE);
      Serial.write(1);
      delay(1000);
    
    digitalWrite(s2,LOW);
 
    digitalWrite(s3,LOW);//setting for RED color sensor
 
    frequency = pulseIn(OutPut, LOW);//reading frequency
 
    if(frequency<1000) Serial.write(10);
    Serial.print(frequency);
 
    digitalWrite(s2,HIGH);
 
    digitalWrite(s3,HIGH);// setting for GREEN color sensor
 
    frequency = pulseIn(OutPut, LOW);// reading frequency
    //Serial.print(frequency2);
    Serial.println();
 
    if(frequency<1000) Serial.write(20);

    
    digitalWrite(s2,LOW);
    
    digitalWrite(s3,HIGH);// setting for BLUE color sensor
    
    frequency = pulseIn(OutPut, LOW);// reading frequency
    
    if(frequency<1000) Serial.write(30);
    }
      }

    st2.run(FORWARD);
    delay(540);
    st2.run(RELEASE);
    Serial.write(2);

    
    if(u==12);
    {
      v++;
      u=0;
    }
    if(v==3)
    v=1;
    u++;
    
}
