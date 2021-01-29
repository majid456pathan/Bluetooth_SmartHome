

#define DEBOUNCE_TIME   70 //in millisec
int pbuttonPin1 = 4; // connect output to push button
int relayPin1 = 8;   // Connected to relay (LED)

bool PinState[4]= {
  0}; // push value from pin 2
int RelayON[4] = {
  0}; //Relay state variable, High means ON, Low Means Off

int pbuttonPin2 = 5;// connect output to push button 2
int relayPin2 = 9;// Connected to relay 2 (LED)

int pbuttonPin3 = 6;// connect output to push button
int relayPin3 = 10;// Connected to relay (LED)

int pbuttonPin4 = 7;// connect output to push button
int relayPin4 = 11;// Connected to relay (LED)


String readString;

void setup() {

  Serial.begin(9600);
  pinMode(pbuttonPin1, INPUT); 
  pinMode(relayPin1, OUTPUT);

  pinMode(pbuttonPin2, INPUT); 
  pinMode(relayPin2, OUTPUT);

  pinMode(pbuttonPin3, INPUT); 
  pinMode(relayPin3, OUTPUT);

  pinMode(pbuttonPin4, INPUT); 
  pinMode(relayPin4, OUTPUT);

}

void loop()
{
  while (Serial.available()) 
  {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }

  if (readString.length() >0) {
    Serial.println(readString);
    if (readString == "1 ON")     
    {
      /* Turn Relay ON and save its State */
      digitalWrite(relayPin1, LOW);
      RelayON[0] = HIGH;
    }
    else if (readString == "1 OFF")
    {
      /* Turn Relay OFF and save its State */

      digitalWrite(relayPin1, HIGH);
      RelayON[0] = LOW;

    }
    //relay2
    else if (readString == "2 ON")     
    {
      /* Turn Relay ON and save its State */
      digitalWrite(relayPin2, LOW);
      RelayON[1] = HIGH;
    }
    else  if (readString == "2 OFF")
    {
      /* Turn Relay OFF and save its State */
      digitalWrite(relayPin2, HIGH);
      RelayON[1] = LOW;

    }
    //relay3    
    else if (readString == "3 ON")     
    {
      /* Turn Relay ON and save its State */
      digitalWrite(relayPin3, LOW);
      RelayON[2] = HIGH;
    }
    else if (readString == "3 OFF")
    {
      /* Turn Relay OFF and save its State */
      digitalWrite(relayPin3, HIGH);
      RelayON[2] = LOW;

    }
    //relay4    
    else if (readString == "4 ON")     
    {
      /* Turn Relay ON and save its State */
      digitalWrite(relayPin4, LOW);
      RelayON[3] = HIGH;      
    }
    else if (readString == "4 OFF")
    {
      /* Turn Relay OFF and save its State */
      digitalWrite(relayPin4, HIGH);
      RelayON[3] = LOW;
    }
    else if (readString == "ALL ON")     
    {
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
      digitalWrite(relayPin4, LOW);

      RelayON[0] = HIGH;
      RelayON[1] = HIGH;
      RelayON[2] = HIGH;
      RelayON[3] = HIGH;
    }
    else if (readString == "ALL OFF")
    {
      digitalWrite(relayPin1, HIGH);
      digitalWrite(relayPin2, HIGH);
      digitalWrite(relayPin3, HIGH);
      digitalWrite(relayPin4, HIGH);

      RelayON[0] = LOW;
      RelayON[1] = LOW;
      RelayON[2] = LOW;
      RelayON[3] = LOW;
    }

    readString="";

  }

  // Get Pin s
  ReadPushButton();

  /************* Relay 1 ****************/
  if((PinState[0] == HIGH) && (RelayON[0] == HIGH))
  {
    /* Relay is ON Turn it Off and save its State */
    digitalWrite(relayPin1, HIGH);
    RelayON[0] = LOW;
  }
  else if((PinState[0] == HIGH) && (RelayON[0] == LOW))
  {
    /* Relay is OFF Turn it ON and save its State */
    digitalWrite(relayPin1, LOW);
    RelayON[0] = HIGH;
  }


  /************* Relay 2 ****************/
  if((PinState[1] == HIGH) && (RelayON[1] == HIGH))
  {
    /* Relay is ON Turn it Off and save its State */
    digitalWrite(relayPin2, HIGH);
    RelayON[1] = LOW;
  }
  else if((PinState[1] == HIGH) && (RelayON[1] == LOW))
  {
    /* Relay is OFF Turn it ON and save its State */
    digitalWrite(relayPin2, LOW);
    RelayON[1] = HIGH;
  }

  /************* Relay 3 ****************/
  if((PinState[2] == HIGH) && (RelayON[2] == HIGH))
  {
    /* Relay is ON Turn it Off and save its State */
    digitalWrite(relayPin3, HIGH);
    RelayON[2] = LOW;
  }
  else if((PinState[2] == HIGH) && (RelayON[2] == LOW))
  {
    /* Relay is OFF Turn it ON and save its State */
    digitalWrite(relayPin3, LOW);
    RelayON[2] = HIGH;
  }

  /************* Relay 4 ****************/
  if((PinState[3] == HIGH) && (RelayON[3] == HIGH))
  {
    /* Relay is ON Turn it Off and save its State */
    digitalWrite(relayPin4, HIGH);
    RelayON[3] = LOW;
  }
  else if((PinState[3] == HIGH) && (RelayON[3] == LOW))
  {
    /* Relay is OFF Turn it ON and save its State */
    digitalWrite(relayPin4, LOW);
    RelayON[3] = HIGH;
  }


  delay(100);
}



void ReadPushButton()
{
  /* Read In all 4 pins Status */
  PinState[0] = digitalRead(pbuttonPin1);
  PinState[1] = digitalRead(pbuttonPin2);
  PinState[2] = digitalRead(pbuttonPin3);
  PinState[3] = digitalRead(pbuttonPin4);

  if(PinState[0] || PinState[1] || PinState[2] || PinState[3])
  {
    /* If any of the pin returns High then apply debounce time */
    delay(DEBOUNCE_TIME); //Debounce time

    if(PinState[0] && !digitalRead(pbuttonPin1))
    {
      /* This pin was initially high but became low after debounce time,
       So its not a succesful button press n we clear it */
      PinState[0] = LOW;
    }
    if(PinState[1] && !digitalRead(pbuttonPin2))
    {
      /* This pin was initially high but became low after debounce time,
       So its not a succesful button press n we clear it */
      PinState[1] = LOW;
    }

    if(PinState[2] && !digitalRead(pbuttonPin3))
    {
      /* This pin was initially high but became low after debounce time,
       So its not a succesful button press n we clear it */
      PinState[2] = LOW;
    }

    if(PinState[3] && !digitalRead(pbuttonPin4))
    {
      /* This pin was initially high but became low after debounce time,
       So its not a succesful button press n we clear it */
      PinState[3] = LOW;
    }

  }

}
