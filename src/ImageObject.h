#pragma once

#include <memory>

#include "ScreenObject.h"




class ImageObject : public ScreenObject {
private:

public:

  ImageObject(Vec2 pos_, int w_, int h_, Vec2 pivot_ = Vec2(0.0f, 0.0f))
  : ScreenObject(pos_, pivot_), w(w_), h(h_)
  {}


};