#include "Plane.h"
#include "../Vec2.h"
#include "Vec3.h"

// class Vec2;

Plane::Plane(Vec3 normal_, Vec3 x_axis_, Vec3 y_axis_, Vec3 point_)
  : normal(normal_), x_axis(x_axis_), y_axis(y_axis_), point(point_)
  {}

float Plane::a() { return normal.x; }
float Plane::b() { return normal.y; }
float Plane::c() { return normal.z; }
float Plane::d() { return a() * point.x + b() * point.y + c() * point.z; }

Vec2 project_on_plane(Vec3 v, Plane plane) {
  float k = (plane.d() - plane.a() * v.x - plane.b() * v.y - plane.c() * v.z) /
            (plane.a() * plane.a() + plane.b() * plane.b() + plane.c() * plane.c());
  float px = v.x + k * plane.a();
  float py = v.y + k * plane.b();
  float pz = v.z + k * plane.c();

  float result_x = plane.x_axis.x * px + plane.x_axis.y * py + plane.x_axis.z * pz;
  float result_y = plane.y_axis.x * px + plane.y_axis.y * py + plane.y_axis.z * pz;

  return Vec2(result_x, result_y);
}