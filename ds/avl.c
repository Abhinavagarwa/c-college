#include <stdio.h>
#include <stdlib.h>
struct Node {
   int key, height;
   struct Node *left, *right; };
   int max(int a, int b) {
   return (a > b) ? a : b;}
   int height(struct Node* node) {
   return (node == NULL) ? 0 : node->height;}
   struct Node* newNode(int key) {
   struct Node* node = (struct Node*)malloc(sizeof(struct Node));
   node->key = key;
   node->left = node->right = NULL;
   node->height = 1;
   return node;}
   Node* rightRotate(struct Node* y) {
   struct Node* x = y->left;
   struct Node* T2 = x->right;
   x->right = y;
   y->left = T2;
   y->height = max(height(y->left), height(y->right)) + 1;
   x->height = max(height(x->left), height(x->right)) + 1;
   return x;}
   struct Node* leftRotate(struct Node* x) {
   struct Node* y = x->right;
   struct Node* T2 = y->left;
   y->left = x;
   x->right = T2;
   x->height = max(height(x->left), height(x->right)) + 1;
   y->height = max(height(y->left), height(y->right)) + 1;
   return y;}
struct Node* insert(struct Node* node, int key) {
   if (node == NULL) return newNode(key);
   if (key < node->key) node->left = insert(node->left, key);
   else if (key > node->key) node->right = insert(node->right, key);
   else return node;
   node->height = 1 + max(height(node->left), height(node->right));
   int balance = height(node->left) - height(node->right);
   if (balance > 1 && key < node->left->key) return rightRotate(node);
   if (balance < -1 && key > node->right->key) return leftRotate(node);
   if (balance > 1 && key > node->left->key) {
       node->left = leftRotate(node->left);
       return rightRotate(node);}
   if (balance < -1 && key < node->right->key) {
       node->right = rightRotate(node->right);
       return leftRotate(node);}
return node;}
struct Node* minValueNode(struct Node* node) {
   struct Node* current = node;
   while (current->left != NULL)
       current = current->left;
   return current;}
struct Node* deleteNode(struct Node* root, int key) {
   if (root == NULL) return root;
   if (key < root->key) root->left = deleteNode(root->left, key);
   else if (key > root->key) root->right = deleteNode(root->right, key);
   else {
       if ((root->left == NULL) || (root->right == NULL)) {
           struct Node* temp = root->left ? root->left : root->right;
           if (temp == NULL) {
               temp = root;
               root = NULL;
           } else
               *root = *temp;
           free(temp);
       } else {
           struct Node* temp = minValueNode(root->right);
           root->key = temp->key;
           root->right = deleteNode(root->right, temp->key);}
    if (root == NULL) return root;
   root->height = 1 + max(height(root->left), height(root->right));
   int balance = height(root->left) - height(root->right);
   if (balance > 1 && height(root->left->left) >= 0) return rightRotate(root);
   if (balance > 1 && height(root->left->left) < 0) {
       root->left = leftRotate(root->left);
       return rightRotate(root);}
   if (balance < -1 && height(root->right->right) <= 0) return leftRotate(root);
   if (balance < -1 && height(root->right->right) > 0) {
       root->right = rightRotate(root->right);
       return leftRotate(root);}
   return root;}
void printTree(struct Node* root, int level) {
   if (root != NULL) {
       printTree(root->right, level + 1);
       for (int i = 0; i < level; i++)
           printf("\t");
       printf("%d\n", root->key);
       printTree(root->left, level + 1);}}
int main() {
   struct Node* root = NULL;
   root = insert(root, 10);
   root = insert(root, 20);
 root = insert(root, 30);
   root = insert(root, 40);
   root = insert(root, 50);
   root = insert(root, 25);
printf("AVL Tree after insertions:\n"); 
   printTree(root, 0);
root = deleteNode(root, 30);
printf("\nAVL Tree after deletion of 30:\n");
   printTree(root, 0);
return 0;
}