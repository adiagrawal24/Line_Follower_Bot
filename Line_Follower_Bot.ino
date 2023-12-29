// Define IR sensor pins
int IR1 = 8;   // Right sensor
int IR2 = 11;  // Left Sensor
int IR3 = 12;

// Define motor control pins for Motor A
int MotorAip1 = 2;
int MotorAip2 = 3;

// Define motor control pins for Motor B
int MotorBip1 = 4;
int MotorBip2 = 5;

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging
  
  // Set IR sensor pins as INPUT
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  
  // Set motor control pins as OUTPUT
  pinMode(MotorAip1, OUTPUT);
  pinMode(MotorAip2, OUTPUT);
  pinMode(MotorBip1, OUTPUT);
  pinMode(MotorBip2, OUTPUT);
}

void loop() {
  // Read the values from IR sensors
  int s1 = digitalRead(IR1);
  int s2 = digitalRead(IR2);
  int s3 = digitalRead(IR3);

  // Print the sensor values to Serial Monitor
  Serial.print(s1);
  Serial.print(s2);
  Serial.println(s3);
  
  // Check the sensor values and perform corresponding actions
  if (s1 == LOW && s2 == HIGH && s3 == LOW) {
    // Forward
    digitalWrite(MotorAip1, HIGH);
    digitalWrite(MotorAip2, LOW);
    digitalWrite(MotorBip1, HIGH);
    digitalWrite(MotorBip2, LOW);
    Serial.println("Forward");
  } else if (s1 == LOW && s2 == LOW && s3 == HIGH) {
    // Right
    digitalWrite(MotorAip1, HIGH);
    digitalWrite(MotorAip2, LOW);
    digitalWrite(MotorBip1, LOW);
    digitalWrite(MotorBip2, LOW);
    Serial.println("Right");
  } else if (s1 == HIGH && s2 == LOW && s3 == LOW) {
    // Left
    digitalWrite(MotorAip1, LOW);
    digitalWrite(MotorAip2, LOW);
    digitalWrite(MotorBip1, HIGH);
    digitalWrite(MotorBip2, LOW);
    Serial.println("Left");
  }
}
