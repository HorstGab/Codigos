import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Drop extends PApplet {

// Daniel Shiffman
// http://codingtra.in
// http://patreon.com/codingtrain
// Code for: https://youtu.be/KkyIDI6rQJI

class drop{
  float x;
  float y;
  float z;
  float len;
  float yspeed;

  public drop() {
    x  = random(width);
    y  = random(-500, -50);
    z  = random(0, 20);
    len = map(z, 0, 20, 10, 20);
    yspeed  = map(z, 0, 20, 1, 20);
  }

  public void fall() {
    y = y + yspeed;
    float grav = map(z, 0, 20, 0, 0.2f);
    yspeed = yspeed + grav;

    if (y > height) {
      y = random(-200, -100);
      yspeed = map(z, 0, 20, 4, 10);
    }
  }

  public void show() {
    float thick = map(z, 0, 20, 1, 3);
    strokeWeight(thick);
    stroke(138, 43, 226);
    line(x, y, x, y+len);
  }
}
// Daniel Shiffman
// http://codingtra.in
// http://patreon.com/codingtrain
// Code for: https://youtu.be/KkyIDI6rQJI

// Purple Rain
// (138, 43, 226)
// (230, 230, 250) // background

drop[] d = new drop[500];

public void setup() {
  //size(640, 360);
  for (int i = 0; i < d.length; i++) {
    d[i] = new drop();
  }
}

public void draw() {
  background(230, 230, 250);
  for (int i = 0; i < d.length; i++) {
    d[i].fall();
    d[i].show();
  }
}

  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Drop" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
