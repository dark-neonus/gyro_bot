#include "render.h"

#include <cmath>
#include <algorithm>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "../Vec2.h"

#include "Vec3.h"

#include "3d_fire.h"

// Custom linear interpolation function
inline float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

CoordinateSystem u3D::gyro_coordinates = CoordinateSystem(
  Vec3(1.0f, 0.0f, 0.0f),
  Vec3(0.0f, 1.0f, 0.0f),
  Vec3(0.0f, 0.0f, 1.0f)
);

void u3D::update_gyro_coordinates(float aX, float aY, float aZ, float rX, float rY, float rZ) {
  gyro_coordinates.z_axis = Vec3(aY, aX, aZ);

  gyro_coordinates.x_axis = Vec3::get_perpendicular(
    gyro_coordinates.z_axis,
    ((VIRTUAL_Z_AXIS - gyro_coordinates.z_axis).length() < 0.2f) ? VIRTUAL_X_AXIS : VIRTUAL_Z_AXIS
  );

  gyro_coordinates.x_axis = Vec3::rotateAroundAxis(gyro_coordinates.x_axis, gyro_coordinates.z_axis, rZ * M_PI / 180);
  
  gyro_coordinates.y_axis = Vec3::get_perpendicular(
    gyro_coordinates.z_axis,
    gyro_coordinates.x_axis
  );
}

Plane camera = Plane(
  Vec3(1.0f, 0.0f, 0.0f), // Normal
  Vec3(0.0f, 1.0f, 0.0f), // X Axis
  Vec3(0.0f, 0.0f, 1.0f), // Y Axis
  Vec3(-30.0f, 0.0f, 0.0f) // Points
);

Vec3 old_p2 = Vec3(0.0f, 0.0f, 0.0f);
float ball_inertion = 0.7f;

void test_render(Adafruit_SSD1306& display, Vec2 dV, float aX, float aY, float aZ) {
  Vec3 p1 = Vec3(0.0f, 0.0f, 0.0f);
  
  Vec3 p2 = Vec3(lerp(aY * 20.0f, old_p2.x, ball_inertion),
                  lerp(-aX * 20.0f, old_p2.y, ball_inertion),
                  lerp(-aZ * 20.0f, old_p2.z, ball_inertion));
  old_p2 = p2;

  Vec2 pp1 = project_on_plane(p1, camera) + dV;
  Vec2 pp2 = project_on_plane(p2, camera) + dV;

  display.drawLine(pp1.x, pp1.y, pp2.x, pp2.y, WHITE);
  display.drawCircle(pp2.x, pp2.y, 60 / (30 - abs(p2.x - camera.point.x) / 2), WHITE);
}

int axis_len = 28;

void render_axis(Adafruit_SSD1306& display, Vec2 dV, float aX, float aY, float aZ) {
  Vec2 ppO = project_on_plane(VIRTUAL_O_CENTER, camera) + dV;
  Vec2 ppX = project_on_plane(u3D::gyro_coordinates.x_axis * axis_len, camera) + dV;
  Vec2 ppY = project_on_plane(u3D::gyro_coordinates.y_axis * axis_len, camera) + dV;
  Vec2 ppZ = project_on_plane(u3D::gyro_coordinates.z_axis * axis_len, camera) + dV;

  display.drawLine(ppO.x, ppO.y, ppX.x, ppX.y, WHITE);
  display.setCursor(ppX.x, ppX.y);
  display.print("x");
  display.drawLine(ppO.x, ppO.y, ppY.x, ppY.y, WHITE);
  display.setCursor(ppY.x, ppY.y);
  display.print("y");
  display.drawLine(ppO.x, ppO.y, ppZ.x, ppZ.y, WHITE);
  display.setCursor(ppZ.x, ppZ.y);
  display.print("z");
}
