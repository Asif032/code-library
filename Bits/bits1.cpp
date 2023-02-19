#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 11;
  int k = 13;

  // chekcing if the kth bit is set or not
  if(((n >> k) & 1)) {
    cout << "The " << k << " th bit is set\n";
  } else {
    cout << "The " << k << " th bit is not set\n";
  }

  if(n & (1 << k)) {  // alternate method
    cout << "The " << k << " th bit is set\n";
  } else {
    cout << "The " << k << " th bit is not set\n";
  }

  // correct method of left shifting long long
  cout << (1LL << 40) << '\n'; // 1 is left shifted so 1 should be long long

  // setting the kth bit on
  k = 2;
  cout << (n | (1 << k)) << '\n'; // n |= (1 << k) for changing the value of n

  // setting the kth bit off
  k = 1;
  cout << (n & (((1 << 30) - 1) - (1 << k))) << '\n';  // n &= ((1 << 31) - 1) - (1 << k)

  // taking the last k bits and setting off other bits
  
  return 0;
}