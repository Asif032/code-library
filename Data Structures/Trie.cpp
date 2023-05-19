#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node* next[26];
  int word = 0;
  int pref = 0;
};

struct Trie {
  Node* root;
  Trie() {
    root = new Node();
  }

  void insert(string word) {
    Node* node = root;
    for (char x : word) {
      if (node->next[x - 'a'] == NULL) {
        node->next[x - 'a'] = new Node();
      }
      node = node->next[x - 'a'];
      node->pref++;
    }
    node->word++;
  }

  int countWords(string word) {
    Node* node = root;
    for (char x : word) {
      if (node->next[x - 'a'] == NULL) {
        return 0;
      }
      node = node->next[x - 'a'];
    }
    return node->word;
  }

  int countPrefix(string word) {
    Node* node = root;
    for (char x : word) {
      if (node->next[x - 'a'] == NULL) {
        return 0;
      }
      node = node->next[x - 'a'];
    }
    return node->pref;
  }

  bool isEmpty(Node* node) {
    for (int i = 0; i < 26; i++) {
      if (node->next[i]) {
        return false;
      }
    }
    return true;
  }
  
  Node* remove(Node* node, string &key, int depth) {
    if (node == NULL) {
      return NULL;
    }
    if (depth == key.size()) {
      if (node->word) {
        node->word--;
      }
      if (isEmpty(node) && !node->word) {
        delete node;
        node = NULL;
      }
      return node;
    }
    int id = key[depth] - 'a';
    node->next[id] = remove(node->next[id], key, depth + 1);
    if (isEmpty(node) && !node->word) {
      delete(node);
      node = NULL;
    }
    return node;
  }

  void remove(string word) {
    root = remove(root, word, 0);
  }

  void clear(Node* node) {
    for (int i = 0; i < 26; i++) {
      if (node->next[i]) {
        clear(node->next[i]);
      }
    }
    delete node;
  }

  void clear() {
    clear(root);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    Trie trie;
    
    trie.clear();
  }
  return 0;
}