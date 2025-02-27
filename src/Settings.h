#pragma once

#include <Preferences.h>

enum BotState {
  NORMAL,
  LOVE,
  TENSION,
  DIZZY,
  TIRED1,
  TIRED2
};

class Settings {
public:
  static Preferences preferences;

  static bool show_ui;
  static BotState bot_state;
  static float face_sensitivity;

  static void saveData() {
    preferences.begin("storage", false);
    preferences.putBool("show_ui", Settings::show_ui);
    preferences.putFloat("face_sensitivity", Settings::face_sensitivity);


    preferences.putInt("myInt", 42);
    preferences.putFloat("myFloat", 3.14);
    preferences.putInt("myEnum", 1);
    preferences.end();
  }

  static void loadData() {
    preferences.begin("storage", true);
    Settings::show_ui = preferences.getBool("show_ui", false);
    Settings::face_sensitivity = preferences.getFloat("face_sensitivity", 2.0f);


    int myInt = preferences.getInt("myInt", 0);
    float myFloat = preferences.getFloat("myFloat", 0.0);
    int myEnum = preferences.getInt("myEnum", 0);
    preferences.end();
  }
};
