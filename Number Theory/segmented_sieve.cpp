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
    for (int j = 0; j < primes.size() && primes[j] <= spf[i] && i * primes[j] < N; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int T = 1;
  cin >> T;
  while(T--) {
    int l, r;
    cin >> l >> r;
    vector<bool> seg(r - l + 5);
    for (int i = 0; 1LL * primes[i] * primes[i] <= r; i++) {
      int start = l + (primes[i] - l % primes[i]) % primes[i];
      for (int j = start; j <= r; j += primes[i]) {
        if (j != primes[i]) {
          seg[j - l] = 1;
        }
      }
    }
    if (l == 1) {
      seg[0] = 1;
    }
    for (int i = l; i <= r; i++) {
      if (!seg[i - l]) {
        cout << i << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}
