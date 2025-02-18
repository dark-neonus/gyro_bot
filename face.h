#pragma once

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "src/Vec2.h"
#include "src/ScreenObject.h"
#include "src/Settings.h"
#include "src/MenuTree.h"
#include "src/ImageObject.h"

#include "src/assets/eyes/anim_normal_eyes.h"
#include "src/assets/eyes/anim_heart_eyes.h"
#include "src/assets/eyes/anim_tension_eyes.h"
#include "src/assets/eyes/anim_dizzy_eyes.h"

#include "src/assets/mouth/anim_normal_mouth.h"


// int tmp_bla = 10;

class Eye : public ImageObject {
public:
  Eye(Vec2 pos_, Vec2 pivot_=Vec2(0.0f, 0.0f))
  : ImageObject(pos_, pivot_)
  {
    addAnimation(std::make_shared<Animation>(*(animation_normal_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_heart_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_tension_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_dizzy_eyes.get())));
    
    animations[animation_normal_eyes->name]->animationLoopType = AnimationLoopType::Loop;
    animations[animation_normal_eyes->name]->setLoopDelay(40);
    
    animations[animation_heart_eyes->name]->animationLoopType = AnimationLoopType::Loop;
    
    animations[animation_tension_eyes->name]->animationLoopType = AnimationLoopType::Loop;

    animations[animation_dizzy_eyes->name]->animationLoopType = AnimationLoopType::Loop;

    selectAnimation(animation_normal_eyes->name);
    // tmp_bla += 7;
  }

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    Vec2 eyePos = getPos() + dV - Vec2(getCurrentW(), getCurrentH()) / 2;
    display.drawBitmap(eyePos.x, eyePos.y, getCurrentFrame(), getCurrentW(), getCurrentH(), SSD1306_WHITE);
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
    leftEye(Vec2(-20.0f, 0.0f)),
    rightEye(Vec2(20.0f, 0.0f))
  {
    rightEye.animations[animation_dizzy_eyes->name]->animationLoopType = AnimationLoopType::Reverse;
  }

  void select_state_animation() {
    switch (Settings::bot_state) {
    case BotState::NORMAL:
      leftEye.selectAnimation(animation_normal_eyes->name);  
      rightEye.selectAnimation(animation_normal_eyes->name);
      break;
    case BotState::LOVE:
      leftEye.selectAnimation(animation_heart_eyes->name);  
      rightEye.selectAnimation(animation_heart_eyes->name);
      break;
    case BotState::TENSION:
      leftEye.selectAnimation(animation_tension_eyes->name);  
      rightEye.selectAnimation(animation_tension_eyes->name);
      break;
    case BotState::DIZZY:
      leftEye.selectAnimation(animation_dizzy_eyes->name);  
      rightEye.selectAnimation(animation_dizzy_eyes->name);
      break;
    }
  }

  void update() override {
    select_state_animation();
    leftEye.update();
    rightEye.update();
  }

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    leftEye.draw(display, pos + dV);
    rightEye.draw(display, pos + dV);
  }
};



