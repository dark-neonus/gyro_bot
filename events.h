#pragma once

#include <memory>

#include "src/Vec2.h"
#include "src/Counter.h"
#include "src/MenuTree.h"
#include "src/Settings.h"

#include "face.h"

#define LEFT_BUTTON_PIN 25
#define UP_BUTTON_PIN 33
#define DOWN_BUTTON_PIN 32
#define RIGHT_BUTTON_PIN 35

#define BUTTON_REACTION_TRESHOLD 5

Counter left_button_counter = Counter(BUTTON_REACTION_TRESHOLD);
Counter up_button_counter = Counter(BUTTON_REACTION_TRESHOLD);
Counter down_button_counter = Counter(BUTTON_REACTION_TRESHOLD);
Counter right_button_counter = Counter(BUTTON_REACTION_TRESHOLD);


void eventsSetup() {
  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(UP_BUTTON_PIN, INPUT);
  pinMode(DOWN_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);
}

void events_handler(std::shared_ptr<MenuTree> menu_list) {
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  if (digitalRead(LEFT_BUTTON_PIN) == HIGH) {
    left_button_counter.increase();
  }
  else {
    left_button_counter.decrease();
  }
    
  if (digitalRead(UP_BUTTON_PIN) == HIGH) {
    up_button_counter.increase();
  }
  else {
    up_button_counter.decrease();
  }

  if (digitalRead(DOWN_BUTTON_PIN) == HIGH) {
    down_button_counter.increase();
  }
  else {
    down_button_counter.decrease();
  }

  if (digitalRead(RIGHT_BUTTON_PIN) == HIGH) {
    right_button_counter.increase();
  }
  else {
    right_button_counter.decrease();
  }

  
  if (left_button_counter.isMax()) {
    display.setCursor(SCREEN_WIDTH - 4 * 7, 5);
    display.print("L");
    if (Settings::show_ui) {
      menu_list->goBack();
    }
    else {
      Settings::show_ui = true;
    }
    left_button_counter.setValue(0);
  }
  if (up_button_counter.isMax()) {
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