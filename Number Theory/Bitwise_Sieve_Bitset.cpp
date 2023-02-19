#include<bits/stdc++.h>
using namespace std;

const int N = 1e8 + 5;
bitset<N> is_prime;
vector<int> primes;

void sieve() {
  is_prime[0] = is_prime[1] = 1;
  for (int i = 2; i * i < N; i++) {
    if (!is_prime[i] && 1LL * i * i < N) {
      for (int j = i * i; j < N; j += i) {
        is_prime[j] = 1;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (!is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  return 0;
}