#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], m[N];

int ext_gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = ext_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

pair<int, int> CRT() {
  int a1 = a[0];
  int m1 = m[0];
  for (int i = 1; i < n; i++) {
    int a2 = a[i];
    int m2 = m[i];
    int p, q;
    ext_gcd(m1, m2, p, q);
    int x = (a1 * m2 * q + a2 * m1 * p) % (m1 * m2);
    a1 = x;
    m1 = m1 * m2;
  }
  if (a1 < 0) {
    a1 += m1;
  }
  return {a1, m1};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> m[i];
  }
  auto res = CRT();
  cout << res.first << ' ' << res.second << '\n';
  return 0;
}