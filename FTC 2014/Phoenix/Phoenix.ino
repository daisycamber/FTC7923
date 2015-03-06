byte inputPin = A0;
byte modePin = A1;
byte relayPin = 10;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(inputPin, INPUT);
  pinMode(modePin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  pinMode(13, OUTPUT);
}

int last = 0;
unsigned long lastTime = 0;
void loop()
{
  // Check to see if there was a significant change in voltage
  // (meaning the NXT is alive and running it's program)
  Serial.println(analogRead(modePin));
  Serial.println(analogRead(inputPin));
  Serial.println();
  delay(100);
  if(analogRead(inputPin) > last + 50 || analogRead(inputPin) < last - 50)
  {
    // Reset the timer, since the NXT is alive still
    lastTime = millis();
    // Record the current voltage for change detection
    last = analogRead(inputPin);
  }
  
  digitalWrite(13,analogRead(inputPin) > 400);
  
  // If it's been more than 2 seconds since we have heard 
  // from the NXT
  if(millis() - lastTime > 2000)
  {
    // Check to make sure our service is enabled
    if(analogRead(modePin) > 400)
    {
      // Oh noes! The NXT is frozen and we are sure of it,
      // since our service is enabled. Restart!
      digitalWrite(relayPin, HIGH);
      delay(200);
      digitalWrite(relayPin, LOW);
      
      // Wait until our service says it's disabled.
      // This is an indication from the NXT that
      // we are back online. It will re-enable the
      // service shortly after. This is to make sure
      // that we don't just immediatley force the NXT
      // to restart again just because we haven't heard
      // from it still (because the program isn't even
      // running yet)!
      
      while(analogRead(modePin) > 400)
      {
        delay(1);
      }
      // Pretend everything is OK
      lastTime = millis();
    }
    else // If it isn't enabled, simply reset the timer.
    {
      // This will make it look like we received a message, 
      // even though we did not.
      lastTime = millis();
    }
  }
  
}
