#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int phi[N];

void sieve() {
  for (int i = 0; i < N; i++) {
    phi[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) {
        phi[j] -= phi[j] / i;
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