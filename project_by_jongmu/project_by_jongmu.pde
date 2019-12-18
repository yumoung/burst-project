import processing.serial.*;
// The serial port:
Serial myPort;
int t1 = 10, t2 = 10;  
int[][] arr = new int[360][3];
int[] att = new int[3]; // that theta_max
int i=0; 
int j=0;

void setup() {
  frameRate(100);
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
  }
  println("j "+j);
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
        break;    //red
      case 20: 
        arr[i][1] = j; 
        break;     //blue
      case 30: 
        arr[i][2] = j; 
        break;     //green
  }
  
  if(i >= 360){ // now, it's time to save theta_max and d!!
    for(int  x=0; x<180; x+=t1){
      for(int y=0; y<3; y++){
        int z = (arr[x][y]+arr[x+180][y])%360;
        if(att[y] < z) att[y] = z;
      }
    }
    delay(10000000);
  }
  
}
