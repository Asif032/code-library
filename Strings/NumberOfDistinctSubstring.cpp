#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;
pair<int, int> pref[N], pw[N], ipw[N];

int power(int a, int b, int mod) {
  int res = 1;
  while(b) {
    if(b & 1) res = 1LL * res * a % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return res;
}

void prec() {
  pw[0] = {1, 1};
  int ip1 = power(p1, mod1 - 2, mod1);
  int ip2 = power(p2, mod2 - 2, mod2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(string& s) {
  pair<int, int> hs({0, 0});
  for (int i = 0; i < s.length(); i++) {
    hs.first = (1LL * hs.first * p1 + s[i]) % mod1;
    hs.second = (1LL * hs.second * p2 + s[i]) % mod2;
  }
  return hs;
}

void build(string& s) {
  for (int i = 0; i < s.length(); i++) {
    pref[i].first = (1LL * s[i] * pw[i].first) % mod1;
    if (i > 0) {
      pref[i].first = (pref[i - 1].first + pref[i].first) % mod1;
    }
    pref[i].second = (1LL * s[i] * pw[i].second) % mod2;
    if (i > 0) {
      pref[i].second = (pref[i - 1].second + pref[i].second) % mod2;
    }
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

long long number_of_substrings(int n) {
  long long res = 0;
  for (int len = 1; len <= n; len++) {
    set<pair<int, int>> hs;
    for (int i = 0; i + len - 1 < n; i++) {
      hs.insert(get_hash(i, i + len - 1));
    }
    res += hs.size();
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  prec();
  string s;
  cin >> s;
  build(s);
  cout << number_of_substrings(s.length());
  return 0;
}