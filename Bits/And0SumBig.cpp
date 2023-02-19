#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 2e5;
vector<int> f(maxN + 5);

int binpow(int a, int b) {
  int res = 1;
  while(b) {
    if(b % 2 == 1) res = (res * 1LL * a) % mod;
    a = (a * 1LL * a) % mod;
    b /= 2;
  }
  return res;
}

int inverse(int a, int p) {
  return binpow(a, p - 2);
}

void fact() {
  f[0] = 1;
  for(int i = 1; i <= maxN; i++) {
    f[i] = (f[i - 1] * 1LL * i) % mod;
  }
}

int c(int n, int k) {
  int res = f[n];
  res = (res * 1LL * inverse(f[n - k], mod)) % mod;
  res = (res * 1LL * inverse(f[k], mod)) % mod;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fact();
  int T = 1;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    n--; k--;
    int res = 0;
    for(int i = 1; i <= k; i++) {
      res = (res + c(n * k, i)) % mod;
    }
    cout << res << '\n';
  }
  return 0;
}