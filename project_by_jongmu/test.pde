int t1 = 10, t2 = 10;  
int[][] arr = new int[360][3];
int i=0;

void setup() {
  frameRate(100);
  size(1000, 700);
}

void draw() {
  int j = 0;
  background(0);
  while (j >= 360) {
    background(0);
    fill(0, 0);
    stroke(255);
    PVector pos = new PVector(300, 350);
    float r = 500;
    ellipse(pos.x, pos.y, 500, 500);
    PVector p1 = new PVector(r/2*cos(i*PI/180), r/2*sin(i*PI/180));
    PVector p2 = new PVector(r/6*cos(j*PI/180), r/6*sin(j*PI/180));
    stroke(255);
    strokeWeight(1);
    line(pos.x, pos.y, pos.x+p1.x, pos.y+p1.y);
    ellipse(pos.x+p1.x, pos.y+p1.y, r/3, r/3);
    line(pos.x+p1.x, pos.y+p1.y, pos.x+p1.x+p2.x, pos.y+p1.y+p2.x);
    println(p1);
    delay(100);
    j+=t2;
  }  
  i+=t1;

  //theta max code
  //save d ..
}
