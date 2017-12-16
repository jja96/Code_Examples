//UART communication

//***DISCLAIMER***
//This code should compile, it won't actually work nor does it do anything specific
//This code just is a compliation of *most* of the UART commands for arduino
//Make sure you set up UART communication then run other serial commands
//all variables used are example variables

//Arduino UNO only has one serial connection, so if a USB is plugged in
//  and talking to the UNO, the Rx/Tx pins need to be clear
//THe Arduino MEGA has 3 extra Rx/Tx pins and can have 3 devices in addition
//  to a computer or 4 devices with no computer
//If more UART connections are needed lookup Software Serial on arduino
//  not recommended


//UART uses the TX and RX pins OR the USB port
//TX pin on device A connects to the RX pin on divice B
//TX pin on device B connects to the RX pin on divice A
//For the USB port just plug it in no extra connection is needed.

//UART uses no external clock
//Both devices must agree on the communication speed known as Baud rate
//Buad rate set up when making the serial connection
/* Common Baud rates
 *  300
 *  600
 *  1200
 *  2400
 *  4800
 *  9600  - Default/ Common
 *  14400
 *  19200
 *  28800
 *  38400
 *  57600
 *  115200 - Also Common
 */

 int arg1 = 1000;
 int arg2 = 9600;
 int arg3 = 1;
 
 int val1;
 int val2;
 int val3;
 int val4;

 byte byte1;

 float fval1;

 long lval1;
 long lval2;

 char char1 = ',';
 
 char string1[] = "example1";
 char string2[] = "example2";
 char string3[] = "example3";
 char string4[] = "example4";

 byte Buffer[5];
 int lengthOfBuffer = 5;

 byte Buffer2[5];
 int lengthOfBuffer2 = 5;

 bool bool1;
 bool bool2;

void setup() {
//Functions used to set up Serial Communiction
  if(Serial){
  //This is a boolean function if Serial is available it returns true
  }

  Serial.setTimeout(arg1);
  //This functions sets the # of milliseconds to wait for serial data
  //  Using serial.readBytesUnit() or serial.readBytes(), default is 1000

}

void loop() {
  Serial.begin(arg2);//initiate serial communication, will take baud rate or default to 9600



  val1 = Serial.available();//gets the number of bytes/characters available for reading from the 
  //  serial port data is stored in the serial buffer - 64 bytes


  val2 = Serial.availableForWrite();//gets the number of available bytes/characters for 
  //  writing in the Serial buffer without blocking the write operation


  
  bool1 = Serial.find(string1);//reads data from buffer until string is found

  bool2 = Serial.findUntil(string2,string3);//reads data from buffer until target string is found
  //  or terminating string is found



  Serial.flush();//waits for Serial data to finish streaming before continueing



  fval1 = Serial.parseFloat();//returns first valid float from serial buffer, non numbers except (-)
  //  are skipped, terminates by first character that is not float number
  // i.e a non float will not return garbage but will terminate returning 0

  lval1 = Serial.parseInt();//same as above but int instead of float


  val3 = Serial.peek();//returns next byte/character without removing it from the buffer if no data
  // returns -1



  //dividing the print into three parts
  Serial.print(78);// prints 78, alternatively can insert any variable containing a number
  //  float and double print to 2 decimal places so 3.2585 prints 3.25
  Serial.print("Hello");//prints Hello, alternatively can use a string or char variable

  //printing numbers
  Serial.print(78, BIN);//prints in binary "1001110"
  Serial.print(78, OCT);//prints in base 8, "116"
  Serial.print(78, DEC);//prints in base 10, "78"
  Serial.print(78, HEX);//prints in hexadecimal "4E"

  //printing to decimal places
  Serial.print(1.23456, 0);//prints "1"
  Serial.print(1.23456, 2);//prints "1.23"
  Serial.print(1.23456, 4);//prints "1.2345"
  //print also returns the number of bytes written, reading this number is optional
  //  as seen above as none of the prints are written to an int variable

  //print line
  Serial.println("example");//literally the same as print just appends a new line at the end



  byte1 = Serial.read();//reads a byte from buffer then removes it from buffer
  // the byte can be saved as any data type returns -1 if no data available

  val4 = Serial.readBytes(Buffer, lengthOfBuffer);//reads character from serial bffer into
  //  the char[] or byte[] buffer specified until the length given has been reached or there
  //  is a time out (see Serial.setTimeout() above)



  Serial.write(arg3);//sends out the number over serial communication
  Serial.write(string4);//sends out the string char by char over serial communication
  Serial.write(Buffer2, lengthOfBuffer2);//sends whatever is in the buffer over
  //  serial communication
  //  returns number of bytes written, optional to read though

}
