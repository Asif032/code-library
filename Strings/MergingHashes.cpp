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

int power(int a, int b, int mod) {
  int res = 1;
  while(b) {
    if(b & 1) res = 1LL * res * a % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  string str = s;
  auto h1 = string_hash(s);
  int l1 = s.length();
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    str += t;
    auto h2 = string_hash(t);
    int l2 = t.length();
    h1.first += 1LL * h2.first * power(p1, l1, mod1) % mod1;
    h1.first %= mod1;
    h1.second += 1LL * h2.second * power(p2, l1, mod2) % mod2;
    h1.second %= mod2;
    l1 += l2;
  }
  cout << (h1 == string_hash(str));
  return 0;
}