#include<bits/stdc++.h>
using namespace std;

using T = __int128;

T ext_gcd(T a, T b, T& x, T& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  T x1, y1;
  T d = ext_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

pair<T, T> CRT(T a1, T m1, T a2, T m2) {
  T p, q;
  T g = ext_gcd(m1, m2, p, q);
  if (a1 % g != a2 % g) return {0, -1};
  T m = m1 / g * m2;
  p = (p % m + m) % m;
  q = (q % m + m) % m;
  return {(a1 * (m2 / g) % m * q % m + a2 * (m1 / g) % m * p % m) % m, m};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), m(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> m[i];
  }
  T a1 = a[0];
  T m1 = m[0];
  bool ok = true;
  for (int i = 1; i < n; i++) {
    T a2 = a[i];
    T m2 = m[i];
    auto r = CRT(a1, m1, a2, m2);
    a1 = r.first;
    m1 = r.second;
    if (a1 == 0 && m1 == -1) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << (int) a1 << ' ' << (int) m1 << '\n';
  } else {
    cout << "No solution exists.\n";
  }
  return 0;
}