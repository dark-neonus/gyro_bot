#include "Settings.h"

Preferences Settings::preferences;

bool Settings::show_ui = false;
BotState Settings::bot_state = BotState::NORMAL;
float Settings::face_sensitivity = 1.0f;
bool Settings::live_mode = false;
