#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int spf[N];
vector<int> primes;

void sieve() {
  for (int i = 2; i < N; i++) {
    if (spf[i] == 0) {
      spf[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < primes.size() && i * primes[j] < N; j++) {
      spf[i * primes[j]] = primes[j];
      if (spf[i] == primes[j]) {
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