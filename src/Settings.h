#pragma once

#include <Preferences.h>

enum BotState {
  NORMAL,
  LOVE,
  TENSION,
  DIZZY,
  TIRED1,
  TIRED2,
  DEAD,
  HAPPY
};

class Settings {
public:
  static Preferences preferences;

  static bool show_ui;
  static bool live_mode;
  static BotState bot_state;
  static float face_sensitivity;

  static void saveData() {
    preferences.begin("storage", false);
    preferences.putBool("show_ui", Settings::show_ui);
    preferences.putFloat("face_sensitivity", Settings::face_sensitivity);

    preferences.end();
  }

  static void loadData() {
    preferences.begin("storage", true);
    Settings::show_ui = preferences.getBool("show_ui", false);
    Settings::face_sensitivity = preferences.getFloat("face_sensitivity", 1.8f);

    preferences.end();
  }
};
