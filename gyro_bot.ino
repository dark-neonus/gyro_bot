
#include "Vec2.h"
#include "Counter.h"
#include "face.h"
#include "menu_list.h"

#include "display.h"
#include "gyroscope.h"
#include "events.h"




float dX_circle, dY_circle;




Face face = Face(Vec2(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2));
SideList side_list = SideList({
  "meow1",
  "meow2",
  "meow3",
  "meow4",
  "meow5",
  "meow6",
  "Meowl",
  "!!!",
  "meoooow",
  "abc"
});
// Counter button_threshold = Counter(4, 0);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("started");

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
  face.draw(display, Vec2(gX * deltaTime, gY * deltaTime) / 2);
  side_list.draw(display, Vec2(0.0f, 0.0f));

  events_handler(side_list);

  display.display();

  delay(50);
}


