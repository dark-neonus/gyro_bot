#pragma once

#include <cmath>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// #include "Vec3.h"
#include "Plane.h"
#include "CoordinateSystem.h"
#include "3d_fire.h"

// #include "src/Vec2.h"
// #include "mpu.h"

#define VIRTUAL_O_CENTER Vec3(0.0f, 0.0f, 0.0f)
#define VIRTUAL_X_AXIS Vec3(1.0f, 0.0f, 0.0f)
#define VIRTUAL_Y_AXIS Vec3(0.0f, 1.0f, 0.0f)
#define VIRTUAL_Z_AXIS Vec3(0.0f, 0.0f, 1.0f)

// utilities 3D
namespace u3D {
  extern CoordinateSystem gyro_coordinates;

  void update_gyro_coordinates(float aX, float aY, float aZ, float gX, float gY, float gZ);
};

extern Plane camera;

void test_render(Adafruit_SSD1306& display, Vec2 dV, float aX, float aY, float aZ);

void render_axis(Adafruit_SSD1306& display, Vec2 dV, float aX, float aY, float aZ);