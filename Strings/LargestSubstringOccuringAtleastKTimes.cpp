#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
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
  int ip1 = power(p1, mod1 - 2, mod1);
  int ip2 = power(p2, mod2 - 2, mod2);
  pw[0] = {1, 1};
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

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

int n, k;

int max_oc(int len) {
  map<pair<int, int>, int> mp;
  map<pair<int, int>, int> id;
  for (int i = 0; i + len - 1 < n; i++) {
    auto hs = get_hash(i, i + len -1);
    mp[hs]++;
    id[hs] = i;
  }
  for (auto [x, y] : mp) {
    if (y >= k) return id[x];
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  prec();
  string s;
  cin >> s;
  cin >> k;
  n = s.length();
  build(s);
  int l = 1, r = n, len = 0, id = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    int x = max_oc(mid);
    if (x != -1) {
      len = mid;
      l = mid + 1;
      id = x;
    } else {
      r = mid - 1;
    }
  }
  cout << s.substr(id, len);
  return 0;
}