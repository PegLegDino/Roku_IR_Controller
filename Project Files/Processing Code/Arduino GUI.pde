import controlP5.*; //import ControlP5 library
import processing.serial.*;

Serial port;

ControlP5 cp5; //create ControlP5 object

PFont font;

void setup(){ //same as arduino program

  size(450, 600);    //window size, (width, height)
  
  printArray(Serial.list());   //prints all available serial ports
  
  port = new Serial(this, Serial.list()[0], 9600);  //i have connected arduino to com3, it would be different in linux and mac os
  
  //lets add buton to empty window
  
  cp5 = new ControlP5(this);
  font = createFont("Arial Rounded MT Bold", 20);    // custom fonts for buttons and title
  
  cp5.addButton("up")     //"up" is the name of button
    .setPosition(100, 50)  //x and y coordinates of upper left corner of button
    .setSize(120, 70)      //(width, height)
    .setFont(font)
  ;   

  cp5.addButton("down")     //"yellow" is the name of button
    .setPosition(100, 150)  //x and y coordinates of upper left corner of button
    .setSize(120, 70)      //(width, height)
    .setFont(font)
  ;

  cp5.addButton("left")     //"blue" is the name of button
    .setPosition(100, 250)  //x and y coordinates of upper left corner of button
    .setSize(120, 70)      //(width, height)
    .setFont(font)
  ;
  
  cp5.addButton("right")     //"alloff" is the name of button
    .setPosition(100, 350)  //x and y coordinates of upper left corner of button
    .setSize(120, 70)      //(width, height)
    .setFont(font)
  ;
  cp5.addButton("ok")     //"alloff" is the name of button
    .setPosition(100, 450)  //x and y coordinates of upper left corner of button
    .setSize(120, 70)      //(width, height)
    .setFont(font)
  ;
  cp5.addButton("amazon")
     .setValue(128)
     .setPosition(250,50)
     .setSize(120, 70)      //(width, height)
     .setFont(font)
  ;
  cp5.addButton("netflix")
     .setValue(128)
     .setPosition(250,150)
     .setSize(120, 70)      //(width, height)
     .setFont(font)
  ;
  cp5.addButton("hulu")
     .setValue(128)
     .setPosition(250,250)
     .setSize(120, 70)      //(width, height)
     .setFont(font)
  ;
  cp5.addButton("disney")
     .setValue(128)
     .setPosition(250,350)
     .setSize(120, 70)      //(width, height)
     .setFont(font)
  ;
  cp5.addButton("disney")
     .setValue(128)
     .setPosition(250,350)
     .setSize(120, 70)      //(width, height)
     .setFont(font)
  ;
  cp5.addButton("home")
     .setValue(128)
     .setPosition(250,450)
     .setSize(120, 70)      //(width, height)
     .setFont(font)
  ;
}

void draw(){  //same as loop in arduino

  background(170, 207, 226); // background color of window (r, g, b) or (0 to 255)
  
  //lets give title to our window
  fill(255, 255, 255);               //text color (r, g, b)
  textFont(font, 38);
  text("Beta Remote", 120, 40);  // ("text", x coordinate, y coordinat)
}

//lets add some functions to our buttons
//so whe you press any button, it sends perticular char over serial port

void up(){ //<>//
  port.write('u');
  println("up");
}

void down(){
  port.write("d");
  println("down");
}

void left(){
  port.write("l");
  println("left");
}

void right(){
  port.write("r");
  println("right");
}

void ok(){
  port.write("k");
  println("ok");
}
void amazon(){
  port.write("a");
  println("amazon");
}

void netflix(){
  port.write("n");
  println("netflix");
}
void hulu(){
  port.write("h");
  println("hulu");
}

void disney(){
  port.write("p");
  println("disney");
}
void home(){
  port.write("o");
  println("home");
}
