#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int f[N], invf[N];

int power(int a, int b) {
  int res = 1 % mod; a %= mod; if (a < 0) a += mod;
  while (b) {
    if (b & 1) res = 1LL * res * a % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return res;
}

int nCr(int n, int r) {
  if (n < 0 || n < r) {
    return 0;
  }
  return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}

int nPr(int n, int r) {
  if (n < 0 || n < r) {
    return 0;
  }
  return 1LL * f[n] * invf[n - r] % mod;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = 1LL * f[i - 1] * i % mod;
  }
  invf[N - 1] = power(f[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
  }
  int T = 1;
  cin >> T;
  while (T--) {
    
  }
  return 0;
}