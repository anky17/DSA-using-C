// // WAP TO PERFORM VARIOUS OPERATIONS RELATED TO AVL TREE

#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
};

int max(int a, int b) { return (a > b) ? a : b; }

struct node *newNode(int key) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;  // new node is initially added at leaf
  return (node);
}

int height(struct node *N) {
  if (N == NULL) return 0;
  return N->height;
}

struct node *rightRotate(struct node *y) {
  struct node *x = y->left;
  struct node *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  // Return new root
  return x;
}

//   y       Left Rotate             x
//  / \     - -- - - - - ->        /   \
// T1  x     Right Rotate(y)      y     T3
//    / \   - - - - - - - ->     / \   / \
//   T2 T3                      T1 T2 T2

struct node *leftRotate(struct node *x) {
  struct node *y = x->right;
  struct node *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  // Return new root
  return y;
}

int getBalance(struct node *N) {
  if (N == NULL) return 0;
  return height(N->left) - height(N->right);
}

struct node *insert(struct node *node, int key) {
  /* 1. Perform the normal BST insertion */
  if (node == NULL) return (newNode(key));

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else  // Equal keys are not allowed in BST
    return node;

  /* 2. Update height of this ancestor node */
  node->height = 1 + max(height(node->left), height(node->right));

  /* 3. Get the balance factor of this ancestor node to check whether
     this node became unbalanced */
  int balance = getBalance(node);

  // If this node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && key < node->left->key) return rightRotate(node);

  // Right Right Case
  if (balance < -1 && key > node->right->key) return leftRotate(node);

  // Left Right Case
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  /* return the (unchanged) node pointer */
  return node;
}

// A utility function to print preorder traversal of the tree.

void preOrder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 6);
  root = insert(root, 10);
  root = insert(root, 4);
  root = insert(root, 7);
  root = insert(root, 9);

  printf("Preorder traversal of the constructed AVL tree is \n");
  preOrder(root);

  return 0;
}
