const int analogIn=A0;
int mVperAmp=66;
int Rawvalue = 0;
int ACSsoffset =2500;
double voltage = 0;
double Amps = 0;

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
 
MPU6050 accelgyro;
 
int16_t ax, ay, az;
int16_t gx, gy, gz;
 
int accel_reading;
int accel_corrected;
int accel_offset = 200;
float accel_angle;
float accel_scale = 1;
 
int gyro_offset = 151;
double dgy_x,deg;
double angle;
float last_read_time;
float last_x_angle,last_y_angle,last_z_angle;
 
void setup() {
  Wire.begin();
  Serial.begin(9600);
  accelgyro.initialize();
  pinMode(3,INPUT);
  pinMode(4,INPUT);
}

int i[1000];
int k=0;
void loop() {
  // 가속도 및 자이로 x,y,z 축에 대한 데이터 받아오기
  // 가속도 값은 -16800 ~ 16800 범위를 -90 ~ 90으로 바꿔줌
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  accel_reading = ay;
  accel_corrected = accel_reading - accel_offset;
  accel_corrected = map(accel_corrected, -16800, 16800, -90, 90);
  accel_corrected = constrain(accel_corrected, -90, 90);
  accel_angle = (float)(accel_corrected * accel_scale);
 
  // 가속도만을 이용한 각도 출력
  Serial.print("Acc angle : ");
  Serial.print(accel_angle);
  Serial.print("\t");
 
  deg = atan2(ax, az) * 180 / PI;     // rad to deg
  
  // 자이로+가속도 조합한 각도
  dgy_x = gy / gyro_offset;
  angle = (0.95 * (angle + (dgy_x * 0.001))) + (0.05 * deg);
 
  // 자이로 가속도 둘 다 이용한 각도 출력
  Serial.print("Filter angle : ");
  Serial.println(angle) ;

  Rawvalue = analogRead(analogIn);  
 voltage = (Rawvalue / 1024.0) * 5000;   
 Amps = ((voltage - ACSsoffset) / mVperAmp);  
   
 //Serial.print(Voltage/1000);   
 //Serial.print("\t");    
 //Serial.println(Amps);      
 
  if(digitalRead(3)==HIGH)
  {
    i[k]=angle;
  }
  if(digitalRead(4)==HIGH)
  {
    for(int j=1;j<=k;j++)
    {
      s1.write(i[k]);
      delay(50);
    }
  }
  k++;
  delay(50);
}
