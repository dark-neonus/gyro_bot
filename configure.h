#pragma once

#include <memory>

#include "src/MenuTree.h"
#include "src/Vec2.h"
#include "face.h"
// #include "configure.h"

#include "src/console/console.h"

MenuListObject menu_list = MenuListObject();

#define LIVE_DIR_NAME "live"
#define MANUAL_DIR_NAME "manual"
#define MPU_DATA_DIR_NAME "mpu_data"
#define NAVIGATION_DIR_NAME "navigation"
#define SLEEP_DIR_NAME "sleep"

void configureMenuList() {
  TreeNode live_mode = TreeNode(LIVE_DIR_NAME);
  {
    live_mode.addNode(std::make_shared<TreeNode>("menu", MenuTree::go_back));
    live_mode.addNode(std::make_shared<TreeNode>("hide UI", 
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::show_ui = false;
      })
    );
  }
  TreeNode manual_mode = TreeNode(MANUAL_DIR_NAME);
  {
    manual_mode.addNode(std::make_shared<TreeNode>("back", MenuTree::go_back));
    manual_mode.addNode(std::make_shared<TreeNode>("normal",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::NORMAL;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("love",
    [](std::shared_ptr<MenuTree> menuTree) {
        Settings::bot_state = BotState::LOVE;
    }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("tension",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::TENSION;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("dizzy1",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::DIZZY1;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("dizzy2",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::DIZZY2;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("tired1",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::TIRED1;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("tired2",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::TIRED2;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("dead",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::DEAD;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("happy",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::HAPPY;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("meditation",
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::bot_state = BotState::MEDITATION;
      }
    ));
    manual_mode.addNode(std::make_shared<TreeNode>("hide UI", 
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::show_ui = false;
      })
    );
  }

  // ### Not supported yet ###
  // TreeNode settings_mode = TreeNode("settings");
  // {
  //   settings_mode.addNode(std::make_shared<TreeNode>("back", MenuTree::go_back));
  //   settings_mode.addNode(std::make_shared<TreeNode>("option 1", MenuTree::do_nothing));
  //   settings_mode.addNode(std::make_shared<TreeNode>("option 2", MenuTree::do_nothing));
  //   settings_mode.addNode(std::make_shared<TreeNode>("option 3", MenuTree::do_nothing));
  //   settings_mode.addNode(std::make_shared<TreeNode>("option 4", MenuTree::do_nothing));
  // }
  // TreeNode test_mode = TreeNode("test");
  // {
  //   test_mode.addNode(std::make_shared<TreeNode>("back", MenuTree::go_back));
  // }
  // 
  TreeNode mpu_data = TreeNode(MPU_DATA_DIR_NAME);
  {
    // mpu_data.addNode(std::make_shared<TreeNode>("back", MenuTree::go_back));
    // mpu_data.addNode(std::make_shared<TreeNode>("hide UI", 
    //   [](std::shared_ptr<MenuTree> menuTree) {
    //       Settings::show_ui = false;
    //   })
    // );
  }
  TreeNode navigation_data = TreeNode(NAVIGATION_DIR_NAME);
  {}
  TreeNode sleep_mode = TreeNode(SLEEP_DIR_NAME, enterDeepSleep);


  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(live_mode));
  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(manual_mode));
  // menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(settings_mode));
  // menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(test_mode));
  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(mpu_data));
  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(navigation_data));
  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(sleep_mode));
}