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
#include "src/assets/eyes/anim_tired_1_eyes.h"
#include "src/assets/eyes/anim_tired_2_eyes.h"
#include "src/assets/eyes/anim_dizzy_eyes.h"
#include "src/assets/eyes/anim_dead_eyes.h"
#include "src/assets/eyes/anim_happy_eyes.h"

#include "src/assets/mouth/anim_normal_mouth.h"
#include "src/assets/mouth/anim_heart_mouth.h"
#include "src/assets/mouth/anim_tension_mouth.h"
#include "src/assets/mouth/anim_dizzy_mouth.h"
#include "src/assets/mouth/anim_tired_mouth.h"
#include "src/assets/mouth/anim_dead_mouth.h"
#include "src/assets/mouth/anim_happy_mouth.h"



class Mouth : public ImageObject {
public:
  Mouth(Vec2 pos_, Vec2 pivot_=Vec2(0.0f, 0.0f))
  : ImageObject(pos_, pivot_)
  {
    addAnimation(std::make_shared<Animation>(*(animation_normal_mouth.get())));
    addAnimation(std::make_shared<Animation>(*(animation_heart_mouth.get())));
    addAnimation(std::make_shared<Animation>(*(animation_tension_mouth.get())));
    addAnimation(std::make_shared<Animation>(*(animation_tired_mouth.get())));
    addAnimation(std::make_shared<Animation>(*(animation_dizzy_mouth.get())));
    addAnimation(std::make_shared<Animation>(*(animation_dead_mouth.get())));
    addAnimation(std::make_shared<Animation>(*(animation_happy_mouth.get())));
    
    animations[animation_normal_mouth->name]->animationLoopType = AnimationLoopType::Loop;
    animations[animation_heart_mouth->name]->animationLoopType = AnimationLoopType::Reverse;
    animations[animation_tension_mouth->name]->animationLoopType = AnimationLoopType::Loop;
    animations[animation_tired_mouth->name]->animationLoopType = AnimationLoopType::StopAtFirst;
    animations[animation_dizzy_mouth->name]->animationLoopType = AnimationLoopType::FrontBack;
    animations[animation_dead_mouth->name]->animationLoopType = AnimationLoopType::StopAtFirst;
    animations[animation_happy_mouth->name]->animationLoopType = AnimationLoopType::StopAtFirst;

    animations[animation_dizzy_mouth->name]->setLoopDelay(4);


    selectAnimation(animation_normal_mouth->name);
    // tmp_bla += 7;
  }

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    Vec2 eyePos = getPos() + dV - Vec2(getCurrentW(), getCurrentH()) / 2;
    display.drawBitmap(eyePos.x, eyePos.y, getCurrentFrame(), getCurrentW(), getCurrentH(), SSD1306_WHITE);
  }
};

class Eye : public ImageObject {
public:
  Eye(Vec2 pos_, Vec2 pivot_=Vec2(0.0f, 0.0f))
  : ImageObject(pos_, pivot_)
  {
    addAnimation(std::make_shared<Animation>(*(animation_normal_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_heart_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_tension_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_tired_1_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_tired_2_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_dizzy_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_dead_eyes.get())));
    addAnimation(std::make_shared<Animation>(*(animation_happy_eyes.get())));
    
    animations[animation_normal_eyes->name]->animationLoopType = AnimationLoopType::Loop;
    animations[animation_normal_eyes->name]->setLoopDelay(40);
    
    animations[animation_heart_eyes->name]->animationLoopType = AnimationLoopType::Loop;
    
    animations[animation_tension_eyes->name]->animationLoopType = AnimationLoopType::StopAtFirst;

    animations[animation_tired_1_eyes->name]->animationLoopType = AnimationLoopType::Loop;
    animations[animation_tired_1_eyes->name]->setLoopDelay(40);

    animations[animation_tired_2_eyes->name]->animationLoopType = AnimationLoopType::Loop;
    animations[animation_tired_2_eyes->name]->setLoopDelay(40);

    animations[animation_dizzy_eyes->name]->animationLoopType = AnimationLoopType::Loop;

    animations[animation_dead_eyes->name]->animationLoopType = AnimationLoopType::StopAtFirst;
    animations[animation_happy_eyes->name]->animationLoopType = AnimationLoopType::StopAtFirst;

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
  Mouth mouth;

  Face(Vec2 pos_)
  : ScreenObject(pos_),
    leftEye(Vec2(-20.0f, 0.0f)),
    rightEye(Vec2(20.0f, 0.0f)),
    mouth(Vec2(0.0f, 20.0f))
  {
    rightEye.animations[animation_dizzy_eyes->name]->animationLoopType = AnimationLoopType::Reverse;
    rightEye.animations[animation_tension_eyes->name]->animationLoopType = AnimationLoopType::StopAtLast;
  }

  void select_state_animation() {
    switch (Settings::bot_state) {
    case BotState::NORMAL:
      leftEye.selectAnimation(animation_normal_eyes->name);  
      rightEye.selectAnimation(animation_normal_eyes->name);
      mouth.selectAnimation(animation_normal_mouth->name);
      break;
    case BotState::LOVE:
      leftEye.selectAnimation(animation_heart_eyes->name);  
      rightEye.selectAnimation(animation_heart_eyes->name);
      mouth.selectAnimation(animation_heart_mouth->name);
      break;
    case BotState::TENSION:
      leftEye.selectAnimation(animation_tension_eyes->name);  
      rightEye.selectAnimation(animation_tension_eyes->name);
      mouth.selectAnimation(animation_tension_mouth->name);
      break;
    case BotState::TIRED1:
      leftEye.selectAnimation(animation_tired_1_eyes->name);  
      rightEye.selectAnimation(animation_tired_1_eyes->name);
      mouth.selectAnimation(animation_tired_mouth->name);
      break;
    case BotState::TIRED2:
      leftEye.selectAnimation(animation_tired_2_eyes->name);  
      rightEye.selectAnimation(animation_tired_2_eyes->name);
      mouth.selectAnimation(animation_tired_mouth->name);
      break;
    case BotState::DIZZY:
      leftEye.selectAnimation(animation_dizzy_eyes->name);  
      rightEye.selectAnimation(animation_dizzy_eyes->name);
      mouth.selectAnimation(animation_dizzy_mouth->name);
      break;
    case BotState::DEAD:
      leftEye.selectAnimation(animation_dead_eyes->name);  
      rightEye.selectAnimation(animation_dead_eyes->name);
      mouth.selectAnimation(animation_dead_mouth->name);
      break;
    case BotState::HAPPY:
      leftEye.selectAnimation(animation_happy_eyes->name);  
      rightEye.selectAnimation(animation_happy_eyes->name);
      mouth.selectAnimation(animation_happy_mouth->name);
      break;
    }
  }

  void update() override {
    select_state_animation();
    leftEye.update();
    rightEye.update();
    mouth.update();
  }

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    leftEye.draw(display, pos + dV);
    rightEye.draw(display, pos + dV);
    mouth.draw(display, pos + dV);
  }
};



