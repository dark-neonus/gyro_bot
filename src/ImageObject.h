#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "ScreenObject.h"

#include "Animation.h"


class ImageObject : public ScreenObject {
private:
  std::shared_ptr<Animation> _current_animation;
  bool _is_enabled;
public:
  std::unordered_map<std::string, std::shared_ptr<Animation>> animations;


  ImageObject(Vec2 pos_, Vec2 pivot_ = Vec2(0.0f, 0.0f))
  : ScreenObject(pos_, pivot_), _is_enabled(true)
  {}

  void addAnimation(std::shared_ptr<Animation> animation) {
    animations[animation->name] = animation;
  }

  void selectAnimation(std::string name) {
    _current_animation = animations[name];
  }

  void update() override {
    if (_current_animation && isEnabled()) {
      _current_animation->update();
    }
  }

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    if (isEnabled()) {
      Vec2 objPos = getPos() + dV - Vec2(getCurrentW(), getCurrentH()) / 2;
      display.drawBitmap(objPos.x, objPos.y, getCurrentFrame(), getCurrentW(), getCurrentH(), SSD1306_WHITE);
    }
  }

  const uint8_t* getCurrentFrame() { return _current_animation->getCurrentFrame(); }

  int getCurrentW() { return _current_animation->width; }
  int getCurrentH() { return _current_animation->height; }

  void enable() { _is_enabled = true; }
  void disable() { _is_enabled = false; }
  bool isEnabled() { return _is_enabled; }

};