#pragma once

#include <memory>

#include "src/Settings.h"
#include "src/MenuTree.h"
#include "src/Counter.h"
#include "display.h"
#include "configure.h"

#define BOTTOM_ACCELERATION_TRIGER 0.3
#define TOP_ACCELERATION_TRIGER 1.7

#define TIRED1_TIME 300
#define TIRED2_TIME 600
#define SLEEP_TIME 900
#define HIDE_UI_TIME 150

Counter inactiveCounter = Counter(SLEEP_TIME);

#define SHAKE_TRESHOLD 7

Counter shakeTriggerCouner = Counter(SHAKE_TRESHOLD);

#define TENSION_TIME 17
#define DIZZY_TIME 60

Counter tensionCounter = Counter(TENSION_TIME);
Counter dizzyCounter = Counter(DIZZY_TIME);

void update_behavior(std::shared_ptr<MenuTree> menu) {
  Settings::live_mode = true;
  if (menu->getDirectoryName() == MANUAL_DIR_NAME) {
    Settings::live_mode = false;
  }

  if (Settings::live_mode) {
    inactiveCounter.increase();

    if (shakeTriggerCouner.isMax()) {
      shakeTriggerCouner.setValue(0);
      Settings::bot_state = BotState::TENSION;
      tensionCounter.setValue(0);
      inactiveCounter.setValue(0);
    }

    if (Settings::bot_state == BotState::TENSION) {
      tensionCounter.increase();

      if (tensionCounter.isMax()) {
        tensionCounter.setValue(0);
        Settings::bot_state = BotState::DIZZY;
        dizzyCounter.setValue(0);
      }
    }

    if (Settings::bot_state == BotState::DIZZY) {
      dizzyCounter.increase();

      if (dizzyCounter.isMax()) {
        dizzyCounter.setValue(0);
        Settings::bot_state = BotState::NORMAL;
      }
    }
  }
  else {
    inactiveCounter.setValue(0);
  }


  if (inactiveCounter.getValue() >= SLEEP_TIME) {
    enterDeepSleep(menu);
  }
  else if (inactiveCounter.getValue() >= TIRED2_TIME) {
    Settings::bot_state = BotState::TIRED2;
  }
  else if (inactiveCounter.getValue() >= TIRED1_TIME) {
    Settings::bot_state = BotState::TIRED1;
  }
  else if (inactiveCounter.getValue() >= HIDE_UI_TIME) {
    Settings::show_ui = false;
  }


}