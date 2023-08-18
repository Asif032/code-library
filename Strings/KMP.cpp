#include<bits/stdc++.h>
using namespace std;

string text, pattern;
int lps[200000];

void build() {
  lps[0] = 0;
  for (int i = 1; i < pattern.size(); i++) {
    int j = lps[i - 1];
    while (j > 0 && pattern[i] != pattern[j]) {
      j = lps[j - 1];
    }
    if (pattern[i] == pattern[j]) j++;
    lps[i] = j;
  }
}

int kmp() {
  int n = text.size();
  int m = pattern.size();
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (text[i] == pattern[j]) {
      j++;
      if (j == m) return i - m + 2;
    } else if (j != 0) {
      j = lps[j - 1];
      i--;
    }
  }
  return -1;
}

int main() {
  cin >> pattern;
  build();
  for (int i = 0; i < pattern.size(); i++) {
    cout << lps[i] << ' ';
  }
  return 0;
}
