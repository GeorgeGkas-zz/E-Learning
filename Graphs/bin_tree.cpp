#include <iostream>
#include <queue>

using std::cout;
using std::queue;
using std::endl;

struct tree_node {
  tree_node *left;
  tree_node *right;
  int data;
};

class bst {
  tree_node *root; 
  
  public:
    bst() {
      root = NULL;
    }
    
    int is_empty() { 
      return (root == NULL);
    }
    
    //Manipulating the Binary Tree
    void insert(int item);
    void remove(int value);
    
    //Graph Traversal of Binary Tree
    void in_order_trav();
    void pre_order_trav();
    void post_order_trav();
    void dfs();
    void bfs();

  private:
    void in_order(tree_node *);
    void pre_order(tree_node *);
    void post_order(tree_node *);
    void dfs_bst(tree_node *);
    void bfs_bst(tree_node *);
};

void bst::insert(int item) {
  tree_node *p = new tree_node;
  tree_node *parent;
  p->data = item;
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

      if (item > ptr->data) ptr = ptr->right;
      else ptr = ptr->left;
    }

    if (item < parent->data) 
      parent->left = p;
    else
      parent->right = p;
  }
}

void bst::remove(int item) {
  if (is_empty()) {
    cout<<" This Tree is empty! "<<endl;
    return;
  }

  //we look if the value we pass exist in the tree
  bool found = false;
  tree_node* curr;
  tree_node* parent;
  curr = root;

  while (curr != NULL) {
    if (curr->data == item) {
      found = true;
      cout << "element found and removed" << endl;
      break;
    }
    else {
      parent = curr;
      if(item > curr->data) curr = curr->right;
      else curr = curr->left;
    }
  }
  if (!found) {
    cout<<" Data not found! "<<endl;
    return;
  }

  // 3 cases :
  // 1. We're removing a leaf node
  // 2. We're removing a node with a single child
  // 3. we're removing a node with 2 children

  // Node with single child
  if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL)) {
    if (curr->left == NULL && curr->right != NULL) {
      if (parent->left == curr) {
        parent->left = curr->right;
        delete curr;
      }
      else {
        parent->right = curr->left;
        delete curr;
      }
    }
    return;
  }

  //We're looking at a leaf node
  if (curr->left == NULL && curr->right == NULL) {
    if (parent->left == curr) {
      parent->left = NULL;
    }
    else {
      parent->right = NULL;
    }
    delete curr;
    return;
  }

  //Node with 2 children
  // replace node with smallest value in right subtree
  if (curr->left != NULL && curr->right != NULL) {
    tree_node* chkr;
    chkr = curr->right;
    if ((chkr->left == NULL) && (chkr->right == NULL)) {
      curr = chkr;
      delete chkr;
      curr->right = NULL;
    }
    else { 
      // right child has children 
      // if the node's right child has a left child
      // Move all the way down left to locate smallest element

      if ((curr->right)->left != NULL) {
        tree_node* lcurr;
        tree_node* lcurrp;
        lcurrp = curr->right;
        lcurr = (curr->right)->left;
        while (lcurr->left != NULL) {
          lcurrp = lcurr;
          lcurr = lcurr->left;
        }
        curr->data = lcurr->data;
        delete lcurr;
        lcurrp->left = NULL;
      }
      else {
        tree_node* tmp;
        tmp = curr->right;
        curr->data = tmp->data;
        curr->right = tmp->right;
        delete tmp;
      }
    }
    return;
  }
}

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

void bst::post_order_trav() {
  post_order(root);
}

void bst::post_order(tree_node *ptr) {
  if (ptr!=NULL) {
    post_order(ptr->left);
    post_order(ptr->right);
    cout << "  " << ptr->data << "     ";
  }
}

void bst::dfs() {
  dfs_bst(root);
}

void bst::dfs_bst(tree_node *ptr) {
  if (ptr!=NULL) {
    cout << "  " << ptr->data << "     ";
    dfs_bst(ptr->left);
    dfs_bst(ptr->right);
  }
}

void bst::bfs() {
  bfs_bst(root);
}

void bst::bfs_bst(tree_node *ptr) {
  queue<tree_node*> q;

  if (ptr != NULL) {
    q.push(ptr);
    cout << ptr->data << " ";  
  } 
  
  while (!q.empty()) {
    const tree_node * const temp_node = q.front(); 
    q.pop();

    if (temp_node->left != NULL) {
      q.push(temp_node->left);
      cout << temp_node->left->data << " ";
    } 

    if (temp_node->right != NULL) {
      q.push(temp_node->right);
      cout << temp_node->right->data << " ";
    } 
  }
}

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
  cout << "remove" << endl;
  b.remove(15);
  b.dfs();
  cout << endl;
  b.bfs();
  cout << endl;
  return 0;
}
