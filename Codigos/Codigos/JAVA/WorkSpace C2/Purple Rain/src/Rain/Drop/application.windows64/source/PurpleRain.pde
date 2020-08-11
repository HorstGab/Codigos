// Daniel Shiffman
// http://codingtra.in
// http://patreon.com/codingtrain
// Code for: https://youtu.be/KkyIDI6rQJI

// Purple Rain
// (138, 43, 226)
// (230, 230, 250) // background

drop[] d = new drop[500];

void setup() {
  //size(640, 360);
  for (int i = 0; i < d.length; i++) {
    d[i] = new drop();
  }
}

void draw() {
  background(230, 230, 250);
  for (int i = 0; i < d.length; i++) {
    d[i].fall();
    d[i].show();
  }
}
