#pragma once

#include <memory>

#include "src/MenuTree.h"

MenuListObject menu_list = MenuListObject();



void configureMenuList() {
  TreeNode live_mode = TreeNode("live");
  {
    live_mode.addNode(std::make_shared<TreeNode>("menu", MenuTree::go_back));
    live_mode.addNode(std::make_shared<TreeNode>("hide UI", 
      [](std::shared_ptr<MenuTree> menuTree) {
          Settings::show_ui = false;
      })
    );
  }
  TreeNode manual_mode = TreeNode("manual");
  {
    manual_mode.addNode(std::make_shared<TreeNode>("back", MenuTree::go_back));
    manual_mode.addNode(std::make_shared<TreeNode>("face 1", MenuTree::do_nothing));
    manual_mode.addNode(std::make_shared<TreeNode>("face 2", MenuTree::do_nothing));
    manual_mode.addNode(std::make_shared<TreeNode>("face 3", MenuTree::do_nothing));
    manual_mode.addNode(std::make_shared<TreeNode>("face 4", MenuTree::do_nothing));
    manual_mode.addNode(std::make_shared<TreeNode>("face 5", MenuTree::do_nothing));
  }
  TreeNode settings_mode = TreeNode("settings");
  {
    settings_mode.addNode(std::make_shared<TreeNode>("back", MenuTree::go_back));
    settings_mode.addNode(std::make_shared<TreeNode>("option 1", MenuTree::do_nothing));
    settings_mode.addNode(std::make_shared<TreeNode>("option 2", MenuTree::do_nothing));
    settings_mode.addNode(std::make_shared<TreeNode>("option 3", MenuTree::do_nothing));
    settings_mode.addNode(std::make_shared<TreeNode>("option 4", MenuTree::do_nothing));
  }
  TreeNode test_mode = TreeNode("test");
  {
    test_mode.addNode(std::make_shared<TreeNode>("back", MenuTree::go_back));
  }
  TreeNode sleep_mode = TreeNode("sleep", MenuTree::do_nothing);


  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(live_mode));
  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(manual_mode));
  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(settings_mode));
  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(test_mode));
  menu_list.menu->getRoot()->addNode(std::make_shared<TreeNode>(sleep_mode));
}