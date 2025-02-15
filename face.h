#pragma once

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "src/Vec2.h"
#include "src/ScreenObject.h"

class Pupil : public ScreenObject {
public:
  int w;
  int h;
  Pupil(Vec2 pos_, int w_, int h_, Vec2 pivot_ = Vec2(0.0f, 0.0f))
  : ScreenObject(pos_, pivot_), w(w_), h(h_)
  {}
};

class Eye : public ScreenObject {
public:
  int w;
  int h;
  Pupil pupil;
  Eye(Vec2 pos_, int w_, int h_, Vec2 pivot_ = Vec2(0.0f, 0.0f))
  : ScreenObject(pos_, pivot_), w(w_), h(h_), pupil(pos, int(w / 4), int(h / 4), _pivot)
  {}

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    Vec2 eyePos = getPos() - Vec2(w / 2, h / 2) + dV;
    display.drawRoundRect(eyePos.x, eyePos.y, w, h, int(w / 2), SSD1306_WHITE);
    Vec2 pupilPos = pupil.getPos() - Vec2(pupil.w / 2, pupil.h / 2) + dV;
    display.fillRoundRect(pupilPos.x, pupilPos.y, pupil.w, pupil.h, int(pupil.w / 2), SSD1306_WHITE);
  }
};


class Face : ScreenObject {
public:
  Eye leftEye;
  Eye rightEye;

  static constexpr int eyeWidth = 20;
  static constexpr int eyeHeight = 40;

  Face(Vec2 pos_)
  : ScreenObject(pos_),
    leftEye(Vec2(-20.0f, 0.0f), eyeWidth, eyeHeight),
    rightEye(Vec2(20.0f, 0.0f), eyeWidth, eyeHeight)
  {}

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    leftEye.draw(display, pos + dV);
    rightEye.draw(display, pos + dV);
  }
};