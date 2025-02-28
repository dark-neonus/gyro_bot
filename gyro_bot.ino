

#include "src/Vec2.h"
#include "src/Counter.h"
#include "src/Settings.h"
#include "face.h"

#include "display.h"
#include "gyroscope.h"
#include "events.h"
#include "configure.h"
#include "behavior.h"


float dX_circle, dY_circle;


Face face = Face(Vec2(0.0f, 0.0f));

// TreeNode default_menu = TreeNode;


// Counter button_threshold = Counter(4, 0);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("started");

  Settings::loadData();

  configureMenuList();

  menu_list.menu->addPath(menu_list.menu->getRoot()->sub_nodes[0]);

  displaySetup();
  gyroSetup();
  eventsSetup();
}


void loop() {
  updateSensorData();

  dX_circle = angleX / 2;
  dY_circle = angleY / 2;

  display.clearDisplay(); // Clear display buffer
  // display.drawCircle(display.width()/2 + dX_circle, display.height()/2 + dY_circle, 5, SSD1306_WHITE);

  if (accelMagnitude < BOTTOM_ACCELERATION_TRIGER || accelMagnitude > TOP_ACCELERATION_TRIGER) {
    shakeTriggerCouner.increase();
  }
  else {
    shakeTriggerCouner.decrease();
  }

  if ((Settings::live_mode) &&
    (Settings::bot_state == BotState::TIRED1 || Settings::bot_state == BotState::TIRED2) &&
    (accelMagnitude < 0.5 || accelMagnitude > 1.5 ||
      abs(gX) + abs(gY) + abs(gZ) > 180)) {
    inactiveCounter.setValue(0);
    Settings::bot_state = BotState::NORMAL;
  }
  
  update_behavior(menu_list.menu);

  face.draw(display,
    Vec2(SCREEN_WIDTH / 2 + (Settings::show_ui ? 26 : 0), SCREEN_HEIGHT / 2)
    + Vec2(-gZ * deltaTime, gX * deltaTime) * Settings::face_sensitivity
  );
  if (Settings::show_ui) {
    menu_list.draw(display, Vec2(0.0f, 0.0f));
  }

  events_handler(menu_list.menu);

  display.display();

  face.update();

  delay(10);
}


