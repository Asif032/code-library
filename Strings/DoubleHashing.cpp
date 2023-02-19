#include<bits/stdc++.h>
using namespace std;

const int p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;

pair<int, int> string_hash(string& s) {
  pair<int, int> hs({0, 0}), pw({1, 1});
  for (int i = 0; i < s.length(); i++) {
    hs.first += 1LL * s[i] * pw.first % mod1;
    hs.first %= mod1;
    hs.second += 1LL * s[i] * pw.second % mod2;
    hs.second %= mod2;
    pw.first = 1LL * pw.first * p1 % mod1;
    pw.second = 1LL * pw.second * p2 % mod2;
  }
  return hs;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}