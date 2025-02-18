#pragma once

#include <vector>
#include <string>
#include <memory>

#include "Counter.h"

enum AnimationLoopType {
  StopAtLast,
  StopAtFirst,
  Loop,
  Reverse
};

class Animation {
private:
  Counter _currentFrame;
  Counter _loopDelay;
  bool _playing;
public:
  const int width;
  const int height;
  const std::string name;
  std::vector<const uint8_t*> frames;
  AnimationLoopType animationLoopType;

  Animation(std::string name_,
            int width_, int height_,
            std::vector<const uint8_t*> frames_,
            AnimationLoopType animationLoopType_=AnimationLoopType::StopAtLast)
  : _playing(true),
  width(width_), height(height_),
  name(name_),
  frames(frames_), animationLoopType(animationLoopType_)
  {
    _currentFrame = Counter(frames.size() - 1);
    _loopDelay = Counter(0);
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
          if (_loopDelay.isZero()) {
            _currentFrame.setValue(0);
            _loopDelay.setValue(_loopDelay.getMaxValue());
          } else {
            _loopDelay.decrease();
          }
        } else if (_playing) {
          _currentFrame.increase();
        }
        break;
      case AnimationLoopType::Reverse:
        if (_currentFrame.isZero()) {
          if (_loopDelay.isZero()) {
            _currentFrame.setValue(_currentFrame.getMaxValue());
            _loopDelay.setValue(_loopDelay.getMaxValue());
          } else {
            _loopDelay.decrease();
          }
        } else if (_playing) {
          _currentFrame.decrease();
        }
        break;
    }
  }

  const uint8_t* getCurrentFrame() {
    return frames[_currentFrame.getValue()];
  }

  void setLoopDelay(int value) {
    _loopDelay.setMaxValue(value);
  }

};