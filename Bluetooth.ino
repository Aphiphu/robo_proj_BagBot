//**************************************************************************************************************************************************
// This procedure reads the serial port - Serial1 - for bluetooth commands being sent from the Android device

void bluetooth(){
while (Serial1.available())                  // Read bluetooth commands over Serial1 // Warning: If an error with Serial1 occurs, make sure Arduino Mega 2560 is Selected
{  
  {  
      str1 = Serial1.readString();           // str1 is the temporary variable for storing the last sring sent over bluetooth from Android device  
  }
      int index1 = str1.indexOf(",");
      int index2 = str1.indexOf(",",index1+1);
      //Serial.print("Str: ");    
      //Serial.println(str);

      str2 = str1.substring(0,index1);
      str1 = str1.substring(index1+1,index2);
      
      //Serial.print("Str1: ");    
      //Serial.println(str1);                    // for testing purposes
      
      //Serial.print("Str2: ");    
      //Serial.println(str2);                    // for testing purposes
  
      Phone_Lat = str1.toFloat();
      Phone_Lon = str2.toFloat();       
      Serial.print("Latitude: ");
      Serial.println(Phone_Lat,7);
           
      Serial.print("Longitude: ");
      Serial.println(Phone_Lon,7);                                          
 }
      if (Serial1.available() < 0)              // if an error occurs, confirm that the arduino mega board is selected in the Tools Menu
      {
      Serial1.println("No Bluetooth Data ");          
      }
} // end of bluetooth procedure
