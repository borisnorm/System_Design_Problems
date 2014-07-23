#include <iostream>
#include <stdlib>

using namespace std;

// Only node under eq are the successors.
struct node {
  char value;
  bool isWord;
  node* left;
  node* eq;
  node* right;
  node(char c) {
    value = c;
    left = eq = right = NULL;
  }
};

node* insert(node* root, string s, int i) {
  if (root == NULL) {
    root = new node(string[i]);
  }
  if (string[i] > root->value) {
    root->right = insert(root->right, s, i);
  } else if (string[i] < root->value) {
    root->left = insert(root->left, s, i);
  } else {
    if (i == s.size() - 1) {
      root->isWord = true;
      return root;
    }
    root->eq = insert(root->eq, s, i+1);
  }
  return root;
}

bool search(node* root, string s, int i) {
  if (root == NULL) {
    return false;
  }
  if (s[i] > root->value) {
    return search(root->left, s, i);
  } else if (s[i] < root->value) {
    return search(root->right, s, i);
  } else {
    if (i == s.size() - 1) {
      return root->isWord;
    }
    return search(root->eq, s, i+1);
  }
}

void traversal(node* root, string tmp) {
  if (root == NULL) {
    return;
  }
  traversal(root->left, tmp);
  string t = tmp+root->value;
  if (root->isWord) {
    traversal(root->eq, t);
  }
  traversal(root->right, tmp);
}
