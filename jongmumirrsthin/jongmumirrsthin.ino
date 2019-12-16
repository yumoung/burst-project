 int s0 = 3, s1 = 9, s2 = 5, s3 = 6, i = 0;

 

int OutPut = 2;

 

부호없는 int 주파수 = 0;

 

#include <AFMotor.h>

 

 

AF_ 스테퍼 st1 (42, 1);

 

AF_ 스테퍼 st2 (42, 2);

 

 

무효 설정 ()

 

{

 

    Serial.begin (9600);

 

    pinMode (s0, OUTPUT);

 

    핀 모드 (s1, OUTPUT); // PINS 3, 4, 5, 6으로서 OUTPUT

 

    pinMode (s2, OUTPUT);

 

    pinMode (s3, OUTPUT);

 

    pinMode (OutPut, INPUT); // PIN 10을 입력으로

 

 

 

    digitalWrite (s0, HIGH);

 

    digitalWrite (s1, LOW); // 주파수 선택을 20 %로 설정

 

    st1.setSpeed (100);

 

    st2.setSpeed (100);

 

}

 

 

 

무효 루프 ()

 

{

 

    st1.step(100,FORWARD, INTERLEAVE);//1번 스텝모터 10도씩 회전

    

    st2.step(100,FORWARD, INTERLEAVE);//1번 스텝모터 10도씩 회전

    

    Serial.print ( "R ="); // 인쇄 이름

 

    digitalWrite (s2, LOW);

 

    RED 컬러 센서의 digitalWrite (s3, LOW); // setting

 

    주파수 = pulseIn (OutPut, LOW); // 판독 주파수

 

    Serial.print (frequency); // printing 빨간색 주파수

 

    Serial.print ( "");

 

 

   

 

    Serial.print ( "B ="); // 인쇄 이름

 

    digitalWrite (s2, LOW);

 

    BLUE 컬러 센서의 digitalWrite (s3, HIGH); // 설정

 

    주파수 = pulseIn (OutPut, LOW); // 판독 주파수

 

    Serial.print (frequency); // BLUE 색 주파수 인쇄

 

    Serial.print ( "");

 

    if (주파수 <100)

    {

      Serial.print ( "모터의 회전 각도는 =");

      Serial.print (i);

    }

    

 

   

 

    Serial.print ( "G ="); // 인쇄 이름

 

    digitalWrite (s2, HIGH);

 

    초록색 센서의 digitalWrite (s3, HIGH); // 설정

 

    주파수 = pulseIn (OutPut, LOW); // 판독 주파수

 

    Serial.print (frequency); // 초록색 주파수 인쇄

 

    Serial.print ( "");

    지연 (100);

 

    Serial.println ();

    i + = 100;

}  
