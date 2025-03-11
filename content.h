#pragma once

#include <string>
#include <vector>
#include <format>

#include "src/Vec2.h"
#include "src/Counter.h"
#include "src/Settings.h"

#include "src/console/console.h"
#include "src/3d/Vec3.h"
#include "src/3d/render.h"
#include "src/3d/3d_fire.h"

#include "face.h"
#include "display.h"
#include "mpu.h"
#include "events.h"
#include "configure.h"
#include "behavior.h"

Vec2 content_pos = Vec2(0.0f, 0.0f);

Face face = Face(Vec2(0.0f, 0.0f));
Console console = Console(Vec2(0.0f, 0.0f));

void draw_content(Adafruit_SSD1306& display) {
  content_pos = Vec2(Settings::show_ui ? 30 : 0, 0.0f);
  if (menu_list.menu->getDirectoryName() == MPU_DATA_DIR_NAME) {
    console.draw(display, content_pos, std::vector<std::string>({
      std::format("aX: {:.1f}", mpu::aX),
      std::format("aY: {:.1f}", mpu::aY),
      std::format("aZ: {:.1f}", mpu::aZ),
      std::string("--------"),
      std::format("gX: {:.1f}", mpu::gX),
      std::format("gY: {:.1f}", mpu::gY),
      std::format("gZ: {:.1f}", mpu::gZ)
    }));
  }
  if (menu_list.menu->getDirectoryName() == NAVIGATION_DIR_NAME) {
    test_render(display, Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), mpu::aX, mpu::aY, mpu::aZ);
  }
  if (menu_list.menu->getDirectoryName() == AXIS_DIR_NAME) {
    render_axis(display, Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), mpu::aX, mpu::aY, mpu::aZ);
  }
  if (menu_list.menu->getDirectoryName() == FIRE_DIR_NAME) {
    fire_3d::draw_fire(display, Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
  }
  if (Settings::enable_face) {
    face.draw(display, content_pos +
      Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2) +
      Vec2(mpu::gZ * deltaTime, -mpu::gX * deltaTime) * Settings::face_sensitivity
      );
  }
}

void update_content() {
  Settings::enable_face = true;
  if (menu_list.menu->getDirectoryName() == MPU_DATA_DIR_NAME ||
      menu_list.menu->getDirectoryName() == NAVIGATION_DIR_NAME ||
      menu_list.menu->getDirectoryName() == AXIS_DIR_NAME ||
      menu_list.menu->getDirectoryName() == FIRE_DIR_NAME
      ) {
    Settings::enable_face = false;
    Settings::show_ui = false;
  }
  if (menu_list.menu->getDirectoryName() == FIRE_DIR_NAME) {
    fire_3d::update_fire();
  }
  if (Settings::enable_face) {
    update_behavior(menu_list.menu);
    face.update();
  }
}