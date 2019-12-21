import processing.serial.*;
// The serial port:
Serial myPort;
int t1 = 30, t2 = 30;  
int[][] arr = new int[360][3];  //감지시 각도, [모터1의 각도][색] = [모터2 각도] 
int[] att = new int[3]; // that theta_max   // r g b의 최대각 저장 배열
float[] d = new float[3];  // 거리 
float d0 = 30; //장치의 팔길이
int i=0;   // 모터 1의 각
int j=0;  //모터 2의 각

void setup() {
  size(1000, 700);
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  background(0);
  fill(0, 0);
  stroke(255);
  PVector pos = new PVector(250, 350);
  float r = 410;
  ellipse(pos.x, pos.y, r, r);  //큰 원
  PVector p1 = new PVector(r/2*cos(i*PI/180), r/2*sin(i*PI/180));  //긴 선의 위치벡터
  PVector p2 = new PVector(r/6*cos(j*PI/180), r/6*sin(j*PI/180));  //짧은 선의 위치벡터
  stroke(255);
  strokeWeight(1);
  line(pos.x, pos.y, pos.x+p1.x, pos.y+p1.y);  //긴 선
  ellipse(pos.x+p1.x, pos.y+p1.y, r/3, r/3);   //작은 원
  line(pos.x+p1.x, pos.y+p1.y, pos.x+p1.x+p2.x, pos.y+p1.y+p2.y); // 짧은 선
    
  switch(myPort.read()) {
      case 1:   //1을 받았을 때
         j=0;   //모터 2 각 초기화
         i += t1;
      case 2:   //모터 1 각 초기화
         j += t2;
      case 10: 
        arr[i][0] = j; 
        stroke(255, 0, 0);
        line(pos.x+p1.x, pos.y+p1.y, pos.x+p1.x+p2.x, pos.y+p1.y+p2.y);
        break;    //red
      case 20: 
        arr[i][1] = j; 
        stroke(0, 255, 0);
        line(pos.x+p1.x, pos.y+p1.y, pos.x+p1.x+p2.x, pos.y+p1.y+p2.y);
        break;     //green
      case 30: 
        arr[i][2] = j;
        stroke(0, 0, 255);
        line(pos.x+p1.x, pos.y+p1.y, pos.x+p1.x+p2.x, pos.y+p1.y+p2.y);
        break;     //blue
  }
  
  if(i >= 360){ // 만약 모터 1이 한바퀴를 돌면
    for(int  x=0; x<3; x++){
      for(int y=0; y<180; y+=t1){
        int z = (arr[y][x]+arr[y+180][x])%360;
        if(att[x] < z) att[x] = z;
        println("theta: "+att[x]);
      }
      d[x] = d0/tan(att[x]*PI/180);
      println("d[x]: "+d[x]);
    }
    
    delay(10000000);
  }
  
}
