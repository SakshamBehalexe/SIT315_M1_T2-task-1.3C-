


const int pirPin = 2;    // PIR sensor pin
const uint8_t BTN_PIN = 3; //button  pin

// Set the button previous state to low
uint8_t buttonPrevState = LOW;


volatile boolean pirState = false;    // PIR sensor state (motion detected or not)
volatile unsigned long pirTime = 0;   // Time of last PIR sensor trigger

void setup() {
  pinMode(13, OUTPUT);
  pinMode(pirPin, INPUT);   // Set PIR sensor pin as input
  pinMode(BTN_PIN , INPUT);
  attachInterrupt(digitalPinToInterrupt(pirPin), motionDetected, CHANGE);   // Attach interrupt on changing edge of PIR sensor output
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), buttonDetected, CHANGE);   // Attach interrupt on changing edge of PIR sensor output
  Serial.begin(9600);    // Start serial communication for debugging
}

void loop() {
  // Print PIR sensor state and time of last trigger
  Serial.print("PIR sensor state: ");
  Serial.println(pirState);
  Serial.print("Time of last trigger: ");
  Serial.println(pirTime);

  delay(1000);   // Wait 1 second before printing again
}

void motionDetected() {
  // Set PIR sensor state to true and record time of trigger
  if (pirState)
  {
    pirState = false;
    digitalWrite(13, LOW);
  }
  else
  {
  	pirState = true;
    digitalWrite(13, HIGH);
  }
  
  pirTime = millis();
}

void buttonDetected()
{
  if (buttonPrevState)
  {
    buttonPrevState = false;
    digitalWrite(13, LOW);
  }
  else
  {
  	buttonPrevState = true;
    digitalWrite(13, HIGH);
    Serial.println("Button Detected");
  }
}


