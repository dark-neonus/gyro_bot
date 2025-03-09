#pragma once

#include <vector>
#include <string>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "../ScreenObject.h"

class Console : ScreenObject {
public:
  int left_padding = 3;
  int char_height = 7;

  Console(Vec2 pos_)
  : ScreenObject(pos_)
  {}

  void draw(Adafruit_SSD1306& display, Vec2 dV, std::vector<std::string> content) {
    for (int y = 0; y < content.size(); y++) {
      display.setCursor(pos.x + left_padding + dV.x, pos.y + y * (char_height + 1) + dV.y);
      display.print(content[y].c_str());
    }
  }
};


