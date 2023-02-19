#include<bits/stdc++.h>
using namespace std;

struct Node {
  char data;
  Node* left;
  Node* right;
};

Node* getNewNode(char data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* Insert(Node* root, char data) {
  if(root == NULL) {
    root = getNewNode(data);
  } else if(data <= root->data) {
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }
  return root;
}

void DFS(Node* root) {    // Preorder
  if(root == NULL) return;
  cout << root->data << ' ';
  DFS(root->left);
  DFS(root->right);
}

void BFS(Node* root) {   // Level order
  if(root == NULL) return;
  queue<Node*> Q;
  Q.push(root);
  while(!Q.empty()) {
    Node* current = Q.front();
    cout << current->data << ' ';
    if(current->left != NULL) Q.push(current->left);
    if(current->right != NULL) Q.push(current->right);
    Q.pop();
  }
}

void Inorder(Node* root) {
  if(root == NULL) return;
  Inorder(root->left);
  cout << root->data << ' ';
  Inorder(root->right);
}

void Postorder(Node* root) {
  if(root == NULL) return;
  Inorder(root->left);
  Inorder(root->right);
  cout << root->data << ' ';
}

int main() {
  Node* root = NULL;

  root = Insert(root, 'F');
  root = Insert(root, 'D');
  root = Insert(root, 'J');
  root = Insert(root, 'B');
  root = Insert(root, 'E');
  root = Insert(root, 'G');
  root = Insert(root, 'K');
  root = Insert(root, 'A');
  root = Insert(root, 'C');
  root = Insert(root, 'I');

  cout << "Preorder : ";
  DFS(root);
  cout << '\n';

  cout << "Level order : ";
  BFS(root);
  cout << '\n';

  cout << "Inorder : ";
  Inorder(root);
  cout << '\n';

  cout << "Postorder : ";
  Postorder(root);
  cout << '\n';

  return 0;
}