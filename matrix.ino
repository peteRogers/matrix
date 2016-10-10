


#include "adafruit-led-backpack.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();
String testString = "YOUR MESSAGE HERE";

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address
  Particle.function("writeText",writeText);
  matrix.setTextColor(LED_GREEN);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextSize(1);

}



void loop() {
  matrix.clear();

  int len = testString.length();
  for (int x=7; x>=-(len*6); x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(testString.c_str());
    matrix.writeDisplay();
    delay(50);
  }


}

int writeText(String command) {
  Serial.println(command);
  if(command.equals("red")){
    matrix.setTextColor(LED_RED);
  }else if(command.equals("green")){
    matrix.setTextColor(LED_GREEN);
  }else{
    testString = command;
    //myText = command;
  }


}
