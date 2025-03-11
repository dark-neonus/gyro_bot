#pragma once
#ifndef COORDINATE_SYSTEM_H_
#define COORDINATE_SYSTEM_H_

#include "Vec3.h"
// #include "Plane.h"
// #include "Vec3.h"
// class Vec3;

class CoordinateSystem {
public:
  Vec3 x_axis;
  Vec3 y_axis;
  Vec3 z_axis;
  Vec3 origin;

  // CoordinateSystem() {}
  CoordinateSystem(Vec3 x_axis_, Vec3 y_axis_, Vec3 z_axis_, Vec3 origin_=Vec3(0.0f, 0.0f, 0.0f));

  // Set new Z and X axis and calculate Y axis
  void setXZ(Vec3 new_x_axis, Vec3 new_z_axis);

  Vec3 local_to_global(const Vec3& local_point);
};

#endif