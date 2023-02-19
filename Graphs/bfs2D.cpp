#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int inf = 1e9;
string s[N];
int dis[N][N], p[N][N];
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
// int dx[] = {1, 0, -1, -1, -1, 0, 1, 1};
// int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool isValid(int x, int y) {
  if (x < 0 || y < 0 || x >= n|| y >= m) return false;
  return (s[x][y] == '.');
}

void bfs(int srcX, int srcY) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dis[i][j] = inf;
    }
  }
  dis[srcX][srcY] = 0;
  queue<pair<int, int>> q;
  q.push({srcX, srcY});
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (isValid(xx, yy) && dis[xx][yy] == inf) {
        dis[xx][yy] = dis[x][y] + 1;
        p[xx][yy] = i;
        q.push({xx, yy});
      }
    }
  }
}

void printPath(int srcX, int srcY, int x, int y) {
  bfs(srcX, srcY);
  vector<pair<int, int>> path;
  while (x != srcX || y != srcY) {
    path.push_back({x, y});
    int deltaX = dx[p[x][y]];
    int deltaY = dy[p[x][y]];
    x -= deltaX;
    y -= deltaY;
  }
  path.push_back({srcX, srcY});
  reverse(path.begin(), path.end());
  cout << path.size() - 1 << '\n';
  for (auto [x, y] : path) {
    cout << x << ' ' << y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  bfs(0, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++) {
      if (dis[i][j] == inf) {
        cout << i << ' ';
      } else {
        cout << dis[i][j] << ' ';
      }
    }
    cout << '\n';
  }
  printPath(0, 0, 1, 5);
  return 0;
}