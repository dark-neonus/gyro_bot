#include "MenuTree.h"

TreeNode::TreeNode(std::string text,
                   std::vector<std::shared_ptr<TreeNode>> sub_nodes_,
                   std::function<void(std::shared_ptr<MenuTree>)> actionFunction_)
  : _text(std::move(text)), sub_nodes(std::move(sub_nodes_))
{
  _selectedIndex = RangeValueInt(0, 0, sub_nodes.size() - 1);

  // Use the provided action function, or the default one
  actionFunction = actionFunction_ ? actionFunction_ : MenuTree::defaultActionFunction;
}

const std::function<void(std::shared_ptr<MenuTree>)> MenuTree::do_nothing = 
  [](std::shared_ptr<MenuTree>) {};

const std::function<void(std::shared_ptr<MenuTree>)> MenuTree::defaultActionFunction = 
  [](std::shared_ptr<MenuTree> menuTree) {
      menuTree->addPath(menuTree->getSelected());
  };