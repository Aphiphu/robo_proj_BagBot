#include "Wire.h"                                                 // Used by I2C and HMC5883L compass
#include "I2Cdev.h"                                               // I2C Communications Library (used for compass)
#include "HMC5883L.h"                                             // Library for the compass - Download from Github @ https://github.com/jarzebski/Arduino-HMC5883L
#include <Servo.h>                                                // Servo library to control Servo arm for metal detector
#include <SoftwareSerial.h>                                       // Software Serial for Serial Communications - not used
#include <TinyGPS++.h>                                            // Tiny GPS Plus Library - Download from http://arduiniana.org/libraries/tinygpsplus/
                                                                  // TinyGPS++ object uses Hardware Serial 2 and assumes that you have a
                                                                  // 9600-baud serial GPS device hooked up on pins 16(tx) and 17(rx).
                                                                     
// Gps Variables and Setup
int GPS_Course;                                                    // variable to hold the gps's determined course to destination
int Number_of_SATS=0;                                             // variable to hold the number of satellites acquired
TinyGPSPlus gps;  

// Compass Variables & Setup
HMC5883L compass;                                                  // HMC5883L compass(HMC5883L)
int16_t mx, my, mz;                                                // variables to store x,y,z axis from compass (HMC5883L)
int desired_heading;                                               // initialize variable - stores value for the new desired heading
int compass_heading;                                               // initialize variable - stores value calculated from compass readings
int compass_dev = 5;                                               // the amount of deviation that is allowed in the compass heading - Adjust as Needed
                                                                   // setting this variable too low will cause the robot to continuously pivot left and right
                                                                   // setting this variable too high will cause the robot to veer off course

int Heading_A;                                                     // variable to store compass heading
int Heading_B;                                                     // variable to store compass heading in Opposite direction
int pass = 0;                                                      // variable to store which pass the robot is on

// ping sensor
boolean pingOn = true;                                            // Turn Collision detection On or Off

int trigleftPin = 49;                                              // Trig - Choose any digital pin
int echoleftPin = 48;                                              // Echo - Choose any digital pin
int trigrightPin = 50;                                             // Trig - Choose any digital pin
int echorightPin = 51;                                             // Echo - Choose any digital pin
int trigfrontPin = 53;                                             // Trig - Choose any digital pin
int echofrontPin = 52;                                             // Echo - Choose any digital pin
long duration, cm;
int Ping_distance;

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;                                  // Store last time Ping was updated
const long interval = 200;                                         // Ping the Distance every X miliseconds

// Bluetooth Variables and Setup
String str1, str2;                                                 // raw string received from android to arduino
float Phone_Lat;                                                   // variable for storing the phone Latitude 
float Phone_Lon;                                                   // variable for storing the phone Longitude

// GPS Locations
unsigned long Distance_To_Phone;                                    // variable for storing the distance to destination

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  Serial.begin(115200);                                            // Serial 0 is for communication with the computer
  Serial1.begin(9600);                                             // Serial 1 is for Bluetooth communication - DO NOT MODIFY - JY-MCU HC-06 v1.40
  Serial2.begin(9600);                                             // Serial 2 is for GPS communication at 9600 baud - DO NOT MODIFY - Ublox Neo 6m 
  
  // Ping Sensor
  pinMode(trigleftPin, OUTPUT);                                        // Ping Sensor
  pinMode(echoleftPin, INPUT);                                         // Ping Sensor
  pinMode(trigrightPin, OUTPUT);                                       // Ping Sensor
  pinMode(echorightPin, INPUT);                                        // Ping Sensor
  pinMode(trigfrontPin, OUTPUT);                                        // Ping Sensor
  pinMode(echofrontPin, INPUT);                                         // Ping Sensor

  // Compass
  Wire.begin();                                                    // Join I2C bus used for the HMC5883L compass
  
  Startup();                                                       // Run the Startup procedure on power-up one time
}

void loop() 
{ 
  Serial.println("Main loop");
  //bluetooth();
  //getGPS();
  //getCompass();
  Serial.println("Ping start");
  Ping();
}  
