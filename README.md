# robo_proj_BagBot

All files should be in one folder for easy use
Comments should be good and clear enough, msg me on line for anything unclear but I should be there in person later.

Ill include the folders in the zip folder, but the links on the comments is the same
# Missing info
This does not have the gyroscope + accelerometer yet, but for that everything but the motor control I have (readings for x,y,z and yaw,roll,pitch)

Steering file is empty yes
Include for the 4 dc motor controls
go forward
go left
go right
stop
// not sure when is this gonna be used, so i dont think it is completely necessary 
backwards
// these two are the small adjustments to turn angle to the robot faces the user
go slightly right
go slightly left

Obstacle File
Okay so i have the front trig sensor coded, but not what it should do after it detects
I believe connection is one left one right one front, but im not sure and it shouldnt be too long to write so I am leaving that to u
sorry

BagBot
  Wire.begin();                                                    // Join I2C bus used for the HMC5883L compass
  compass.begin();                                                 // initialize the compass (HMC5883L)
  compass.setRange(HMC5883L_RANGE_1_3GA);                          // Set measurement range  
  compass.setMeasurementMode(HMC5883L_CONTINOUS);                  // Set measurement mode  
  compass.setDataRate(HMC5883L_DATARATE_30HZ);                     // Set data rate  
  compass.setSamples(HMC5883L_SAMPLES_8);                          // Set number of samples averaged  
  compass.setOffset(0,0);                                          // Set calibration offset 
  
I forgot to add this in, also for setOffset we need to find those values
from the calibrateCompass() in the GPS file.
uncomment the loop() and remove the serial.print please. that was for testing

Bluetooth File should be good

Gps file as mentioned the calibrateCompass should be run and Ill buy the hmc5833L at ban mor

Go_To_Waypoint should be good

Obstacle File
Okay so i have the front trig sensor coded, but not what it should do after it detects
I believe connection is one left one right one front, but im not sure and it shouldnt be too long to write so I am leaving that to u
sorry

Startup should be good

Steering file is empty yes
Include for the 4 dc motor controls
go forward
go left
go right
stop
// not sure when is this gonna be used, so i dont think it is completely necessary 
backwards
// these two are the small adjustments to turn angle to the robot faces the user
go slightly right
go slightly left


















For any randos who see this, this is copied and edited from many many uncredited sources. Dm me for the sources.
