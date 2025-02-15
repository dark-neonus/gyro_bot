#include "MenuTree.h"


#include <memory>
#include <string>

TreeNode::TreeNode(std::string text,
                   std::function<void(std::shared_ptr<MenuTree>)> actionFunction_,
                   std::vector<std::shared_ptr<TreeNode>> sub_nodes_)
  : _text(std::move(text)), sub_nodes(std::move(sub_nodes_))
{
  _selectedIndex = RangeValueInt(0, 0, sub_nodes.size() - 1);

  // Use the provided action function, or the default one
  actionFunction = actionFunction_ ? actionFunction_ : MenuTree::defaultActionFunction;
}

const std::function<void(std::shared_ptr<MenuTree>)> MenuTree::do_nothing = 
  [](std::shared_ptr<MenuTree>) {};

const std::function<void(std::shared_ptr<MenuTree>)> MenuTree::go_back = 
  [](std::shared_ptr<MenuTree> menuTree) {
      menuTree->goBack();
  };

const std::function<void(std::shared_ptr<MenuTree>)> MenuTree::defaultActionFunction = 
  [](std::shared_ptr<MenuTree> menuTree) {
      menuTree->addPath(menuTree->getSelected());
  };
