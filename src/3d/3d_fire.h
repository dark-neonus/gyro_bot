#pragma once

#include <vector>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "../Counter.h"
#include "../Vec2.h"
#include "Vec3.h"
#include "Plane.h"

class CircleParticle {
public:
  Vec3 pos;

  Counter lifetime = Counter(50, 50);
  float max_radius = 10.0f;
  float min_radius = 1.0f;

  CircleParticle(Vec3 pos_)
  : pos(pos_)
  {}

  void update(Vec3 dV) {
    lifetime.decrease();
    pos = pos + dV;
  }
  void draw(Adafruit_SSD1306& display, Vec2 dV, Plane camera) {
    if (camera.is_point_in_front(pos)) {
      Vec2 ppos = project_on_plane(pos, camera) + dV;

      display.fillCircle(ppos.x, ppos.y, max(max_radius * lifetime.getValue() / lifetime.getMaxValue() - abs(pos.x - camera.point.x) / 10, min_radius), WHITE);
    }
  }
};

namespace fire_3d {
  extern std::vector<CircleParticle> particles;

  extern Plane camera;

  extern Counter spawnCounter;

  void update_fire();
  void draw_fire(Adafruit_SSD1306& display, Vec2 dV);
}