#pragma once

#include <Preferences.h>

enum BotState {
  NORMAL,
  LOVE,
  TENSION,
  DIZZY1,
  DIZZY2,
  TIRED1,
  TIRED2,
  DEAD,
  HAPPY,
  MEDITATION
};

namespace Settings {
  extern Preferences preferences;

  extern bool show_ui;
  extern bool live_mode;
  extern bool enable_face;
  extern BotState bot_state;
  extern float face_sensitivity;

  void saveData();

  void loadData();
};
