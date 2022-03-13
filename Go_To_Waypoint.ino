void Go_To_Waypoint()
{   
 Serial1.println("Go to Waypoint");
//Serial.print("Phone_Lat ");
//Serial.print(Phone_LAT,6);
//Serial.print(" ");
//Serial.println(Phone_LON,6);   

//Serial1.print("Distance to Phone");   
//Serial1.print(Distance_To_Phone);

 while (true)  
  {                                                                // Start of Go_To_Phone procedure 
  bluetooth();                                                     // Run the Bluetooth procedure to see if there is any data being sent via BT
  Ping();                                                           // If an obstacle is detected then break from the Loop
  getCompass();                                                    // Update Compass heading                                          
  getGPS();                                                        // Tiny GPS function that retrieves GPS data - update GPS location// delay time changed from 100 to 10
  
  if (millis() > 5000 && gps.charsProcessed() < 10)                // If no Data from GPS within 5 seconds then send error
    Serial1.println(F("No GPS data: check wiring"));     
 
  Distance_To_Phone = TinyGPSPlus::distanceBetween(gps.location.lat(),gps.location.lng(),Phone_Lat, Phone_Lon);  //Query Tiny GPS for Distance to Destination
  GPS_Course = TinyGPSPlus::courseTo(gps.location.lat(),gps.location.lng(),Phone_Lat,Phone_Lon);                 //Query Tiny GPS for Course to Destination   
 
    if (Distance_To_Phone == 0)                                   // If the Vehicle has reached it's Destination, then Stop
        {
        //StopCar();                                               // Stop the robot 
        Serial1.println("You have arrived!");                    // Print to Bluetooth device - "You have arrived"          
        break;                                                   // Break from Go_Home procedure and send control back to the Void Loop 
        }  
         
   if (abs(GPS_Course - compass_heading) <= 15)                  // If GPS Course and the Compass Heading are within x degrees of each other then go Forward                                                                  
                                                                 // otherwise find the shortest turn radius and turn left or right  
       {
         //Forward();                                               // Go Forward
       } else 
         {                                                       
            int x = (GPS_Course - 360);                           // x = the GPS desired heading - 360
            int y = (compass_heading - (x));                      // y = the Compass heading - x
            int z = (y - 360);                                    // z = y - 360
  
            //if ((z <= 180) && (z >= 0))                           // if z is less than 180 and not a negative value then turn left otherwise turn right
                  //{ SlowLeftTurn();  }
             //else { SlowRightTurn(); }               
        } 
  }                                                              // End of While Loop  
}                                                                // End of Go_Home procedure
