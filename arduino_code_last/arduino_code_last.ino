#include <AFMotor.h>

 

int s0=3,s1=9,s2=5,s3=6,i=0,j=0,k=0;

 

int OutPut=2;

 

unsigned int frequency1 = 0;

unsigned int frequency2 = 0;

unsigned int frequency3 = 0;
 

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

 

void loop()

{
    if(Serial.read()==1)
    {
     st1.run(FORWARD);
     delay(180);
     st1.run(RELEASE);
    }
 
    if(Serial.read()==2)
    {
     st2.run(FORWARD)
      delay(180);
     st1.run(RELEASE);
    }
 
 
    digitalWrite(s2,LOW);
 
    digitalWrite(s3,LOW);//setting for RED color sensor
 
    frequency1 = pulseIn(OutPut, LOW);//reading frequency
 
    if(frequency1<1000) Serial.write("10");
    

 
    digitalWrite(s2,HIGH);
 
    digitalWrite(s3,HIGH);// setting for GREEN color sensor
 
    frequency2 = pulseIn(OutPut, LOW);// reading frequency
 
    if(frequency2<1000) Serial.write("20");


    
    digitalWrite(s2,LOW);
    
    digitalWrite(s3,HIGH);// setting for BLUE color sensor
    
    frequency3 = pulseIn(OutPut, LOW);// reading frequency
    
    if(frequency3<1000) Serial.write("30");

}
