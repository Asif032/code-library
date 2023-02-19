#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
  long long res = 1;
  while(b) {
    if(b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long res = power(a, b / 2);
  res *= res;
  if(b & 1) res *= a;
  return res;
}

long long power(long long a, long long b) {
  long long res = 1;
  while(b) {
    if(b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  long long a, b;
  cin >> a >>  b;
  cout <<  power(a, b) << '\n';
  return 0;
}