#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 18;
vector<int> adj[N];
int par[N][M + 1], level[N];

void dfs(int node, int p = 0) {
  par[node][0] = p;
  level[node] = level[p] + 1;
  for (int k = 1; k <= M; k++) {
    par[node][k] = par[par[node][k - 1]][k - 1];
  }
  for (int to : adj[node]) {
    if (to != p) {
      dfs(to, node);
    }
  }
}

int LCA(int u, int v) {
  if (level[u] < level[v]) {
    swap(u, v);
  }
  for (int k = M; k >= 0; k--) {
    if (level[par[u][k]] >= level[v]) {
      u = par[u][k];
    }
  }
  if (u == v) {
    return u;
  }
  for (int k = M; k >= 0; k--) {
    if (par[u][k] != -1 && par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }
  return par[u][0];
}

int dist(int u, int v) {
  int l = LCA(u, v);
  return level[u] + level[v] - 2 * level[l];
}

// kth ancestor of u
int kth(int u, int k) {
  for (int i = 0; i <= M; i++) {
    if (k & (1 << i)) {
      u = par[u][i];
    }
  }
  return u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1);
  return 0;
}