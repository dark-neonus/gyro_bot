#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "ScreenObject.h"

#include "Animation.h"


class ImageObject : public ScreenObject {
private:
  std::shared_ptr<Animation> _current_animation;
public:
  std::unordered_map<std::string, std::shared_ptr<Animation>> animations;


  ImageObject(Vec2 pos_, Vec2 pivot_ = Vec2(0.0f, 0.0f))
  : ScreenObject(pos_, pivot_)
  {}

  void addAnimation(std::shared_ptr<Animation> animation) {
    animations[animation->name] = animation;
  }

  void selectAnimation(std::string name) {
    _current_animation = animations[name];
  }

  void update() override {
    if (_current_animation) {
      _current_animation->update();
    }
  }

  const uint8_t* getCurrentFrame() { return _current_animation->getCurrentFrame(); }

  int getCurrentW() { return _current_animation->width; }
  int getCurrentH() { return _current_animation->height; }

};