#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int p = 137, mod = 1e9 + 7;

int string_hash(string& s) {
  int hs = 0;
  int pw = 1;
  for (int i = 0; i < s.length(); i++) {
    hs += 1LL * s[i] * pw % mod;
    hs %= mod;
    pw = 1LL * pw * p % mod;
  }
  return hs;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  cout << string_hash(s);
  return 0;
}