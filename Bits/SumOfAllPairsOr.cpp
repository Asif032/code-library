#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("inputf.in", "r", stdin);
  int n, x;
  cin >> n;
  int p = 31 - __builtin_clz((int) 1e9);
  vector<vector<int>> cnt(p + 1, vector<int> (2));  // size of cnt == log2(max(a[i]))
  // no need to declare 2D vector, cnt[0] can be found by n - cnt[1]
  for(int i = 0; i < n; i++) {
    cin >> x;
    for(int j = 0; j <= p; j++) {
      cnt[j][(x >> j) & 1]++;
    }
  }
  long long sum = 0;
  for(int i = 0; i <= p; i++) {
    sum += (1 << i) * 1LL * (cnt[i][0] * 1LL * cnt[i][1] + cnt[i][1] * 1LL * (cnt[i][1] - 1) / 2);
  }
  cout << sum << '\n';
  return 0;
}