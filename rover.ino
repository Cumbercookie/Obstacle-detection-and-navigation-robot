const int M1 = 12;
const int M2 = 3;
const int M1I1 = 11;
const int M1I2 = 10;
const int M2I3 = 2;
const int M2I4 = 4;
const int trigPin = 6;
const int echoPin = 5;
void setup()
{
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M1I1, OUTPUT);
  pinMode(M2I3, OUTPUT);
  pinMode(M1I2, OUTPUT);
  pinMode(M2I4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);     // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);      // Sets the echoPin as an INPUT
  Serial.begin(9600);           // Configure and start Serial Communication
  moveforward();
}

int readUltrasonic(){
  long duration;                // Variable for the duration of sound wave travel
  int distance;                 // Variable for the distance measurement
  
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
   // Speed of sound wave divided by 2 (go and back)
  distance = duration * 0.034 / 2;

  return distance;
}


void loop() {
  int distance;
  distance = readUltrasonic();
  if(distance<10){
    stop();
    turnleft();
    distance = readUltrasonic();
    if(distance<10){
      turnright();
      turnright();
      distance = readUltrasonic();
      if(distance<10){
        turnright();
      }
    }
    moveforward();
  }
}

void turnleft(){
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M1I1, LOW);
  digitalWrite(M2I3, HIGH);
  digitalWrite(M1I2, HIGH);
  digitalWrite(M2I4, LOW);
  delay(1000);
  stop();
}

void turnright(){
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M1I1, HIGH);
  digitalWrite(M2I3, LOW);
  digitalWrite(M1I2, LOW);
  digitalWrite(M2I4, HIGH);
  delay(1000);
  stop();
}

void moveforward(){
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M1I1, HIGH);
  digitalWrite(M2I3, HIGH);
  digitalWrite(M1I2, LOW);
  digitalWrite(M2I4, LOW);
}

void stop(){
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
}
