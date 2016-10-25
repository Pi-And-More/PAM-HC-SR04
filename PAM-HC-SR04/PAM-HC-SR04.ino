////////////////////////////////////////////////////////////////////////////////////
//
//                               PI and more
//                  Arduino & HC-SR04 ultrasonic distance
//
// https://piandmore.wordpress.com/2016/10/04/arduino-hc-sr04-ultrasonic-distance/
//
////////////////////////////////////////////////////////////////////////////////////
//
// The HC-SR04 requires two pins, one to trigger a reading (TRIGGERPIN)
// and one to measure the distance (ECHOPIN)
//
#define TRIGGERPIN 13
#define ECHOPIN 12

void setup() {
  //
  // Intialize serial
  //
  Serial.begin (115200);
  //
  // The TRIGGERPIN will be an output
  //
  pinMode(TRIGGERPIN,OUTPUT);
  //
  // The ECHOPIN will be an input
  //
  pinMode(ECHOPIN,INPUT);
}

void loop() {
  //
  // The duration will contain the time in microseconds that the echo takes
  // to return. The distance will contain the distance in cms
  //
  long duration, distance;
  //
  // To tell the HC-SR04 to start a reading, we should put the TRIGGERPIN
  // high for 10 microseconds, so we pull it LOW, than HIGH for 10 microseconds
  // and LOW again. Immediately after we check how long the ECHOPIN is HIGH
  //
  digitalWrite(TRIGGERPIN,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGERPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERPIN,LOW);
  duration = pulseIn(ECHOPIN,HIGH);
  //
  // The distance travelled by the sound send out is duration divided by the
  // pace of sound which is 29.1 ms/cm. We divide by 29.1 to get the amount
  // of centimeters and we divide by two because the sound travel to the object
  // and back, so the distance to the object is half the distance traveled
  // by the sound.
  //
  distance = (duration/2)/29.1;
  if (distance>=200 || distance<=0){
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(100);
}

