#include "CoordinateSystem.h"
#include "Vec3.h"

CoordinateSystem::CoordinateSystem(Vec3 x_axis_, Vec3 y_axis_, Vec3 z_axis_)
  : x_axis(x_axis_.normalize()), y_axis(y_axis_.normalize()), z_axis(z_axis_.normalize())
  {}

void CoordinateSystem::setXZ(Vec3 new_x_axis, Vec3 new_z_axis) {
  x_axis = new_x_axis.normalize();
  z_axis = new_z_axis.normalize();
  y_axis = Vec3::get_perpendicular(x_axis, z_axis);
}

