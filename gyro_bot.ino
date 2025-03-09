#include "src/Vec2.h"
#include "src/Counter.h"
#include "src/Settings.h"

#include "face.h"
#include "display.h"
#include "mpu.h"
#include "events.h"
#include "configure.h"
#include "behavior.h"
#include "content.h"

// TreeNode default_menu = TreeNode;
// Preferences Settings::preferences;

// bool Settings::show_ui = false;
// BotState Settings::bot_state = BotState::NORMAL;
// float Settings::face_sensitivity = 1.0f;
// bool Settings::live_mode = false;


// Counter button_threshold = Counter(4, 0);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("started");

  Settings::loadData();

  configureMenuList();

  menu_list.menu->addPath(menu_list.menu->getRoot()->sub_nodes[0]);

  displaySetup();
  mpuSetup();
  eventsSetup();
}


void loop() {
  updateMPUData();
  events_handler(menu_list.menu);
  update_content();

  display.clearDisplay();

  if (Settings::show_ui) {
    menu_list.draw(display, Vec2(0.0f, 0.0f));
  }
  draw_content(display);

  display.display();

  delay(10);
}


