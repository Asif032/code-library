#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int res = INT_MAX;
  do {
    int mx = -1, mn = INT_MAX, cur = 0;
    for (auto x : a) {
      cout << x << ' ';
      mx = max(x, mx);
      mn = min(x, mn);
      cur += mx - mn;
    }
    cout << '\n';
    cout << cur << "\n\n";
    res = min(res, cur);
  } while (next_permutation(a.begin(), a.end()));
  cout << res << '\n';
  return 0;
}