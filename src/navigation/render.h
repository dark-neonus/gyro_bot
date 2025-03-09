#pragma once

#include <cmath>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Vec3.h"
#include "Plane.h"

#include "../Vec2.h"
#include "../../mpu.h"

Plane camera = Plane(
  Vec3(1.0f, 0.0f, 0.0f), // Normal
  Vec3(0.0f, 1.0f, 0.0f), // X Axis
  Vec3(0.0f, 0.0f, 1.0f), // Y Axis
  Vec3(-30.0f, 0.0f, 0.0f) // Point
);

Vec3 old_p2 = Vec3(0.0f, 0.0f, 0.0f);
float ball_inertion = 0.7f;

void test_render(Adafruit_SSD1306& display, Vec2 dV) {
  Vec3 p1 = Vec3(0.0f, 0.0f, 0.0f);
  // Vec3 p2 = Vec3(0.0f, 10.0f, 5.0f);
  Vec3 p2 = Vec3(std::lerp(mpu::aY * 20.0f, old_p2.x, ball_inertion),
                  std::lerp(-mpu::aX * 20.0f, old_p2.y, ball_inertion),
                  std::lerp(-mpu::aZ * 20.0f, old_p2.z, ball_inertion));
  old_p2 = p2;

  Vec2 pp1 = p1.project_on_plane(camera) + dV;
  Vec2 pp2 = p2.project_on_plane(camera) + dV;

  display.drawLine(pp1.x, pp1.y, pp2.x, pp2.y, WHITE);
  display.drawCircle(pp2.x, pp2.y, 60 / (30 - abs(p2.x - camera.point.x) / 2), WHITE);
}
