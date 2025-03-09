#pragma once

#include <memory>

#include "src/Vec2.h"
#include "src/Counter.h"
#include "src/MenuTree.h"
#include "src/Settings.h"
#include "behavior.h"

#include "face.h"

// ### Correct configure ###
#define LEFT_BUTTON_PIN 5
#define UP_BUTTON_PIN 6
#define DOWN_BUTTON_PIN 4
#define RIGHT_BUTTON_PIN 7

// ### Incorrect solution for short time ###
// #define LEFT_BUTTON_PIN 7
// #define UP_BUTTON_PIN 4
// #define DOWN_BUTTON_PIN 6
// #define RIGHT_BUTTON_PIN 5

#define WAKE_UP_PIN DOWN_BUTTON_PIN
#define WAKE_UP_MODE INPUT_PULLDOWN
#define WAKE_UP_SIGNAL HIGH

#define BUTTON_MODE INPUT_PULLDOWN
#define BUTTON_PRESSED_SIGNAL HIGH

#define BUTTON_REACTION_TRESHOLD 6

Counter left_button_counter = Counter(BUTTON_REACTION_TRESHOLD);
Counter up_button_counter = Counter(BUTTON_REACTION_TRESHOLD);
Counter down_button_counter = Counter(BUTTON_REACTION_TRESHOLD);
Counter right_button_counter = Counter(BUTTON_REACTION_TRESHOLD);


void eventsSetup() {
// ### Incorrect solution for short time ###
// #define LEFT_BUTTON_PIN 7
// #define UP_BUTTON_PIN 4
// #define DOWN_BUTTON_PIN 6
// #define RIGHT_BUTTON_PIN 5

  pinMode(LEFT_BUTTON_PIN, BUTTON_MODE);
  pinMode(UP_BUTTON_PIN, BUTTON_MODE);
  pinMode(DOWN_BUTTON_PIN, BUTTON_MODE);
  pinMode(RIGHT_BUTTON_PIN, BUTTON_MODE);

  pinMode(WAKE_UP_PIN, WAKE_UP_MODE);
  esp_sleep_enable_ext0_wakeup((gpio_num_t)WAKE_UP_PIN, WAKE_UP_SIGNAL);  // Wake up when button pressed
}

void events_handler(std::shared_ptr<MenuTree> menu_list) {
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  if (digitalRead(LEFT_BUTTON_PIN) == BUTTON_PRESSED_SIGNAL) {
    left_button_counter.increase();
  }
  else {
    left_button_counter.decrease();
  }
    
  if (digitalRead(UP_BUTTON_PIN) == BUTTON_PRESSED_SIGNAL) {
    up_button_counter.increase();
  }
  else {
    up_button_counter.decrease();
  }

  if (digitalRead(DOWN_BUTTON_PIN) == WAKE_UP_SIGNAL) {
    down_button_counter.increase();
  }
  else {
    down_button_counter.decrease();
  }

  if (digitalRead(RIGHT_BUTTON_PIN) == BUTTON_PRESSED_SIGNAL) {
    right_button_counter.increase();
  }
  else {
    right_button_counter.decrease();
  }

  
  if (left_button_counter.isMax()) {
    inactiveCounter.setValue(0);
    display.setCursor(SCREEN_WIDTH - 4 * 7, 5);
    display.print("L");
    // if (Settings::show_ui) {
    menu_list->goBack();
    // }
    // else {
    Settings::show_ui = true;
    // }
    left_button_counter.setValue(0);
  }
  if (up_button_counter.isMax()) {
    inactiveCounter.setValue(0);
    display.setCursor(SCREEN_WIDTH - 3 * 7, 5);
    display.print("U");
    if (Settings::show_ui) {
      menu_list->selectPrevious();
    }
    else {
      Settings::show_ui = true;
    }
    up_button_counter.setValue(0);
  }
  if (down_button_counter.isMax()) {
    inactiveCounter.setValue(0);
    display.setCursor(SCREEN_WIDTH - 2 * 7, 5);
    display.print("D");
    if (Settings::show_ui) {
      menu_list->selectNext();
    }
    else {
      Settings::show_ui = true;
    }
    down_button_counter.setValue(0);
  }
  if (right_button_counter.isMax()) {
    inactiveCounter.setValue(0);
    display.setCursor(SCREEN_WIDTH - 1 * 7, 5);
    display.print("R");
    if (Settings::show_ui) {
      menu_list->performAction();
    }
    else {
      Settings::show_ui = true;
    }
    right_button_counter.setValue(0);
  }
}