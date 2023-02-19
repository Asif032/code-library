#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
bool isprime[N];
vector<int> primes;

void sieve() {
  for (int i = 2; i < N; i++) {
    if (isprime[i] == 0) {
      primes.push_back(i);
    }
    for (int p : primes) {
      if (i * p > N) {
        break;
      }
      isprime[i * p] = 1;
      if (i % p == 0) {
        break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int T = 1;
  cin >> T;
  while (T--) {

  }
  return 0;
}