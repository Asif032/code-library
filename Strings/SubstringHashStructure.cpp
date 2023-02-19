#include<bits/stdc++.h>
using namespace std;

struct hash_table {
  const int p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;
  vector<pair<int, int>> pref, ipw;

  int power(int a, int b, int mod) {
    int res = 1;
    while(b) {
      if(b & 1) res = 1LL * res * a % mod;
      a = 1LL * a * a % mod;
      b >>= 1;
    }
    return res;
  }

  void prec(int n) {
    int ip1 = power(p1, mod1 - 2, mod1);
    int ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < n; i++) {
      ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
      ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
  }

  void build(string& s) {
    int n = s.length();
    pref.resize(n + 5);
    ipw.resize(n + 5);
    prec(n);
    pair<int, int> pw({1, 1});
    for (int i = 0; i < s.length(); i++) {
      pref[i].first = (1LL * s[i] * pw.first) % mod1;
      if (i > 0) {
        pref[i].first = (pref[i - 1].first + pref[i].first) % mod1;
      }
      pref[i].second = (1LL * s[i] * pw.second) % mod2;
      if (i > 0) {
        pref[i].second = (pref[i - 1].second + pref[i].second) % mod2;
      }
      pw.first = 1LL * pw.first * p1 % mod1;
      pw.second = 1LL * pw.second * p2 % mod2;
    }
  }

  pair<int, int> get_hash(int i, int j) {
    assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if (i > 0) {
      hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    }
    hs.first = 1LL * hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if (i > 0) {
      hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    }
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  hash_table h1, h2;
  h1.build(s);
  h2.build(t);
  
  return 0;
}