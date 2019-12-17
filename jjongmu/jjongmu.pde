import processing.serial.*;
Serial port;
//port=new Serial(this,Serial.list()[1],9600);
//port.write('a');

void setup()
{
  port=new Serial(this,"COM3",300);
  size(400,400);
  frameRate(20);
}
int i=0;
void draw()
{
  background(255);
  int a=port.read();
  //ellipse(150,150,100,100);
  fill(0);
  textSize(20);
  text(a,200,i);
  i+=20;
}
