//SPI communication

//***DISCLAIMER***
//This code should compile, it won't actually work nor does it do anything specific
//This code just is a compliation of *most* of the SPI commands for arduino

//SPI is a communication protocol used between electronic devices.
//One device is designated as the MASTER and ALL OTHER devices are designated as SLAVES
//communication is always between the MASTER and a SLAVE
//there is no SLAVE to SLAVE communication

//physical connections:
//MISO: MASTER in SLAVE out
//  All devices connect to this data line, and all connections are for the MISO pin even the master
//MOSI: MASTER out SLAVE in
//  All devices also connect to this data line, all connections includint the master are for the
//  mosi pin
//SCK or SCLK: clock
//  all divices connect to this line, the master is supplying a clock so everyone communicates
//  at the same speed
//SS: SLAVE SELECT
//  The Master has one SS pin per device, each SS line only goes from the MASTER to the SLAVE
//Arduino boards have 6 pin ICSP
//  THis has MISO, SCK, Vcc, MOSI, GND, and reset hardwired in
//additionally you can use the MISO,SCK, and MOSI digital I/O pins also designated for SPI

//SPI set up
//SPI communication has three settings:
//  1)Communication speed: the frequency devices can communicate, varies from device to device
//  2)How is data transmitted:
//    There are two ways Data is stored/transmitted
//      MOST SIGNIFIGANT BIT(MSB) or LEAST SIGNIFIGANT BIT(LSB)
//      arduino operates in LSB, most devices use MSB
//    This setting is for how the slave device operates, after recieving the data,
//      fix the data for arduino.(SEE FixingBitOrder.txt)
//  3)Clock mode: determined by clock polarity and clock pahse
//    Handy chart:
//    Mode        CLK Polarity    ClockPhase
//    SPI_MODE0   0               0
//    SPI_MODE1   0               1
//    SPI_MODE2   1               0
//    SPI_MODE3   1               1
//   
//  An example of the SPI setting, at 14MHZ, MSB, and SPI_MODE 0
//    SPISettings(14000000, MSBFITST, SPI_MODE0);


//**Typically open a SPI transaction when you need to communicate and close it when done**


// the next three variables are for when spi settings are variables instead of constants
int speedMaximum = 14000000;// data speed
byte dataOrder = LSBFIRST; // or MSBFIRST
byte dataMode = SPI_MODE0; // or one of the other modes above


byte in;
byte out = 'l';
int in2
int out2 = 3000;
char string[] = "hello";
int stringLen = 5;

void setup() {
  // put your setup code here, to run once:

  SpiSettings mySetting(speedMaximum, dataOrder, dataMode); //use this to set the spi settings
  //  if the settings might change throughout the code otherwise use SPI.beginTransaction();


  SPI.begin()// returns nothing, takes nothing
  //  initilizes SPI bus setting SCK, MOSI, and SS to outputs


}

void loop() {
  // put your main code here, to run repeatedly:

  //when you are ready to communicate, start your communicatioin
  SPI.beginTransaction(mySetting(14000000,MSBFIRST,SPI_MODE0));//if your parameters don't change
  //  this is how to setup spi
  //alternatly if parameters change initiate spi setings as above and then use the following
  SPI.beginTransaction(mySetting);
  

  //transfer() is for transfering one byte on SPI and you recieve a byte in return
  in = SPI.transfer(out);//Send out, in gets data written by the the return value

  //transfer16() is for two byte values such as int
  in2 = SPI.transfer16(out2);// sends out2, in2 gets the responce

  //transfering an array, assuming no data returned, otherwise use individual transfers
  SPI.transfer(string,strinLen)//sends the buffer/array using the buffer size


  //after you are finished communicating over SPI, free it up
  SPI.endTransaction()//Stops using the spi bus, no paramters, no returns


  SPI.end()//disables the SPI bus leaving pin modes unchanged, no paramters, no returns

}
