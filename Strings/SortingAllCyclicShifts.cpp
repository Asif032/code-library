#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;
pair<int, int> pref[N], ipw[N];

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
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

void build(string& s) {
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

string s;
int n;

int LCP(int i, int j, int x, int y) {
  int l = 1, r = min(j - i, y - x) + 1, res = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (get_hash(i, i + mid - 1) == get_hash(x, x + mid - 1)) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return res;
}

bool compare(int& a, int& b) {
  int lcp = LCP(a, a + n - 1, b, b + n - 1);
  if (lcp == n) return false;
  return s[a + lcp] < s[b + lcp];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  prec();
  cin >> s;
  n = s.length();
  s += s;
  build(s);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = i;
  }
  sort(a.begin(), a.end(), compare);
  for (auto x : a) {
    cout << s.substr(x, n) << '\n';
  }
  return 0;
}