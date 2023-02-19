#include<bits/stdc++.h>
using namespace std;

long long p;

long long power(long long a, long long b) {
  long long res = 1;
  while(b) {
    if(b % 2 == 1) res = (res * a) % p;
    a = (a * a) % p;
    b /= 2;
  }
  return res;
}

long long inverse(long long a, long long p) {
  return power(a, p - 2);
}

int main() {
  long long a, b;
  cin >> a >> p;
  cout << inverse(a, p);
  return 0;
}