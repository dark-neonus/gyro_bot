#pragma once

#ifndef PLANE_H_
#define PLANE_H_

#include "Vec3.h"
// #include "../Vec2.h"

class Vec2;
// class Vec3;

class Plane {
public:
  Vec3 normal;
  Vec3 x_axis;
  Vec3 y_axis;
  Vec3 point;
  
  Plane(Vec3 normal_, Vec3 x_axis_, Vec3 y_axis_, Vec3 point_);

  float a();
  float b();
  float c();
  float d();

  bool is_point_in_front(Vec3 p) {
    return normal.dot(p - point) > 0;  // True if point is in front
  }
};

Vec2 project_on_plane(Vec3 v, Plane plane);

#endif