#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 20;
vector<int> adj[N];
int par[N][M], level[N];

void dfs(int node, int p, int l) {
  par[node][0] = p;
  level[node] = l;
  for (int to : adj[node]) {
    if (to != p) {
      dfs(to, node, l + 1);
    }
  }
}

int LCA(int x, int y) {
  if (level[x] < level[y]) {
    swap(x, y);
  }
  int d = level[x] - level[y];
  while (d > 0) {
    int k = (int) log2(d);
    x = par[x][k];
    d -= (1 << k);
  }
  if (x == y) {
    return x;
  }
  for (int i = M - 1; i >= 0; i--) {
    if (par[x][i] != -1 && par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  }
  return par[x][0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  memset(par, -1, sizeof par);
  dfs(1, -1, 0);
  int m = (int) log2(n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (par[i][j - 1] != -1) {
        par[i][j] = par[par[i][j - 1]][j - 1];
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << "LCA(" << x << ", " << y << ") = " << LCA(x, y) << '\n';
  }
  return 0;
}