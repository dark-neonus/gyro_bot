#pragma once

#include <memory>

#include "src/Settings.h"
#include "src/MenuTree.h"
#include "src/Counter.h"
#include "display.h"
#include "configure.h"
#include "mpu.h"

#define BOTTOM_ACCELERATION_TRIGER 0.3
#define TOP_ACCELERATION_TRIGER 1.7
#define SPINNING_TRIGGER 400

#define TIRED1_TIME 300
#define TIRED2_TIME 600
#define SLEEP_TIME 900
#define HIDE_UI_TIME 150

#define WAKE_UP_SHAKE_TRESHOLD 4
#define WAKE_UP_SPINNING_TRESHOLD 3

Counter inactiveCounter = Counter(SLEEP_TIME);

#define SHAKE_TRESHOLD 8
#define SPINNIG_THRESHOLD 20

Counter shakeTriggerCounter = Counter(SHAKE_TRESHOLD);
Counter spinningTriggerCounter = Counter(SPINNIG_THRESHOLD);

#define TENSION_TIME 17
#define DIZZY1_TIME 60
#define DIZZY2_TIME 60

Counter tensionCounter = Counter(TENSION_TIME);
Counter DIZZY1Counter = Counter(DIZZY1_TIME);
Counter DIZZY2Counter = Counter(DIZZY2_TIME);

void update_behavior(std::shared_ptr<MenuTree> menu) {
  if (Settings::bot_state != BotState::TENSION) {
    if (mpu::accelMagnitude < BOTTOM_ACCELERATION_TRIGER || mpu::accelMagnitude > TOP_ACCELERATION_TRIGER) {
      shakeTriggerCounter.increase();
    }
    else {
      shakeTriggerCounter.decrease();
    }


    if (mpu::gSum > SPINNING_TRIGGER) {
      spinningTriggerCounter.increase();
    }
    else {
      spinningTriggerCounter.decrease();
    }
  }

  if ((Settings::live_mode) &&
    (Settings::bot_state == BotState::TIRED1 || Settings::bot_state == BotState::TIRED2) &&
    (shakeTriggerCounter.getValue() > WAKE_UP_SHAKE_TRESHOLD || spinningTriggerCounter.getValue() > WAKE_UP_SPINNING_TRESHOLD)) {
    inactiveCounter.setValue(0);
    Settings::bot_state = BotState::NORMAL;
  }

  Settings::live_mode = true;
  if (menu->getDirectoryName() == MANUAL_DIR_NAME) {
    Settings::live_mode = false;
  }

  if (Settings::live_mode) {
    inactiveCounter.increase();

    if (spinningTriggerCounter.isMax()) {
      shakeTriggerCounter.setValue(0);
      Settings::bot_state = BotState::TENSION;
      // tensionCounter.setValue(0);
      inactiveCounter.setValue(0);
    }

    if (shakeTriggerCounter.isMax()) {
      spinningTriggerCounter.setValue(0);
      Settings::bot_state = BotState::TENSION;
      // tensionCounter.setValue(0);
      inactiveCounter.setValue(0);
    }

    if (Settings::bot_state == BotState::TENSION) {
      tensionCounter.increase();

      if (tensionCounter.isMax()) {
        tensionCounter.setValue(0);
        if (shakeTriggerCounter.isMax()) {
          shakeTriggerCounter.setValue(0);
          Settings::bot_state = BotState::DIZZY1;
          DIZZY1Counter.setValue(0);
        } else if (spinningTriggerCounter.isMax()) {
          spinningTriggerCounter.setValue(0);
          Settings::bot_state = BotState::DIZZY2;
          DIZZY2Counter.setValue(0);
        } else {
          // Just to not loop in TENSION state
          Settings::bot_state = BotState::DIZZY1;
        }
        tensionCounter.setValue(0);
      }
    }

    if (Settings::bot_state == BotState::DIZZY1) {
      DIZZY1Counter.increase();

      if (DIZZY1Counter.isMax()) {
        DIZZY1Counter.setValue(0);
        Settings::bot_state = BotState::NORMAL;
      }
    }

    if (Settings::bot_state == BotState::DIZZY2) {
      DIZZY2Counter.increase();

      if (DIZZY2Counter.isMax()) {
        DIZZY2Counter.setValue(0);
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