#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e15;
bool vis[1001][1001];
ll dis[1001][1001];
int n, m, a, b, c, d;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y) {
  if(x < 1 || y < 1 || x > n || y > m) return false;
  if(vis[x][y]) return false;
  return true;
}

void dijkstra() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) dis[i][j] = INF, vis[i][j] = false;
  }
  bool ok = true;
  dis[a][b] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int x = -1, y = -1;
      for(int k = 0; k < n; k++) {
        for(int l = 0; l < m; l++)
        if(!vis[k][l] && ((x == -1 && y == -1) || dis[k][l] < dis[x][y])) x = k, y = l;
      }
      if(dis[x][y] == INF) {
        ok = false;
        break;
      }
      vis[x][y] = true;
      for(int k = 0; k < 4; k++) {
        int X = x + dx[k], Y = y + dy[k];
        int L = x * X + y * Y;
        if(isValid(X, Y) && dis[x][y] + L < dis[X][Y]) {
          dis[X][Y] = dis[x][y] + L;
        }
      }
    }
    if(!ok) break;
  }
  if(dis[c][d] == INF) {
    printf("%d\n", -1);
  } else {
    printf("%d\n", dis[c][d]);
  }
}
int main() {
  while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    dijkstra();
  }
  return 0;
}