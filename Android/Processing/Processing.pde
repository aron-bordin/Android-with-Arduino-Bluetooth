import com.aronbordin.recuebicaro.*;

/*make sure to use the same name of the robot. 
And check if it's paired with your device */
BluetoothArduino mBlue = BluetoothArduino.getInstance("ExempleRobot");

void setup(){
  mBlue.Connect();  
}

void draw(){
  background(0);
  String msg = mBlue.getLastMessage();
  text(msg, 100, 100);  
  
}
