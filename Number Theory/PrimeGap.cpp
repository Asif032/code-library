#include<bits/stdc++.h>
using namespace std;

bool prime(int n) {
  for(int i = 2; i * i <= n; i++) {
    if(n % i == 0) return false;
  }
  return true;
}
int main() {
  // conjecture : next prime of n is in within the range of (log(n))^2
  // for 10^9 its ~= 900

  int n; cin >> n;
  n++;
  while(!prime(n)) n++;
  cout << n << '\n';
  return 0;
}