#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const long long inf = 1e18;
long long dis[N][N];
int n;

void floyd() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = inf;
    }
    dis[i][i] = 0;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if(dis[i][k] < inf && dis[k][j] < inf) {
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    cin >> n;
  }
  return 0;
}