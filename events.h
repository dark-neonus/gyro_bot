#pragma once

#include "Vec2.h"
#include "Counter.h"
#include "face.h"
#include "menu_list.h"

#define LEFT_BUTTON_PIN 25
#define UP_BUTTON_PIN 33
#define DOWN_BUTTON_PIN 32
#define RIGHT_BUTTON_PIN 35

bool left_button_pressed = false;
bool up_button_pressed = false;
bool down_button_pressed = false;
bool right_button_pressed = false;

void eventsSetup() {
  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(UP_BUTTON_PIN, INPUT);
  pinMode(DOWN_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);
}

void events_handler(SideList& side_list) {
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  if (digitalRead(LEFT_BUTTON_PIN) == HIGH) {
    display.setCursor(SCREEN_WIDTH - 4 * 7, 5);
    display.print("L");
    if (!left_button_pressed) {
      // side_list.selectPrevious();
    }
    // button_threshold.setValue(button_threshold.getMaxValue());
    left_button_pressed = true;
  } else {
    left_button_pressed = false;
  }
  if (digitalRead(UP_BUTTON_PIN) == HIGH) {
    display.setCursor(SCREEN_WIDTH - 3 * 7, 5);
    display.print("U");
    if (!up_button_pressed) {
      side_list.selectPrevious();
    }
    // button_threshold.setValue(button_threshold.getMaxValue());
    up_button_pressed = true;
  } else {
    up_button_pressed = false;
  }
  if (digitalRead(DOWN_BUTTON_PIN) == HIGH) {
    display.setCursor(SCREEN_WIDTH - 2 * 7, 5);
    display.print("D");
    if (!down_button_pressed) {
      side_list.selectNext();
    }
    // button_threshold.setValue(button_threshold.getMaxValue());
    down_button_pressed = true;
  } else {
    down_button_pressed = false;
  }
  if (digitalRead(RIGHT_BUTTON_PIN) == HIGH) {
    display.setCursor(SCREEN_WIDTH - 1 * 7, 5);
    display.print("R");
    if (!right_button_pressed) {
      // side_list.selectNext();
    }
    // button_threshold.setValue(button_threshold.getMaxValue());
    right_button_pressed = true;
  } else {
    right_button_pressed = false;
  }
}