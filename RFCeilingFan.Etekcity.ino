//*****************************************************************************
/// @file
/// @brief
/// 433 mhz switch integration into SmartThings
/// Origial version for RCSwitch by keithcroshaw https://github.com/keithcroshaw/Arduino/blob/master/ST_RC_Switch_Rev4
/// Modify for ceiling fan to work with Smartthings & Arduino by tamttt@gmail.com
//*****************************************************************************
#include <SoftwareSerial.h>
#include <SmartThings.h>
#include <RCSwitch.h>

#define PIN_THING_RX    3
#define PIN_THING_TX    2

/*
#define RF_FAN1_OFF			1053804		//RF signal collected by RCSwitch & receiver 433 module
#define RF_FAN1_LOW			1053800
#define RF_FAN1_MEDIUM		1053794
#define RF_FAN1_HIGH		1053798
#define RF_FAN1_LIGHT		1053797

#define RF_FAN2_OFF			13625132
#define RF_FAN2_LOW			13625128
#define RF_FAN2_MEDIUM		13625122
#define RF_FAN2_HIGH		13625126
#define RF_FAN2_LIGHT		13625125

#define RF_FAN3_OFF			13645196
#define RF_FAN3_LOW			13645192
#define RF_FAN3_MEDIUM		13645186
#define RF_FAN3_HIGH		13645190
#define RF_FAN3_LIGHT		13645189

#define RF_FAN4_OFF			7088709
#define RF_FAN4_LOW			7088712
#define RF_FAN4_MEDIUM		7088706
#define RF_FAN4_HIGH		7088710
#define RF_FAN4_LIGHT		7088716
*/

RCSwitch mySwitch = RCSwitch();

SmartThingsCallout_t messageCallout;    // call out function forward decalaration
SmartThings smartthing(PIN_THING_RX, PIN_THING_TX, messageCallout);  // constructor

int ledPin = 13;
bool isDebugEnabled;    // enable or disable debug in this example
int stateLED;           // state to track last set value of LED

void setup()
{
  mySwitch.enableTransmit(12);
  mySwitch.setRepeatTransmit(10); // Optional set number of transmission repetitions.

  // setup default state of global variables
  //isDebugEnabled = true;
  //stateLED = 0;                 // matches state of hardware pin set below


  // setup hardware pins
  pinMode(ledPin, OUTPUT);     // define PIN_LED as an output
  digitalWrite(ledPin, LOW);   // set value to LOW (off) to match stateLED=0

 /*
  digitalWrite(ledPin, HIGH);  // turn LED on
  smartthing.shieldSetLED(0, 1, 0);

  digitalWrite(ledPin, LOW);   // turn LED off
  smartthing.shieldSetLED(0, 0, 0);
*/
  if (isDebugEnabled)
  { // setup debug serial port
    Serial.begin(9600);         // setup serial with a baud rate of 9600
    Serial.println("setup..");  // print out 'setup..' on start
  }
}

void loop()
{
  // run smartthing logic
  smartthing.run();
}

void fan1off()
{
  //mySwitch.send(1053804RF_FAN1_OFF, 24);  // living room fan off
  mySwitch.send(1053804, 24);				
  //smartthing.send("arduino turn fan 1 off");	// send message to cloud
  //Serial.println("fan 1 off");  
}

void fan1low()
{
  //mySwitch.send(RF_FAN1_LOW, 24);
  mySwitch.send(1053800, 24);
  //smartthing.send("arduino turn fan 1 low");
  //Serial.println("fan 1 low");  
}

void fan1medium()
{
  //mySwitch.send(RF_FAN1_MEDIUM, 24);
  mySwitch.send(1053794, 24);
  //smartthing.send("arduino turn fan 1 medium");
  //Serial.println("fan 1 medium");  
}

void fan1high()
{
  //mySwitch.send(RF_FAN1_HIGH, 24);
  mySwitch.send(1053798, 24);
  //smartthing.send("arduino turn fan 1 high");
  //Serial.println("fan 1 high");  
}

void fan1light()
{
  //mySwitch.send(RF_FAN1_LIGHT, 24);
  mySwitch.send(1053797, 24);
  //smartthing.send("arduino send light 1");
  //Serial.println("fan 1 light");
}

void fan2off()
{
  //mySwitch.send(RF_FAN2_OFF, 24);		// kitchen fan off
  mySwitch.send(13625132, 24);
  //smartthing.send("arduino turn fan 2 off");
  //Serial.println("fan 2 off");
}

void fan2low()
{
  //mySwitch.send(RF_FAN2_LOW, 24);
  mySwitch.send(13625128, 24);
  //smartthing.send("arduino turn fan 2 low");
  //Serial.println("fan 2 low");
}

void fan2medium()
{
  //mySwitch.send(RF_FAN2_MEDIUM, 24);
  mySwitch.send(13625122, 24);
  //smartthing.send("arduino turn fan 2 medium");
  //Serial.println("fan 2 medium");
}

void fan2high()
{
  //mySwitch.send(RF_FAN2_HIGH, 24);
  mySwitch.send(13625126, 24);
  //smartthing.send("arduino turn fan 2 high");
  //Serial.println("fan 2 high");
}

