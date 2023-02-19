#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
int tc;
vector<vector<int>> p(N + 5, vector<int> (N + 5));
vector<int> spf(N + 5);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 2; i <= N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i <= N; i++) {
    for(int j = i; j <= N; j += i) {
      spf[j] = min(spf[j], i);
    }
  }
  for(int i = 2; i <= N; i++) {
    for(int j = 2; j <= N; j++) {
      p[i][j] = p[i - 1][j];
    }
    int x = i;
    while(x > 1) {
      p[i][spf[x]]++;
      x /= spf[x];
    }
  }
  int T = 1;
  cin >> T;
  while(T--) {
    
  }
  return 0;
}