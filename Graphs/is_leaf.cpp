int bst::is_leaf(tree_node *curr, tree_node *parent) {
  if (curr->left == NULL && curr->right == NULL) {
    if (parent->left == curr) {
      parent->left = NULL;
    }
    else {
      parent->right = NULL;
    }
    delete curr;
    return true;
    }
  
  else return false;
}

if(is_leaf(curr, parent) == true) return;
