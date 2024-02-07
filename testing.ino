#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <SoftwareSerial.h>

SoftwareSerial BLUETOOTH(2, 3);
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  mpu.begin(0x69);

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  readMPU();
  delay(100);
}

void readMPU( ) {
  ////Read acceleromter data
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

//  Serial.print("Acceleration(");
//  Serial.print(a.acceleration.x);
//  Serial.print(", ");
//  Serial.print(a.acceleration.y);
//  Serial.print(", ");
//  Serial.print(a.acceleration.z);
//  Serial.print(") m/s^2|");
//  Serial.print("Rotation(");
//  Serial.print(g.gyro.x);
//  Serial.print(", ");
//  Serial.print(g.gyro.y);
//  Serial.print(", ");
//  Serial.print(g.gyro.z);
//  Serial.println(") rad/s");
}


