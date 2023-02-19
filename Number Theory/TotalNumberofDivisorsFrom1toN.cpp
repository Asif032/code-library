#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int d[N];
long long sum[N];

int main() {
  for(int i = 1; i < N; i++) {
    for(int j = i; j < N; j += i) {
      d[j]++;
      sum[j] += i; // sum of divisors of j
    }
  }
  return 0;
}