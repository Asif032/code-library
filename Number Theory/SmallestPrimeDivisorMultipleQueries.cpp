#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> spf(N);
int main() {
  for(int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    for(int j = i; j < N; j += i) {
      spf[j] = min(spf[j], i);
    }
  }
  // for(int i = 2; i <= 100; i++) {
  //   cout << i << ' ' << spf[i] << '\n';
  // }

  
  // prime factorization of a number using spf
  int q; cin >> q;
  while(q--) {
    int n; cin >> n;
    vector<int> primes;
    while(n > 1) {
      primes.push_back(spf[n]);
      n /= spf[n];
    }
    for(auto x : primes) cout << x << ' '; cout << '\n';
  }
  return 0;
}