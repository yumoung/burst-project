int t1,t2;  
// Example by Tom Igoe

import processing.serial.*;

// The serial port:
Serial myPort;       


void setup(){
  // List all the available serial ports:
  printArray(Serial.list());

  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
  
}
void draw(){
  for(int i=0; i<=360; i+=t1){
    for(int j=0; j<=360; j+=t2){
      myPort.write(2); // 1 is spin of t2
      delay(100);
      if(myPort.read()==100){ //when i get signal from aduino
        //processing code of when i get color signal f
      }
    }
    delay(100);
    myPort.write(1); // 2 is spin of t1
  }
  
}
