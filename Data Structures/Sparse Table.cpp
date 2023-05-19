#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int K = 20;
long long st[N][K];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  copy(a.begin(), a.end(), st[0]);
  for (int i = 1; i < K; i++) {
    for (int j = 0; j + (1 << i) < n; j++) {
      st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int L, R;
    cin >> L >> R;
    long long sum = 0;
    for (int i = K; i >= 0; i--) {
      if ((1 << i) <= R - L + 1) {
        sum += st[i][L];
        L += 1 << i;
      }
    }
    cout << sum << '\n';
  }
  return 0;
}