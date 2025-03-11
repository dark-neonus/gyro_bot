#include "3d_fire.h"

#include <vector>
#include "Vec3.h"
#include "render.h"
#include "../Counter.h"

std::vector<CircleParticle> fire_3d::particles = {};

Counter fire_3d::spawnCounter = Counter(5, 0);

Plane fire_3d::camera = Plane(
  Vec3(1.0f, 0.0f, 0.0f), // Normal
  Vec3(0.0f, 1.0f, 0.0f), // X Axis
  Vec3(0.0f, 0.0f, 1.0f), // Y Axis
  Vec3(-25.0f, 0.0f, 0.0f) // Points
);

void fire_3d::update_fire() {
  for (auto& particle : particles) {
    particle.update(u3D::gyro_coordinates.z_axis + Vec3(random(200) / 200 - 0.5f, random(200) / 200 - 0.5f, random(200) / 200 - 0.5f) * 0.1f);
  }
  for (auto it = particles.begin(); it != particles.end(); ) {
    if (it->lifetime.isZero()) {
        it = particles.erase(it);  // Erase and move iterator to next valid position
    } else {
        ++it;  // Move to the next element
    }
  }
  spawnCounter.increase();
  if (spawnCounter.isMax()) {
    spawnCounter.setValue(0);
    particles.push_back(CircleParticle(
      u3D::gyro_coordinates.origin + Vec3(random(200) / 200 - 0.5f, random(200) / 200 - 0.5f, random(200) / 200 - 0.5f) * 10.0f
      ));
  }
}


void fire_3d::draw_fire(Adafruit_SSD1306& display, Vec2 dV) {
  for (auto& particle : particles) {
    particle.draw(display, dV, camera);
  }
}

