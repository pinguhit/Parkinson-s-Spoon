Parkinson's Tremor Detection Spoon
==================================

Overview:
---------
This is a simple Arduino project that detects hand tremors (like those in Parkinson's disease) using an MPU6050 accelerometer and responds with a servo motor. The servo moves slightly according to tremor intensity to mimic spoon stabilization.

Note: This is for educational purposes only and is NOT a medical device.

Components:
-----------
- Arduino Uno (or compatible board)
- MPU6050 accelerometer
- Servo motor (SG90 recommended)
- Jumper wires
- Breadboard (optional)

Wiring:
-------
MPU6050 VCC  -> 5V
MPU6050 GND  -> GND
MPU6050 SDA  -> A4
MPU6050 SCL  -> A5
Servo signal -> D9
Servo VCC    -> 5V
Servo GND    -> GND

How It Works:
-------------
1. MPU6050 measures acceleration in X, Y, Z axes.
2. Tremor intensity is calculated as the combined X and Y acceleration.
3. A smoothing filter stabilizes readings.
4. Servo angle changes with tremor intensity (70°–110°).
5. Tremor level is printed on Serial Monitor for debugging.
