#pragma once

#include <vector>
#include <stack>
#include <tuple>
#include <memory>
#include <string>
#include <functional>

#include <Adafruit_GFX.h>       // Core graphics library
#include <Adafruit_SSD1306.h>   // OLED library

#include "RangeValueInt.h"

#include "Vec2.h"
#include "ScreenObject.h"

class MenuTree;

class TreeNode : public std::enable_shared_from_this<TreeNode> {
  friend class MenuTree;
private:
  std::string _text;
  RangeValueInt _selectedIndex;

public:
  std::vector<std::shared_ptr<TreeNode>> sub_nodes;
  std::function<void(std::shared_ptr<MenuTree>)> actionFunction;

  TreeNode(std::string text,
           std::function<void(std::shared_ptr<MenuTree>)> actionFunction_ = nullptr,
           std::vector<std::shared_ptr<TreeNode>> sub_nodes_ = {});

  std::string getText() { return _text; }

  void addNode(std::shared_ptr<TreeNode> node) {
    sub_nodes.push_back(node);
    _selectedIndex.setMaxValue(sub_nodes.size() - 1);
  }
};

class MenuTree : public std::enable_shared_from_this<MenuTree> {
private:
  std::vector<std::shared_ptr<TreeNode>> _nodes;
  std::stack<std::shared_ptr<TreeNode>> _path;
  std::shared_ptr<TreeNode> _rootNode;
  

  
public:
  static const std::function<void(std::shared_ptr<MenuTree>)> do_nothing;
  static const std::function<void(std::shared_ptr<MenuTree>)> go_back;
  static const std::function<void(std::shared_ptr<MenuTree>)> defaultActionFunction;

  static constexpr int FONT_SIZE = 1;
  static constexpr int LEFT_PADDING = 5;
  static constexpr int ELEMENT_PADDING = 10;

  MenuTree(std::vector<std::shared_ptr<TreeNode>> sub_nodes_ = {})
    : _rootNode(std::make_shared<TreeNode>("root", MenuTree::do_nothing, sub_nodes_))
  {
    addPath(_rootNode);
  }

  std::shared_ptr<TreeNode> getRoot() { return _rootNode; }

  void addPath(std::shared_ptr<TreeNode> node) {
    _path.push(node);
  }

  void goBack() {
    if (_path.size() > 1) {
      _path.pop();
    }
  }

  void performAction() {
    if (getSelected()->actionFunction != nullptr) {
      getSelected()->actionFunction(shared_from_this());
    }
  }

  std::shared_ptr<TreeNode> getCurrentNode() {
    return _path.top();
  }

  void select(int index) { getCurrentNode()->_selectedIndex.setValue(index); }
  void selectNext() { getCurrentNode()->_selectedIndex.increase(); }
  void selectPrevious() { getCurrentNode()->_selectedIndex.decrease(); }

  int getIndex() { return getCurrentNode()->_selectedIndex.getValue(); }
  std::shared_ptr<TreeNode> getAt(int index) { return getCurrentNode()->sub_nodes[index]; }
  std::shared_ptr<TreeNode> getSelected() { return getAt(getCurrentNode()->_selectedIndex.getValue()); }
};



class MenuListObject : public ScreenObject {
public:
  std::shared_ptr<MenuTree> menu;

  MenuListObject(std::vector<std::shared_ptr<TreeNode>> sub_nodes_ = {})
  : ScreenObject(Vec2(0.0f, 0.0f)), menu(std::make_shared<MenuTree>(sub_nodes_))
  {}

  void draw(Adafruit_SSD1306& display, Vec2 dV) override {
    std::array<int, 5> visibleIndexes = {
      menu->getIndex() - 2,
      menu->getIndex() - 1,
      menu->getIndex(),
      menu->getIndex() + 1,
      menu->getIndex() + 2
    };

    for (int i = 0; i < visibleIndexes.size(); i++) {
      if (0 <= visibleIndexes[i] && visibleIndexes[i] < menu->getCurrentNode()->sub_nodes.size()) {
        display.setCursor(MenuTree::LEFT_PADDING, MenuTree::ELEMENT_PADDING * (i + 1));
        // display.setTextSize(i == 2 ? 2 : 1);        // Set text size (1 = small, 2 = medium, etc.)
        display.setTextColor(WHITE);
        if (i == 2) {
          display.printf("> %s", menu->getSelected()->getText().c_str());
        }
        else {
          display.print(menu->getAt(visibleIndexes[i])->getText().c_str());
        }
      }
    }
  }
};

