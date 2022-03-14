# robo_proj_BagBot

## Ignore files that are not in a folder

All files should be in the relevant folder for easy use  
Comments should be good and clear enough, msg me on line for anything unclear but I should be there in person later.  

Ill include the folders in the zip folder, but the links on the comments is the same  
# Missing info
Read Gyro Accel ReadMEs file

### BagBot
setOffset we need to find those values  
from the calibrateCompass() in the GPS file. (i think)  
and if that doesnt work  
https://electropeak.com/learn/interfacing-gy-271-hmc5883l-compass-magnetometr-with-arduino/  
https://github.com/helscream/HMC5883L_Header_Arduino_Auto_calibration  
these should work

### Bluetooth File 
should be good  

### Gps file 
as mentioned the calibrateCompass should be run and Ill buy the hmc5833L at ban mor  

### Go_To_Waypoint 
should be good  

### Obstacle File
Okay so i have the front trig sensor coded, but not what it should do after it detects  
I believe connection is one left one right one front, but im not sure and it shouldnt be too long to write so I am leaving that to u  
sorry  

### Startup 
should be good  

### Steering file is empty 
// go left and go right should be to avoid the obstacle  
Include for the 4 dc motor controls  
go forward, go left, go right ,stop  
// not sure when is this gonna be used, so i dont think it is completely necessary   
backwards  
// these two are the small adjustments to turn angle to the robot faces the user  
go slightly right, go slightly left  

### Additonal Notes
Ignore the warning, I couldn't figure a way to remove the warning  

Anything goes wrong
### https://www.instructables.com/How-to-Build-a-GPS-Guided-Robot/










