Android with Arduino - Bluetooth
================================

Arduino and Android classes to easily connect your mobile device with an Arduino board.
With the example bellow, we can send a message to Android using Arduino.
Read more here: http://bytedebugger.wordpress.com/2014/06/27/tutorial-how-to-connect-an-android-device-with-arduino-and-bluetooth/

I had tested this lib with BC417 module, but I believe that this class works with major part of modules, because all of them use the same protocol. If you test other module, working or not, please, just start a new issue here to help me. If you have any problem, start an issue here too that I will try to help you.


Android Example (Using Processing)
==================================

		import com.aronbordin.*;

		/*make sure to use the same name of the robot. 
		And check if it's paired with your device */
		BluetoothArduino mBlue = BluetoothArduino.getInstance("ExampleRobot");

		void setup(){
		  mBlue.Connect();  
		  textSize(30);
		}

		void draw(){
		  background(0);
		  String msg = mBlue.getLastMessage();
		  text(msg, 100, 100);  
		  
		}

Arduino Example
===============

		#include <SoftwareSerial.h>
		#include "bluetooth.h"

		Bluetooth *blue = new Bluetooth("ExampleRobot");


		void setup(){
			Serial.begin(9600);
			blue->setupBluetooth();	
		}


		void loop(){
			String msg = blue->Read();
			if(msg.length() > 1){
				Serial.print("Received: ");
				Serial.println(msg);
			}
			if(Serial.available()){

				blue->Send("Example message#");
			}
		}


Arduino class reference
=======================

**int getrxPin();**
Get the RX Pin

**void setrxPin(int rx);**
Set the RX Pin

**int gettxPin();**
Get the TX Pin

**void settxPin(int tx);**
Set the TX Pin

**void setupBluetooth();**
Run it on setup(). It will configure all bluetooth prefenreces for you. 
After run it, you cannot change any settings of your bluetooth, like pin, or name

**Bluetooth(char name[]);**
Create a Bluetooth object with the name

**Bluetooth(char name[], int r, int t);**
Create a Bluetooth object with the name and pins

**String Read();**
Read char by char the data receive

**void Send(char c[]);**
Send a string to any connected deive

**char *getName();**
Get the device name

**void setName(char c[]);**
Set the device name


Android class reference
=======================
Important!
This class will read char by char until get the delimiter char(a char that represents the end of the string). 
By default is '#', but you can chage it with setDelimiter(char d);

**BluetoothArduino getInstance(String n);**
Get/Create a Bluetooth instance with the robot name. The name provided will be used in the connection

**boolean isBluetoothEnabled();**
Check if the device bluetooth is enabled

**boolean Connect();**
Connect to the Arduino board.

**boolean hasMensagem(int i);**
Check if had already received a message

**String getMenssage(int i);**
Get the Message by ID

**void clearMessages();**
Clear all messages

**int countMessages();**
Count messages

**String getLastMessage();**
Get the last message received

**void SendMessage(String msg);**
Send a message to the Arduino

**char getDelimiter();**
Get the end message character

**void setDelimiter(char d);**
Set the end message character
