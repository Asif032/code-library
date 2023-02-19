#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int flag[N / 32 + 5];

void sieve() {
  flag[0] |= 3;  // marking 0, 1 as non prime
  for (int i = 2; i * i < N; i++) {
    int id = i / 32, bit = i % 32;
    if (!((flag[id] >> bit) & 1)) {
      for (int j = i * i; j < N; j += i) {
        id = j / 32; bit = j % 32;
        flag[id] |= (1LL << bit);
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