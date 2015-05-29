#include <iostream>

using namespace std;

//Begin the construction of the BINARY TREE
struct tree_node {
  tree_node *left;
  tree_node *right;
  int data;
};

//Declaring the class
class bst {
  tree_node *root; //creating the root of the binary tree
  
  public:
    bst() {
      root = NULL; //intialize the default construction, set the root to NULL
    }
    
    int is_empty() { //check for empty graph
      return (root == NULL);
    }
    
    //Manipulating the Binary Tree
    void insert(int item);
    void remove_it(int value); //difficult implementation
    
    //Graph Traversal of Binary Tree
    void in_order_trav();
    void in_order(tree_node *);
    void pre_order_trav();
    void pre_order(tree_node *);
    void post_order_trav();
    void post_order(tree_node *);
};

void bst::insert(int item) {
  tree_node *p = new tree_node;
  tree_node *parent;
  p->left = NULL;
  p->right = NULL;
  parent = NULL;
  
  if (is_empty()) {
    root = p;
  }
  else {
    tree_node *ptr;
    ptr = root;
    
    while (ptr != NULL) {
      parent = ptr;
      
      if (item > ptr->data)
        ptr = ptr->right;
      else
        ptr = ptr->left;
    }
    
    if (item < parent->data) 
      parent->left = p;
    else
      parent->right = p;
  }
}
/*************In Order Traversal*****************************/
// Begin
void bst::in_order_trav() {
  in_order(root);
}

void bst::in_order(tree_node *ptr) {
  if (ptr!=NULL) {
    in_order(ptr->left);
    cout << " " << ptr->data << "     ";
    in_order(ptr->right);
  }
}
// End
/***********************************************************/

/*************Pre Order Traversal*****************************/
// Begin
void bst::pre_order_trav() {
  pre_order(root);
}

void bst::pre_order(tree_node *ptr) {
  if (ptr!=NULL) {
    cout << "  " << ptr->data << "     ";
    pre_order(ptr->left);
    pre_order(ptr->right);
  }
}
// End
/***********************************************************/

/*************Post Order Traversal*****************************/
// Begin
void bst::post_order_trav() {
  post_order(root);
}

void bst::post_order(tree_node *ptr) {
  if(ptr!=NULL) {
    post_order(ptr->left);
    post_order(ptr->right);
    cout << "  " << ptr->data << "     ";
  }
}
// End
/***********************************************************/

int main() {
  bst bin_tree; //create the Binary Tree
  bin_tree.insert(20);
  bin_tree.insert(30); 
  bin_tree.insert(52);  
  bin_tree.insert(254); 
  bin_tree.insert(2); 
  bin_tree.insert(24); 
  bin_tree.insert(2); 
  bin_tree.insert(42); 
  bin_tree.insert(59); 
  bin_tree.in_order_trav(); //in order traversal
  bin_tree.pre_order_trav(); //pre order traversal
  bin_tree.post_order_trav(); //post order traversal
}

