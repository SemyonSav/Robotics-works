#include <Servo.h>
#include <math.h>

const int SERVO_1_PIN = 4;
const int SERVO_2_PIN = 7;
const int angle1 = 45;
const int angle2 = 30;
const double l1 = 8.5;
const double l2 = 6.5;
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  servo1.attach(SERVO_1_PIN);
  servo2.attach(SERVO_2_PIN);
  servo1.write(0);
  servo2.write(180);
  delay(5000);
  servo1.write(angle1);
  delay(5000);
  servo2.write(angle2);
  getCoords();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void getCoords() {
  double OE = sqrt(pow(l1, 2) + pow(l2, 2) - 2 * l1 * l2 * cos(angle2 * (PI / 180)));
  double angleEOX = (angle1 * (PI / 180)) - asin(l2 * sin(angle2 * (PI / 180)) / OE);

  double x = cos(angleEOX) * OE;
  double y = sin(angleEOX) * OE;

  Serial.println(x);
  Serial.println(y);
}
