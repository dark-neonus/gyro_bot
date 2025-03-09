#pragma once

#include <SPI.h>
#include <Wire.h>

#include <MPU9250_asukiaaa.h>

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 8
#define SCL_PIN 9
#endif

namespace mpu {
float aX;
float aY;
float aZ;
float accelMagnitude = 1.0f;
float gX;
float gY;
float gZ;
float mDirection;
float mX;
float mY;
float mZ;

}

MPU9250_asukiaaa mpuSensor;
// float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;
// float accelMagnitude = 1.0f;

// float angleX = 0, angleY = 0, angleZ = 0;
unsigned long lastTime = 0;

void mpuSetup() {
  #ifdef _ESP32_HAL_I2C_H_ // For ESP32
    Wire.begin(SDA_PIN, SCL_PIN);
    mpuSensor.setWire(&Wire);
  #endif

  mpuSensor.beginAccel();
  mpuSensor.beginGyro();
  mpuSensor.beginMag();
}

float deltaTime = 0.0f;

void updateMPUData() {
  int result;

  unsigned long currentTime = millis(); 
  deltaTime = (currentTime - lastTime) / 1000.0; // Convert ms to seconds
  lastTime = currentTime;


  result = mpuSensor.accelUpdate();
  if (result == 0) {
    mpu::aX = mpuSensor.accelX();
    mpu::aY = mpuSensor.accelY();
    mpu::aZ = mpuSensor.accelZ();
    // aSqrt = mpuSensor.accelSqrt();
    mpu::accelMagnitude = mpuSensor.accelSqrt();
    // Serial.println("accelX: " + String(aX));
    // Serial.println("accelY: " + String(aY));
    // Serial.println("accelZ: " + String(aZ));
    // Serial.println("accelSqrt: " + String(aSqrt));
  } else {
    Serial.println("Cannod read accel values " + String(result));
  }

  result = mpuSensor.gyroUpdate();
  if (result == 0) {
    mpu::gX = mpuSensor.gyroX();
    mpu::gY = mpuSensor.gyroY();
    mpu::gZ = mpuSensor.gyroZ();
    // Serial.println("gyroX: " + String(gX));
    // Serial.println("gyroY: " + String(gY));
    // Serial.println("gyroZ: " + String(gZ));
  } else {
    Serial.println("Cannot read gyro values " + String(result));
  }

  // Serial.println("at " + String(millis()) + "ms");
  // Serial.println(""); // Add an empty line

  // angleX += mpu::gX * deltaTime;
  // angleY += mpu::gY * deltaTime;
  // angleZ += mpu::gZ * deltaTime;
}



