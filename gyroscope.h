#pragma once

#include <SPI.h>
#include <Wire.h>

#include <MPU9250_asukiaaa.h>

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 8
#define SCL_PIN 9
#endif

MPU9250_asukiaaa gyroSensor;
float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;
float accelMagnitude = 1.0f;

float angleX = 0, angleY = 0, angleZ = 0;
unsigned long lastTime = 0;

void gyroSetup() {
  #ifdef _ESP32_HAL_I2C_H_ // For ESP32
    Wire.begin(SDA_PIN, SCL_PIN);
    gyroSensor.setWire(&Wire);
  #endif

  gyroSensor.beginAccel();
  gyroSensor.beginGyro();
  gyroSensor.beginMag();
}

float deltaTime = 0.0f;

void updateSensorData() {
  int result;

  unsigned long currentTime = millis(); 
  deltaTime = (currentTime - lastTime) / 1000.0; // Convert ms to seconds
  lastTime = currentTime;


  result = gyroSensor.accelUpdate();
  if (result == 0) {
    aX = gyroSensor.accelX();
    aY = gyroSensor.accelY();
    aZ = gyroSensor.accelZ();
    aSqrt = gyroSensor.accelSqrt();
    accelMagnitude = sqrt(aX * aX + aY * aY + aZ * aZ);
    // Serial.println("accelX: " + String(aX));
    // Serial.println("accelY: " + String(aY));
    // Serial.println("accelZ: " + String(aZ));
    // Serial.println("accelSqrt: " + String(aSqrt));
  } else {
    Serial.println("Cannod read accel values " + String(result));
  }

  result = gyroSensor.gyroUpdate();
  if (result == 0) {
    gX = gyroSensor.gyroX();
    gY = gyroSensor.gyroY();
    gZ = gyroSensor.gyroZ();
    // Serial.println("gyroX: " + String(gX));
    // Serial.println("gyroY: " + String(gY));
    // Serial.println("gyroZ: " + String(gZ));
  } else {
    Serial.println("Cannot read gyro values " + String(result));
  }

  // Serial.println("at " + String(millis()) + "ms");
  // Serial.println(""); // Add an empty line

  angleX += gX * deltaTime;
  angleY += gY * deltaTime;
  angleZ += gZ * deltaTime;
}