void fan2light()
{
  //mySwitch.send(RF_FAN2_LIGHT, 24);
  mySwitch.send(13625125, 24);
  //smartthing.send("arduino send light 2");
  //Serial.println("fan 2 light");
}

void fan3off()
{
  //mySwitch.send(RF_FAN3_OFF, 24);		// bedroom fan off
  mySwitch.send(13645196, 24);
  //smartthing.send("arduino turn fan 3 off");
  //Serial.println("fan 3 off");
}

void fan3low()
{
  //mySwitch.send(RF_FAN3_LOW, 24);
  mySwitch.send(13645192, 24);
  //smartthing.send("arduino turn fan 3 low");
  //Serial.println("fan 3 low");
}

void fan3medium()
{
  //mySwitch.send(RF_FAN3_MEDIUM, 24);
  mySwitch.send(13645186, 24);
  //smartthing.send("arduino turn fan 3 medium");
  //Serial.println("fan 3 medium");
}

void fan3high()
{
  //mySwitch.send(RF_FAN3_HIGH, 24);
  mySwitch.send(13645190, 24);
  //smartthing.send("arduino turn fan 3 high");
  //Serial.println("fan 3 high");
}

void fan3light()
{
  //mySwitch.send(RF_FAN3_LIGHT, 24);
  mySwitch.send(13645189, 24);
  //smartthing.send("arduino send light 3");
  //Serial.println("fan 3 light");
}

void fan4off()
{
  //mySwitch.send(RF_FAN4_OFF, 24);	// study room fan off	
  mySwitch.send(7088716, 24);
  //smartthing.send("arduino turn fan 4 off");	
  //Serial.println("fan 4 off");
}

void fan4low()
{
  //mySwitch.send(RF_FAN4_LOW, 24);
  mySwitch.send(7088712, 24);
  //smartthing.send("arduino turn fan 4 low");
  //Serial.println("fan 4 low");
}

void fan4medium()
{
  //mySwitch.send(RF_FAN4_MEDIUM, 24);
  mySwitch.send(7088706, 24);
  //smartthing.send("arduino turn fan 4 medium");
  //Serial.println("fan 4 medium");
}

void fan4high()
{
  //mySwitch.send(RF_FAN4_HIGH, 24);
  mySwitch.send(7088710, 24);
  //smartthing.send("arduino turn fan 4 high");
  //Serial.println("fan 4 high");
}

void fan4light()
{
  //mySwitch.send(RF_FAN4_LIGHT, 24);
  mySwitch.send(7088709, 24);
  //smartthing.send("arduino send light 4");
  //Serial.println("fan 4 light");
}


void switch1on()
{
    mySwitch.send(5511183, 24);
}

void switch1off()
{
    mySwitch.send(5511175, 24);
}

void switch2on()
{
    mySwitch.send(5511179, 24);
}

void switch2off()
{
    mySwitch.send(5511171, 24);
}

void switch3on()
{
    mySwitch.send(5511181, 24);
}

void switch3off()
{
    mySwitch.send(5511173, 24);
}

void switch4on()
{
    mySwitch.send(5511182, 24);
}

void switch4off()
{
    mySwitch.send(5511174, 24);
}

void ledOn() 
{
  digitalWrite(ledPin, HIGH);  // turn LED on
  smartthing.shieldSetLED(0, 1, 0);

  digitalWrite(ledPin, LOW);   // turn LED off
  smartthing.shieldSetLED(0, 0, 0);
}

void messageCallout(String message)
{
  // if debug is enabled print out the received message
  if (isDebugEnabled)
  {
    Serial.print("Received message: '");
    Serial.print(message);
    Serial.println("' ");
  }

  ledOn();

  if (message.equals("fan1off")) fan1off();
  if (message.equals("fan1low")) fan1low();
  if (message.equals("fan1medium")) fan1medium();
  if (message.equals("fan1high")) fan1high();
  if (message.equals("fan1light")) fan1light();

  if (message.equals("fan2off")) fan2off();
  if (message.equals("fan2low")) fan2low();
  if (message.equals("fan2medium")) fan2medium();
  if (message.equals("fan2high")) fan2high();
  if (message.equals("fan2light")) fan2light();

  if (message.equals("fan3off")) fan3off();
  if (message.equals("fan3low")) fan3low();
  if (message.equals("fan3medium")) fan3medium();
  if (message.equals("fan3high")) fan3high();
  if (message.equals("fan3light")) fan3light();
  
  if (message.equals("fan4off")) fan4off();
  if (message.equals("fan4low")) fan4low();
  if (message.equals("fan4medium")) fan4medium();
  if (message.equals("fan4high")) fan4high();
  if (message.equals("fan4light")) fan4light();

  // for RF switch
  if (message.equals("switch1on")) switch1on();
  if (message.equals("switch1on")) switch1off();

  if (message.equals("switch2on")) switch2on();
  if (message.equals("switch2on")) switch2off();
  
  if (message.equals("switch3on")) switch3on();
  if (message.equals("switch3on")) switch3off();
  
  if (message.equals("switch4on")) switch4on();
  if (message.equals("switch4on")) switch4off();

}



