#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bitset<10> a(n);
  // xor of 4 consecutive numbers(starting with 0) is 0.
  // because even number xor (even number + 1) = 1, 1 xor 1 = 0.
  int m = n % 4;
  int x = 0;
  for(int i = n - m + 1; i <= n; i++) {
    bitset<10> y(i);
    cout << i << ' ' << y << '\n';
    x ^= i;
  }
  bitset<10> b(x);
  // cout << n << ' ' << a << '\n';
  cout << x << ' ' << b << '\n';
  return 0;
}