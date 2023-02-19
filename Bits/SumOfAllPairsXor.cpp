#include<bits/stdc++.h>
using namespace std;

int main() {
  // n <= 10^5, a[i] <= 10^5
  // have to find out sum of all possible pairs xor (Sum of a[i] ^ a[j], i < j <= n);
  // if we think about only for a[i] <= 1 then it's only the problem of cnt[0] * cnt[1]
  // and for a n bit integer ith bit of two numbers can contribute 2^i to the sum if those two bits are not same
  // so for each number in the array the ith bit contributes cnt[i][0] * cnt[i][1] * 2^i to the sum

  freopen("inputf.in", "r", stdin);
  int n, x;
  cin >> n;
  int p = 31 - __builtin_clz(100000); // log
  cout << p << '\n';
  vector<vector<int>> cnt(p + 1, vector<int> (2));
  for(int i = 0; i < n; i++) {
    cin >> x;
    for(int j = 0; j <= p; j++) {
      cnt[j][(x >> j) & 1]++;
    }
  }
  long long sum = 0;
  for(int i = 0; i <= p; i++) {
    sum += cnt[i][0] * 1LL * cnt[i][1] * 1LL * (1 << i);
  }
  cout << sum << '\n';
  return 0;
}