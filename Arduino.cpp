#include <Servo.h>

Servo servoX;  // Servo for X axis

void setup() {
  Serial.begin(115200);  
  servoX.attach(9);  # Servo gắn vào chân số 9 
}

void loop() {
  if (Serial.available() > 0) {
    int data = Serial.read();  // Read the incoming byte
    int servoPos = map(data, 0, 255, 0, 180);  // Map the received data (0-255) to the servo angle (0-180 degrees)
    servoX.write(servoPos);  // Move the servo to the mapped position
  }
}
