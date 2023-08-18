#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 4;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  vector<int> res;
  int mx = 0;
  do {
    set<int> s;
    for (int i = 0; i < n; i++) {
      s.insert(__gcd(a[i], a[(i + 1) % n]));
    }
    if (s.size() > mx) {
      mx = s.size();
      res = a;
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << mx << '\n';
  for (auto x : res) {
    cout << x << ' ';
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  do {
    set<int> s;
    for (int i = 0; i < n; i++) {
      s.insert(__gcd(a[i], a[(i + 1) % n]));
    }
    if (s.size() == mx) {
      for (auto x : a) {
        cout << x << ' ';
      }
      cout << '\n';
      for (int i = 0; i < n; i++) {
        cout << __gcd(a[i], a[(i + 1) % n]) << ' ';
      }
      cout << "\n\n";
    }
  } while (next_permutation(a.begin(), a.end()));
  return 0;
}