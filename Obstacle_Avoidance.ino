void Ping()
{ 
  currentMillis = millis();
  
 if ((currentMillis - previousMillis >= interval) && (pingOn == true))  
 {
  previousMillis = currentMillis;
  digitalWrite(trigfrontPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigfrontPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigfrontPin, LOW);

  pinMode(echofrontPin, INPUT);
  duration = pulseIn(echofrontPin, HIGH);
  
  int cm = (duration/2)/29 ;                       // convert the time into a distance
  Ping_distance == cm;  
  Serial1.println(Ping_distance);
  
  if (Ping_distance < 10)
  {
    
  } // end if statement 
 }
}         // end Ping()

void pingToggle()                                         // Turns Collision avoidance on/ off
 {
  if (pingOn == true) {
    pingOn = false;
    Serial1.print("Collision Avoidance OFF");
  }
    else if (pingOn == false) {
    pingOn = true;
    Serial1.print("Collision Avoidance ON");
  }
  
 }
