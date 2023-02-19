#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
string s[N];
bool vis[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
// int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
// int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
// int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool isValid(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  return (!vis[x][y] && s[x][y] == '.');
}

void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], Y = y + dy[i];
    if (isValid(xx, Y)) dfs(xx, Y);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isValid(i, j)) {
        dfs(i, j);
        res++;
      }
    }
  }
  cout << res << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) vis[i][j] = 0;
  }
  return 0;
}