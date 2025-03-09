#pragma once

#include "Vec3.h"

class Plane {
public:
  Vec3 normal;
  Vec3 x_axis;
  Vec3 y_axis;
  Vec3 point;
  
  Plane(Vec3 normal_, Vec3 x_axis_, Vec3 y_axis_, Vec3 point_)
  : normal(normal_), x_axis(x_axis_), y_axis(y_axis_), point(point_)
  {}

  float a() { return normal.x; }
  float b() { return normal.y; }
  float c() { return normal.z; }
  float d() { return a() * point.x + b() * point.y + c() * point.z; }

  /* Create plane by direction and point
   * direction (da_, db_, dc_)
   * point (px_, py_, pz_)
   */
  // Plane(float da_, float db_, float dc_,
  //       float px_, float py_, float pz_)
  // : a(da_), b(db_), c(dc_),
  // d(da_ * px_ + db_ * py_ + dc_ * pz_)
  // {}

};
