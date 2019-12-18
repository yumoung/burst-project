#include <AFMotor.h>

 

int s0=3,s1=4,s2=5,s3=6,i=0,j=0,k=0;

 

int OutPut=2;

 

unsigned int frequency = 0;

 

AF_Stepper st1(42,1);

 

AF_Stepper st2(42,2);

 

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

    

   st1.setSpeed(100);

   

   st2.setSpeed(100);

}

 

void loop()

{

    st1.step(30,FORWARD, INTERLEAVE);//1번 스텝모터 10도씩 회전

    for(k=1;k<=12;k++)

    {

    st2.step(30,FORWARD, INTERLEAVE);//1번 스텝모터 10도씩 회전

 

    /*Serial.print("R=");//printing name

 

    digitalWrite(s2,LOW);

 

    digitalWrite(s3,LOW);//setting for RED color sensor

 

    frequency = pulseIn(OutPut, LOW);//reading frequency

 

    Serial.print(frequency);//printing RED color frequency

 

    Serial.print("  ");

*/

   

 //--------------------------------------------------------------

   Serial.print("B=");// printing name
    digitalWrite(s2,LOW);
    digitalWrite(s3,HIGH);// setting for BLUE color sensor
    frequency = pulseIn(OutPut, LOW);// reading frequency
    Serial.print(frequency);// printing BLUE color frequency
    Serial.print("  ");
    Serial.println();
    f[i]=frequency;

    if(f[i]-f[i-1]<=20)
    {
      Serial.write(10); 
    }
     
 //--------------------------------------------------------------
    

    j+=30;

    Serial.print("j=");

    Serial.print(j);

    Serial.println();

    delay(100);

    }

   i+=30;

 

  /*  Serial.print("G=");// printing name

 

    digitalWrite(s2,HIGH);

 

    digitalWrite(s3,HIGH);// setting for GREEN color sensor

 

    frequency = pulseIn(OutPut, LOW);// reading frequency

 

    Serial.print(frequency);// printing GREEN color frequency

 

    Serial.print("    ");

 

    Serial.println();*/

    if(i==360)

    i=0;

    if(j==360)

    j=0;

    Serial.print("i=");

    Serial.print(i);

    Serial.println();

    

}
