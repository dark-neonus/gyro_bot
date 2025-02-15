
#include "Vec2.h"
#include "Counter.h"
#include "face.h"
#include "menu_list.h"

#include "display.h"
#include "gyroscope.h"
#include "events.h"
#include "MenuTree.h"




float dX_circle, dY_circle;



Face face = Face(Vec2(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2));

// TreeNode default_menu = TreeNode;

MenuListObject menu_list = MenuListObject();


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
  

  menu_list.menu->getRoot()->addNode(
    std::make_shared<TreeNode>(TreeNode("default", std::vector<std::shared_ptr<TreeNode>>({
      std::make_shared<TreeNode>(TreeNode("option1", {}, MenuTree::do_nothing)),
      std::make_shared<TreeNode>(TreeNode("option2", {}, MenuTree::do_nothing)),
      std::make_shared<TreeNode>(TreeNode("option3", {}, MenuTree::do_nothing)),
      std::make_shared<TreeNode>(TreeNode("meow", {}, MenuTree::do_nothing)),
      std::make_shared<TreeNode>(TreeNode("meow !!!", {}, MenuTree::do_nothing)),
      std::make_shared<TreeNode>(TreeNode("Owww", {}, MenuTree::do_nothing))
    })))
  );

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
  face.draw(display, Vec2(gX * deltaTime, gY * deltaTime) / 2);
  menu_list.draw(display, Vec2(0.0f, 0.0f));

  events_handler(menu_list.menu);

  display.display();

  delay(50);
}


