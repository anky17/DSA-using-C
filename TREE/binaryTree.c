// WAP TO PERFORM VARIOUS OPERATIONS ON BINARY TREE.

#include <stdio.h>
#include <stdlib.h>

// Node creation using struct
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Function to create a node for the binary tree
struct node* createNode(int data) {
  struct node* Node;  // Creating a node pointer.
  Node = (struct node*)malloc(sizeof(struct node));
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  return Node;  // Returning the created node.
}

// Function to perform preorder traversal of binary tree.
void preorderTraversal(struct node* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

// Function to perform inorder traversal of binary tree.
void inorderTraversal(struct node* root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

// Function to perform postorder traversal of binary tree.
void postorderTraversal(struct node* root) {
  if (root != NULL) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  // Constructing the node
  struct node* root;
  struct node* p = createNode(2);
  struct node* p1 = createNode(1);
  struct node* p2 = createNode(4);
  struct node* p3 = createNode(6);
  struct node* p4 = createNode(7);
  struct node* p5 = createNode(5);
  struct node* p6 = createNode(9);
  struct node* p7 = createNode(8);
  struct node* p8 = createNode(0);

  root = p;
  // Linking the root node with left and right children
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;
  p2->left = p5;
  p2->right = p6;
  p3->left = p7;
  p3->right = p8;

  printf("Pre-order Traversal:\n");
  preorderTraversal(root);
  printf("\nPoat-order Traversal:\n");
  postorderTraversal(root);
  printf("\nIn-order Traversal:\n");
  inorderTraversal(root);
  return 0;
}

/*

Output

Pre-order Traversal:
2 1 6 8 0 7 4 5 9
Poat-order Traversal:
8 0 6 7 1 5 9 4 2
In-order Traversal:
8 6 0 1 7 2 5 4 9

*/