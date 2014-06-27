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
