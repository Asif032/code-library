#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int lps[N];

void build(string s) {
  lps[0] = 0;
  for (int i = 1; i < s.size(); i++) {
    int j = lps[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = lps[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    lps[i] = j;
  }
}

vector<int> kmp(string t, string s) {
  int n = t.size();
  int m = s.size();
  int j = 0;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (t[i] == s[j]) {
      j++;
      if (j == m) {
        res.push_back(i - m + 2);
        j = lps[j - 1];
      }
    } else if (j != 0) {
      j = lps[j - 1];
      i--;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    
  }
  return 0;
}
