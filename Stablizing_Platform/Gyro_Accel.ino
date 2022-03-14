#include<Wire.h>
#include <Servo.h>

// no calibration here, please help me find one

//Servo vairables
Servo MyServoRoll                                    // left right tilt
Servo My ServoPitch                                  // front back tilt
int Rollpos = 0;                                     // Store the position of the Roll Servo
int Pitchpos = 0;                                    // Store the position of the Pitch Servo

//MPU variables
const int MPU_addr1 = 0x68;
float xa, ya, za, roll, pitch;

void setup() {

  Wire.begin();                                      //begin the wire communication
  Wire.beginTransmission(MPU_addr1);                 //begin, send the slave adress (in this case 68)
  Wire.write(0x6B);                                  //make the reset (place a 0 into the 6B register)
  Wire.write(0);
  Wire.endTransmission(true);                        //end the transmission
  Serial.begin(9600);
}

void loop() {
  // https://forum.arduino.cc/t/mpu6050-pitch-and-roll-problem/679711/2
  Wire.beginTransmission(MPU_addr1);
  Wire.write(0x3B);  //send starting register address, accelerometer high byte
  Wire.endTransmission(false); //restart for read
  Wire.requestFrom(MPU_addr1, 6, true); //get six bytes accelerometer data
  int t = Wire.read();
  xa = (t << 8) | Wire.read();
  t = Wire.read();
  ya = (t << 8) | Wire.read();
  t = Wire.read();
  za = (t << 8) | Wire.read();

  roll = atan2(ya , za) * 180.0 / PI;
  pitch = atan2(-xa , sqrt(ya * ya + za * za)) * 180.0 / PI; //account for roll already applied

  Serial.print("roll = ");
  Serial.print(roll,1);
  Serial.print(", pitch = ");
  Serial.println(pitch,1);

  // forgot which side is longer that side should have lower prioity, the runtime should be super fast that is is unoticeable but just in case
  // Im assuming that the intial position is straight so at 90 deg but im not sure
  for (Rollpos; Rollpos < Roll; Rollpos += 1) { // goes from 90 degrees to roll degrees
    // in steps of 1 degree
    myservoRoll.write(Rollpos);              // tell servo to go to position in variable 'pos'
    delay(int(Roll/12));                          // waits xms for the servo to reach the position
  }
  for (Rollpos; Rollpos > Roll; Rollpos -= 1) { // goes from 90 degrees to roll degrees
    myservoRoll.write(Rollpos);              // tell servo to go to position in variable 'pos'
    delay(int(Roll/12));                          // waits xms for the servo to reach the position
  }
  
  for (Pitchpos; Pitchpos < Pitch; Pitchpos += 1) { // goes from 0 degrees to pitch degrees
    myservoPitch.write(Pitchpos);              // tell servo to go to position in variable 'pos'
    delay(int(Pitch/12));                          // waits xms for the servo to reach the position
  }
   for (Pitchpos; Pitchpos < Pitch; Pitchpos -= 1) { // goes from 0 degrees to pitch degrees
    myservoPitch.write(Pitchpos);              // tell servo to go to position in variable 'pos'
    delay(int(Pitch/12));                          // waits xms for the servo to reach the position
  }
}
