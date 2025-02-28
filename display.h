#pragma once



#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "src/Settings.h"
#include "src/MenuTree.h"
#include "src/assets/logo.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displaySetup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.drawBitmap(
      (SCREEN_WIDTH - LOGO_WIDTH) / 2,  // X center
      (SCREEN_HEIGHT - LOGO_HEIGHT) / 2, // Y center
      logo_art, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE
  );

  display.display();

  delay(500);
}

const std::function<void(std::shared_ptr<MenuTree>)> enterDeepSleep = 
[](std::shared_ptr<MenuTree>) {
    display.clearDisplay();
    display.display();
    Settings::saveData();
    esp_deep_sleep_start();
};
