#include "CoordinateSystem.h"
#include "Vec3.h"

CoordinateSystem::CoordinateSystem(Vec3 x_axis_, Vec3 y_axis_, Vec3 z_axis_, Vec3 origin_)
  : x_axis(x_axis_.normalize()), y_axis(y_axis_.normalize()), z_axis(z_axis_.normalize()), origin(origin_)
  {}

void CoordinateSystem::setXZ(Vec3 new_x_axis, Vec3 new_z_axis) {
  x_axis = new_x_axis.normalize();
  z_axis = new_z_axis.normalize();
  y_axis = Vec3::get_perpendicular(x_axis, z_axis);
}

Vec3 CoordinateSystem::local_to_global(const Vec3& local_point) {
    // Transform local point to global coordinates using basis vectors
    return origin + 
           x_axis * local_point.x +
           y_axis * local_point.y +
           z_axis * local_point.z;
}

