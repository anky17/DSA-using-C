// WAP TO PERFORM VARIOUS OPERATIONS RELATED TO BINARY SEARCH TREE.

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

// Function to perform inorder traversal of BST.
void inorderTraversal(struct node* root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

// Function to check whether a binary tree is a BST or not.
int isBST(struct node* root) {
  // 'prev' is a pointer to the previous node in in-order traversal
  static struct node* prev = NULL;

  // Base case: an empty tree is a BST
  if (root == NULL) {
    return 1;
  }

  // Check the left subtree
  if (!isBST(root->left)) {
    return 0;  // If the left subtree is not a BST, then this tree is not a BST
  }

  // 'prev' should be less than the current node if it's a BST
  if (prev != NULL && root->data <= prev->data) {
    return 0;  // Violation of the BST property
  }

  // Update 'prev' to the current node
  prev = root;

  // Check the right subtree
  return isBST(root->right);
}

// Function to search a specific element from BST using recursive call
int search(struct node* root, int key) {
  if (root == NULL) {
    return -1;
  }
  if (root->data == key) {
    return root->data;
  } else if (key > root->data) {
    search(root->right, key);
  } else {
    search(root->left, key);
  }
}

// Function to search a specific element from BST using iterative approach
int searchIter(struct node* root, int key) {
  while (root != NULL) {
    if (root->data == key)
      return root->data;
    else if (key < root->data)
      root = root->left;
    else
      root = root->right;
  }
  return -1;
}

// Function  to insert the element in the BST
void insertNode(struct node* root, int key) {
  struct node* prev;  // prev' is a pointer to the previous node
  //  Search for the leaf node to add a new node
  while (root != NULL) {
    prev = root;  // Update 'prev' to the current node
    if (root->data == key) {
      printf("Cannot insert %d, already in BST", key);
      return;
    } else if (key < root->data) {
      root = root->left;
    } else {
      root = root->right;
    }
  }

  // Adding the new node and linking it with the prev node
  struct node* newNode = createNode(key);  // Node Creation
  // Linking it with prev node a/c to BST condition
  if (key < prev->data) {
    prev->left = newNode;
  } else {
    prev->right = newNode;
  }
}

// Function to find the inorder Predecessor(Largest of the left subtree)
struct node* inorderPredecessor(struct node* root) {
  root = root->left;
  while (root->right != NULL) {
    root = root->right;
  }
  return root;  // inorder predecessor
}

// Function to delete a node from the BST
struct node* deleteNode(struct node* root, int key) {
  // Base case: If root is NULL, the key isn't present in the tree
  if (root == NULL) return NULL;
  if (root->left == NULL && root->right == NULL) {
    free(root);
    return NULL;
  }

  // Search for a node to delete
  if (key < root->data) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  }

  // Deletion case for the root node
  else {
    struct node* inPre = inorderPredecessor(root);
    root->data = inPre->data;
    root->left = deleteNode(root->left, inPre->data);
  }

  // Return the (possibly updated) root pointer
  return root;
}

int main() {
  // Constructing the node
  struct node* root;
  struct node* p = createNode(8);
  struct node* p1 = createNode(6);
  struct node* p2 = createNode(10);
  struct node* p3 = createNode(4);
  struct node* p4 = createNode(7);
  struct node* p5 = createNode(9);
  struct node* p6 = createNode(19);

  root = p;  // root holds the address of p which is the root node

  // Linking the root node with left and right children
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;
  p2->left = p5;
  p2->right = p6;

  // To check if BST
  if (isBST(root))
    printf("Tree is BST\n");
  else
    printf("Tree is not BST\n");

  // Various operations

  int data = search(root, 198);
  if (data == -1)
    printf("Element not found\n");
  else
    printf("Element found: %d\n", data);

  int data1 = searchIter(root, 19);
  if (data1 == -1)
    printf("Element not found");
  else
    printf("Element found: %d\n", data1);

  printf("Before Insertion: ");
  inorderTraversal(root);  // BST inorder traversal follows ascending order
  insertNode(root, 2);
  printf("\nAfter Insertion: ");
  inorderTraversal(root);  // BST inorder traversal follows ascending order
  deleteNode(root, 19);
  printf("\nAfter deletion: ");
  inorderTraversal(root);
  return 0;
}

/*

Output

Tree is BST
Element not found
Element found: 19
Before Insertion: 4 6 7 8 9 10 19
After Insertion: 2 4 6 7 8 9 10 19
After deletion: 2 4 6 7 8 9 10
*/
