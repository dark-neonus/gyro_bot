#include "render.h"

#include <cmath>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "../Vec2.h"

#include "Vec3.h"
// #include "Plane.h"
// #include "CoordinateSystem.h"

// #include "mpu.h"

CoordinateSystem u3D::gyro_coordinates = CoordinateSystem(
  Vec3(1.0f, 0.0f, 0.0f),
  Vec3(0.0f, 1.0f, 0.0f),
  Vec3(0.0f, 0.0f, 1.0f)
);

void u3D::update_gyro_coordinates(float aX, float aY, float aZ) {
  Vec3 z_axis = Vec3(aY, -aX, aZ);
  // if ((Vec3()))
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
  
  // Vec3 p2 = Vec3(0.0f, 10.0f, 5.0f);
  Vec3 p2 = Vec3(std::lerp(aY * 20.0f, old_p2.x, ball_inertion),
                  std::lerp(-aX * 20.0f, old_p2.y, ball_inertion),
                  std::lerp(-aZ * 20.0f, old_p2.z, ball_inertion));
  old_p2 = p2;

  Vec2 pp1 = project_on_plane(p1, camera) + dV;
  Vec2 pp2 = project_on_plane(p2, camera) + dV;

  display.drawLine(pp1.x, pp1.y, pp2.x, pp2.y, WHITE);
  display.drawCircle(pp2.x, pp2.y, 60 / (30 - abs(p2.x - camera.point.x) / 2), WHITE);
}

