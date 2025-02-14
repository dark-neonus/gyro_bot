
#pragma once

#include <vector>
#include <array>
#include <string>

#include <Adafruit_GFX.h>       // Core graphics library
#include <Adafruit_SSD1306.h>   // OLED library

#include "RangeValueInt.h"
#include "Vec2.h"
#include "ScreenObject.h"

class SideList : public ScreenObject {
private:
  std::vector<std::string> _items;
  RangeValueInt _selectedIndex;
public:
  static constexpr int FONT_SIZE = 1;
  static constexpr int LEFT_PADDING = 5;
  static constexpr int ELEMENT_PADDING = 10;

  SideList(std::vector<std::string> items_, int selectedIndex_=0, Vec2 pos_=Vec2(0.0f, 0.0f))
  : ScreenObject(pos_), _items(items_),
  _selectedIndex(selectedIndex_, 0, _items.size() - 1)
  {}

  void select(int index) { _selectedIndex.setValue(index); }
  void selectNext() { _selectedIndex.increase(); }
  void selectPrevious() { _selectedIndex.decrease(); }

  int getIndex() { return _selectedIndex.getValue(); }
  // std::string getAt(int index) { return _items[max(0, min(index, _items.size() - 1))]; }
  std::string getAt(int index) { return _items[index]; }
  std::string getSelected() { return getAt(_selectedIndex.getValue()); }

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    std::array<int, 5> visibleIndexes = {
      getIndex() - 2,
      getIndex() - 1,
      getIndex(),
      getIndex() + 1,
      getIndex() + 2
    };

    for (int i = 0; i < visibleIndexes.size(); i++) {
      if (0 <= visibleIndexes[i] && visibleIndexes[i] < _items.size()) {
        display.setCursor(LEFT_PADDING, ELEMENT_PADDING * (i + 1));
        // display.setTextSize(i == 2 ? 2 : 1);        // Set text size (1 = small, 2 = medium, etc.)
        display.setTextColor(WHITE);
        if (i == 2) {
          display.printf("> %s", getSelected().c_str());
        }
        else {
          display.print(_items[visibleIndexes[i]].c_str());
        }
      }
    }
  }

};
