#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
bool vis[8][8];
int dis[8][8];
int a, b, c, d, n = 8;
priority_queue<pair<int, int>, int> q;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool isValid(int x, int y) {
  if(x < 0 || y < 0 || x > 7 || y > 7) return false;
  if(vis[x][y]) return false;
  return true;
}

void dijkstra() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) dis[i][j] = INF, vis[i][j] = false;
  }
  bool ok = true;
  dis[a][b] = 0;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      int x = -1, y = -1;
      for(int k = 0; k < 8; k++) {
        for(int l = 0; l < 8; l++)
        if(!vis[k][l] && ((x == -1 && y == -1) || dis[k][l] < dis[x][y])) x = k, y = l;
      }
      // if(i == 0 && j == 0) printf("%d %d\n", x, y);
      if(dis[x][y] == INF) {
        ok = false;
        break;
      }
      vis[x][y] = true;
      for(int k = 0; k < 8; k++) {
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
  freopen("input.txt", "r", stdin);
  while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    dijkstra();
  }
  return 0;
}