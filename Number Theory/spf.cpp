#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int spf[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if(spf[i] == i) {
      for(int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
  return 0;
}