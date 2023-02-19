#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("inputf.in", "r", stdin);
  int n, x;
  cin >> n;
  int p = 31 - __builtin_clz((int) 1e9);
  vector<int> f(p + 1);   // the ith element stores the number of set bits in ith position of all the numbers present in the array
  for(int i = 0; i < n; i++) { 
    cin >> x;
    int j = 0;
    while(x) {
      f[j++] += (x & 1);
      x >>= 1;
    }
  }
  long long sum = 0;
  for(int i = 0; i <= p; i++) {
    sum += (1 << i) * 1LL * ((1 << f[i]) - 1);
  }
  cout << sum << '\n';
  return 0;
}