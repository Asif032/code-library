#include<bits/stdc++.h>
using namespace std;

int query(int l, int r) {
  int k = r - l + 1;
  cout << "? " << k << ' ';
  for (int i = l; i <= r; i++) {
    cout << i << ' ';
  }
  cout << endl;
  int sum;
  cin >> sum;
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> pref(n + 5);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      pref[i] = pref[i - 1] + x;
    }
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      int sum = query(l, mid);
      if (sum == pref[mid] - pref[l - 1]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    cout << "! " << l << endl;
  }
  return 0;
}