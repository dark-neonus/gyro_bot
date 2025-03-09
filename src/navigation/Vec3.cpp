#include "Plane.h"
#include "Vec3.h"
#include "../Vec2.h"

Vec2 Vec3::project_on_plane(Plane plane) {
  float k = (plane.d() - plane.a() * x - plane.b() * y - plane.c() * z) /
            (plane.a() * plane.a() + plane.b() * plane.b() + plane.c() * plane.c());
  float px = x + k * plane.a();
  float py = y + k * plane.b();
  float pz = z + k * plane.c();

  float result_x = plane.x_axis.x * px + plane.x_axis.y * py + plane.x_axis.z * pz;
  float result_y = plane.y_axis.x * px + plane.y_axis.y * py + plane.y_axis.z * pz;

  return Vec2(result_x, result_y);
}
