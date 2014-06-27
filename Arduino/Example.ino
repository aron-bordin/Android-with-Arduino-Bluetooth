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