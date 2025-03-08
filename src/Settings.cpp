#include "Settings.h"

Preferences Settings::preferences;

bool Settings::show_ui = false;
BotState Settings::bot_state = BotState::NORMAL;
float Settings::face_sensitivity = 1.0f;
bool Settings::live_mode = false;

void Settings::saveData() {
  preferences.begin("storage", false);
  preferences.putBool("show_ui", Settings::show_ui);
  preferences.putFloat("face_sensitivity", Settings::face_sensitivity);

  preferences.end();
}

void Settings::loadData() {
  preferences.begin("storage", true);
  Settings::show_ui = preferences.getBool("show_ui", false);
  Settings::face_sensitivity = preferences.getFloat("face_sensitivity", 1.8f);

  preferences.end();
}
