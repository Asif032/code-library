#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  s += '$';
  int n = s.size();
  vector<int> p(n), c(n);
  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = {s[i], i};
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    p[i] = a[i].second;
  }
  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i].first == a[i - 1].first) {
      c[p[i]] = c[p[i - 1]];
    } else {
      c[p[i]] = c[p[i - 1]] + 1;
    }
  }
  int k = 0;
  while ((1 << k) < n) {
    vector<pair<pair<int, int>, int>> temp(n);
    for (int i = 0; i < n; i++) {
      temp[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
      p[i] = temp[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (temp[i].first == temp[i - 1].first) {
        c[p[i]] = c[p[i - 1]];
      } else {
        c[p[i]] = c[p[i - 1]] + 1;
      }
    }
    k++;
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << " \n"[i == n - 1];
  }
  return 0;
}