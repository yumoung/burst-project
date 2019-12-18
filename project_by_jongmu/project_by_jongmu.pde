import processing.serial.*;
// The serial port:
Serial myPort;       

int t1, t2;  
int[][] arr = new int[360][3];


void setup() {
  size(1000, 700);
 // List all the available serial ports:
  printArray(Serial.list());

  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
}
void draw() {
  PVector pos = new PVector(300, 350);
  background(0);
  fill(0);
  println("dddd");
  stroke(255);
  ellipse(pos.x, pos.y, 500, 500);
  for (int i=0; i<=360; i+=t1) {
    for (int j=0; j<=360; j+=t2) {
      myPort.write(2); // 2 is spin of t2
      delay(100);
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
    }
    
    //theta max code
    //save d .. 
  }
  delay(100);
  myPort.write(1); // 1 is spin of t1
}
