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

/*************Insert Procedure*****************************/
// Begin
void bst::insert(int item) {
  tree_node* t = new tree_node;
   tree_node* parent;
   t->data = item;
   t->left = NULL;
   t->right = NULL;
   parent = NULL;

   // is this a new tree?
   if(is_empty()) root = t;
   else
   {
      //Note: ALL insertions are as leaf nodes
      tree_node* curr;
      curr = root;
      // Find the Node's parent
      while(curr)
      {
         parent = curr;
         if(t->data > curr->data) curr = curr->right;
         else curr = curr->left;
      }

      if(t->data < parent->data)
      {
         parent->left = t;
      }
      else
      {
      parent->right = t;
      }
    }
}
// End
/***********************************************************/

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
  bst b;
  b.insert(52);
  b.insert(25);
  b.insert(50);
  b.insert(15);
  b.insert(40);
  b.insert(45);
  b.insert(20); cout<<"inorder"<<endl;
  b.in_order_trav();
  cout<<endl<<"postorder"<<endl;
  b.post_order_trav();
  cout<<endl<<"preorder"<<endl;
  b.pre_order_trav();
}
