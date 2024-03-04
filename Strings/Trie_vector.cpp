#include<bits/stdc++.h>
using namespace std;

const int K = 26;

struct Node {
  int next[K];
  bool output = false;

  Node() {
    fill(begin(next), end(next), -1);
  }
};

vector<Node> trie(1);

void insert(string const& s) {
  int v = 0;
  for (char ch : s) {
    int c = ch - 'a';
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = trie.size();
      trie.emplace_back();
    }
    v = trie[v].next[c];
  }
  trie[v].output = true;
}

bool search(string const& s) {
  int v = 0;
  for (char ch : s) {
    int c = ch - 'a';
    if (trie[v].next[c] == -1) {
      return false;
    }
    v = trie[v].next[c];
  }
  return trie[v].output;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    insert(s);
  }
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    cout << search(t) << '\n';
  }
  return 0;
}