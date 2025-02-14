#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Vec2.h"

class ScreenObject {
protected:
  Vec2 _pivot;

public:
  Vec2 pos;

  ScreenObject(Vec2 pos_, Vec2 pivot_ = Vec2(0.0f, 0.0f))
  : _pivot(pivot_), pos(pos_) 
  {}

  Vec2 getPos() { return _pivot + pos; }

  Vec2 getPivot() { return _pivot; }
  void setPivot(Vec2 value) { _pivot = value; }

  void virtual draw(Adafruit_SSD1306& display, Vec2 dV) {}
  void virtual update() {}

};