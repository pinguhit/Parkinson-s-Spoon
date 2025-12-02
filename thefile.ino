#include <Wire.h>
#include <Servo.h>

Servo servo;
const int servoPin = 9;

int16_t ax, ay, az;
long lastTime = 0;
float tremorLevel = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Start MPU6050
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); 
  Wire.write(0);    // wake up sensor
  Wire.endTransmission(true);

  servo.attach(servoPin);
  servo.write(90);  // neutral position
}

void loop() {
  // Read accelerometer raw values
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true);

  ax = (Wire.read() << 8 | Wire.read());
  ay = (Wire.read() << 8 | Wire.read());
  az = (Wire.read() << 8 | Wire.read());

  // Compute tremor level (simple |high-frequency acceleration|)
  float amplitude = abs(ax) + abs(ay);
  tremorLevel = 0.8 * tremorLevel + 0.2 * amplitude;  // smoothing filter

  // Map tremor intensity to servo movement
  int servoAngle = map(tremorLevel, 0, 30000, 70, 110);
  servoAngle = constrain(servoAngle, 70, 110);

  servo.write(servoAngle);

  Serial.print("Tremor Level: ");
  Serial.println(tremorLevel);
  delay(50);
}
