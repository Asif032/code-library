#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
bool f[N];
vector<int> primes;

void sieve() {
  f[0] = f[1] = 1;
  for(int i = 2; i * i < N; i++) {
    if(!f[i]) {
      for(int j = i * i; j < N; j += i) {
        f[j] = 1;
      }
    }
  }
  for(int i = 2; i < N; i++) {
    if(!f[i]) primes.push_back(i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int T = 1, tc = 0;
  cin >> T;
  while(T--) {
    long long n;
    int totalDivisors = 1;
    cin >> n;
    for (int i = 0; i < primes.size() && 1LL * primes[i] * primes[i] <= n; i++) {
      if (n % primes[i] == 0) {
        int p = 0;
        while (n % primes[i] == 0) {
          p++;
          n /= primes[i];
        }
        totalDivisors *= p + 1;
      }
    }
    if (n != 1) {
      totalDivisors *= 2;
    }
    cout << "Case " << ++tc << ": " << totalDivisors - 1 << '\n';
  }
  return 0;
}
