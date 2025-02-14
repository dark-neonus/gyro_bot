
#include <MPU9250_asukiaaa.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Vec2.h"
#include "Counter.h"
#include "face.h"
#include "menu_list.h"

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 21
#define SCL_PIN 22
#endif

#define LEFT_BUTTON_PIN 25
#define UP_BUTTON_PIN 33
#define DOWN_BUTTON_PIN 32
#define RIGHT_BUTTON_PIN 35

bool left_button_pressed = false;
bool up_button_pressed = false;
bool down_button_pressed = false;
bool right_button_pressed = false;

MPU9250_asukiaaa mySensor;
float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;

float dX_circle, dY_circle;


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Face face = Face(Vec2(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2));
SideList side_list = SideList({
  "meow1",
  "meow2",
  "meow3",
  "meow4",
  "meow5",
  "meow6",
  "Meowl",
  "!!!",
  "meoooow",
  "abc"
});
// Counter button_threshold = Counter(4, 0);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("started");

#ifdef _ESP32_HAL_I2C_H_ // For ESP32
  Wire.begin(SDA_PIN, SCL_PIN);
  mySensor.setWire(&Wire);
#endif

  mySensor.beginAccel();
  mySensor.beginGyro();
  mySensor.beginMag();

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();

  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(UP_BUTTON_PIN, INPUT);
  pinMode(DOWN_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);

  // You can set your own offset for mag values
  // mySensor.magXOffset = -50;
  // mySensor.magYOffset = -55;
  // mySensor.magZOffset = -10;
}

float angleX = 0, angleY = 0, angleZ = 0; // Store calculated angles
unsigned long lastTime = 0;

void loop() {
  uint8_t sensorId;
  int result;

  unsigned long currentTime = millis(); 
  float deltaTime = (currentTime - lastTime) / 1000.0; // Convert ms to seconds
  lastTime = currentTime;

  // Serial.println("\n\n\n\n\n");

  // result = mySensor.readId(&sensorId);
  // if (result == 0) {
  //   Serial.println("sensorId: " + String(sensorId));
  // } else {
  //   Serial.println("Cannot read sensorId " + String(result));
  // }

  result = mySensor.accelUpdate();
  if (result == 0) {
    aX = mySensor.accelX();
    aY = mySensor.accelY();
    aZ = mySensor.accelZ();
    aSqrt = mySensor.accelSqrt();
    Serial.println("accelX: " + String(aX));
    Serial.println("accelY: " + String(aY));
    Serial.println("accelZ: " + String(aZ));
    // Serial.println("accelSqrt: " + String(aSqrt));
  } else {
    Serial.println("Cannod read accel values " + String(result));
  }

  result = mySensor.gyroUpdate();
  if (result == 0) {
    gX = mySensor.gyroX();
    gY = mySensor.gyroY();
    gZ = mySensor.gyroZ();
    Serial.println("gyroX: " + String(gX));
    Serial.println("gyroY: " + String(gY));
    Serial.println("gyroZ: " + String(gZ));
  } else {
    Serial.println("Cannot read gyro values " + String(result));
  }

  result = mySensor.magUpdate();
  if (result != 0) {
    // Serial.println("cannot read mag so call begin again");
    // mySensor.beginMag();
    // result = mySensor.magUpdate();
  }
  if (result == 0) {
    mX = mySensor.magX();
    mY = mySensor.magY();
    mZ = mySensor.magZ();
    mDirection = mySensor.magHorizDirection();
    Serial.println("magX: " + String(mX));
    Serial.println("maxY: " + String(mY));
    Serial.println("magZ: " + String(mZ));
    Serial.println("horizontal direction: " + String(mDirection));
  } else {
    // Serial.println("Cannot read mag values " + String(result));
  }

  Serial.println("at " + String(millis()) + "ms");
  Serial.println(""); // Add an empty line

  angleX += gX * deltaTime;
  angleY += gY * deltaTime;
  angleZ += gZ * deltaTime;

  dX_circle = angleX / 2;
  dY_circle = angleY / 2;

  display.clearDisplay(); // Clear display buffer
  // display.drawCircle(display.width()/2 + dX_circle, display.height()/2 + dY_circle, 5, SSD1306_WHITE);
  face.draw(display, Vec2(gX * deltaTime, gY * deltaTime) / 2);
  side_list.draw(display, Vec2(0.0f, 0.0f));

  // if (button_threshold.getValue() == 0) {
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  if (digitalRead(LEFT_BUTTON_PIN) == HIGH) {
    display.setCursor(SCREEN_WIDTH - 4 * 7, 5);
    display.print("L");
    if (!left_button_pressed) {
      // side_list.selectPrevious();
    }
    // button_threshold.setValue(button_threshold.getMaxValue());
    left_button_pressed = true;
  } else {
    left_button_pressed = false;
  }
  if (digitalRead(UP_BUTTON_PIN) == HIGH) {
    display.setCursor(SCREEN_WIDTH - 3 * 7, 5);
    display.print("U");
    if (!up_button_pressed) {
      side_list.selectPrevious();
    }
    // button_threshold.setValue(button_threshold.getMaxValue());
    up_button_pressed = true;
  } else {
    up_button_pressed = false;
  }
  if (digitalRead(DOWN_BUTTON_PIN) == HIGH) {
    display.setCursor(SCREEN_WIDTH - 2 * 7, 5);
    display.print("D");
    if (!down_button_pressed) {
      side_list.selectNext();
    }
    // button_threshold.setValue(button_threshold.getMaxValue());
    down_button_pressed = true;
  } else {
    down_button_pressed = false;
  }
  if (digitalRead(RIGHT_BUTTON_PIN) == HIGH) {
    display.setCursor(SCREEN_WIDTH - 1 * 7, 5);
    display.print("R");
    if (!right_button_pressed) {
      // side_list.selectNext();
    }
    // button_threshold.setValue(button_threshold.getMaxValue());
    right_button_pressed = true;
  } else {
    right_button_pressed = false;
  }
  // }

  display.display();

  // Serial.println(side_list.getSelected().c_str());

  // button_threshold.decrease();
  
  delay(50);
}
