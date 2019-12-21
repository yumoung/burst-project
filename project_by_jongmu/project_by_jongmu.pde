import processing.serial.*;
// The serial port:
Serial myPort;
int t1 = 9, t2 = 18;  
int[][] arr = new int[360][3];
int[] att = new int[3]; // that theta_max
float[] d = new float[3];
float d0 = 30; 
int i=0; 
int j=0;

void setup() {
  frameRate(5);
  size(1000, 700);
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  background(0);
  if (j >= 360) {
    j=0;
    i += t1;
    myPort.write(2);
  }
  background(0);
  fill(0, 0);
  stroke(255);
  PVector pos = new PVector(250, 350);
  float r = 410;
  ellipse(pos.x, pos.y, r, r);
  PVector p1 = new PVector(r/2*cos(i*PI/180), r/2*sin(i*PI/180));
  PVector p2 = new PVector(r/6*cos(j*PI/180), r/6*sin(j*PI/180));
  stroke(255);
  strokeWeight(1);
  line(pos.x, pos.y, pos.x+p1.x, pos.y+p1.y);
  ellipse(pos.x+p1.x, pos.y+p1.y, r/3, r/3);
  line(pos.x+p1.x, pos.y+p1.y, pos.x+p1.x+p2.x, pos.y+p1.y+p2.y);
  println(p1);
  delay(10);
  j += t2;
  myPort.write(2);
  
  switch(myPort.read()) {
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
  
  if(i >= 360){ // now, it's time to save theta_max and d!!
    for(int  x=0; x<3; x++){
      for(int y=0; y<180; y+=t1){
        int z = (arr[y][x]+arr[y+180][x])%360;
        if(att[x] < z) att[x] = z;
      }
      d[x] = d0/tan(att[x]*PI/180);
    }
    delay(10000000);
  }
  
}
