/**********************************************************************
 Arduino serial write and read with LabVIEW
 How to read a number from serial, do something in Arduino, 
 and write the result via Serial for LabVIEW
 author  Physics Light
 date    09 July 2014
 license Creative Commons 4.0 share alike 
************************************************************************/
long randNumber;
long readNumber = 1;
void setup() {
  // init serial port baud rate
  Serial.begin(9600);
  // generate different seed number if pin 0 is unconnected
  randomSeed(analogRead(0));
}
void loop() {
  // check serial 
  if ( Serial.available() ){
    // cast the string read in an integer 
    readNumber = Serial.parseInt();
  }
  // generate a random number from 0 to the number read 
  randNumber = random(readNumber);
  //write the result via Serial for LabVIEW
  Serial.println (randNumber);
  delay(250);
}
