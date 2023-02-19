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
    for (char ch : word) {
      if (node->next[ch - 'a'] == NULL) {
        node->next[ch - 'a'] = new Node();
      }
      node = node->next[ch - 'a'];
      node->pref++;
    }
    node->word++;
  }

  bool search(string word) {
    Node* node = root;
    for (char ch : word) {
      if (node->next[ch - 'a'] == NULL) {
        return false;
      }
      node = node->next[ch - 'a'];
    }
    return (node->word != 0);
  }

  bool isPrefix(string word) {
    Node* node = root;
    for (char ch : word) {
      if (node->next[ch - 'a'] == NULL) {
        return false;
      }
      node = node->next[ch - 'a'];
    }
    return true;
  }

  int countWords(string word) {
    Node* node = root;
    for (char ch : word) {
      if (node->next[ch - 'a'] == NULL) {
        return 0;
      }
      node = node->next[ch - 'a'];
    }
    return node->word;
  }

  int countPrefix(string word) {
    Node* node = root;
    for (char ch : word) {
      if (node->next[ch - 'a'] == NULL) {
        return 0;
      }
      node = node->next[ch - 'a'];
    }
    return node->pref;
  }

  void deleteWord(string word) {
    Node* node = root;
    for (char ch : word) {
      if (node->next[ch - 'a'] == NULL) {
        return;
      }
      node = node->next[ch - 'a'];
    }
    node->pref--;
    if (node->word) node->word--;
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