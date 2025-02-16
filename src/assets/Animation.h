#include <cstdint>
#pragma once

#include <vector>
#include <memory>

#include "Counter.h"

enum AnimationLoopType {
  StopAtLast,
  StopAtFirst,
  Loop
  // FrontBack
};

class Animation {
private:
  Counter _currentFrame;
  bool _playing;
public:
  const int width;
  const int height;
  std::vector<const uint8_t*> frames;
  AnimationLoopType animationLoopType;

  Animation(width_: int, height_: int,
            std::vector<const uint8_t*> frames_,
            AnimationLoopType animationLoopType_=AnimationLoopType::StopAtLast)
  : _playing(true),
  width(width_), height(height_),
  frames(frames_), animationLoopType(animationLoopType_)
  {
    _currentFrame = Counter(frames.size());
  }

  int getNumberOfFrames() { return frames.size(); }

  void play(bool playFromStart = true) {
    if (playFromStart) {
      _currentFrame.setValue(0);
    }
    _playing = true;
  }

  void stop() { _playing = false; }

  void update() {
    switch (animationLoopType) {
      case AnimationLoopType::StopAtLast:
        if (_playing) { 
          _currentFrame.increase();
        }
        if (_currentFrame.isMax()) {
          _playing = false;
        }
        break;
      case AnimationLoopType::StopAtFirst:
        if (_currentFrame.isMax()) {
          _playing = false;
          _currentFrame.setValue(0);
        } else if (_playing) {
          _currentFrame.increase();
        }
        break;
      case AnimationLoopType::Loop:
        if (_currentFrame.isMax()) {
          _currentFrame.setValue(0);
        } else if (_playing) {
          _currentFrame.increase();
        }
        break;
    }
  }

  const uint8_t* getCurrentFrame() {
    return frames[_currentFrame.getValue()];
  }


};