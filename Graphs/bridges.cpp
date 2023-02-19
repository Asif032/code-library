#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int in[N], low[N];
int timer;
vector<pair<int, int>> bridges;
vector<pair<int, int>> backedges;

void dfs(int node, int par = -1) {
  vis[node] = 1;
  in[node] = low[node] = timer++;
  for (int to : adj[node]) {
    if (to == par) continue;
    if (vis[to]) {
      if (in[node] > in[to]) {
        backedges.push_back({node, to});
      }
      low[node] = min(low[node], in[to]);
    } else {
      dfs(to, node);
      low[node] = min(low[node], low[to]);
      if (low[to] > in[node]) {
        bridges.push_back({node, to});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  cout << bridges.size() << '\n';
  for (auto [x, y] : bridges) {
    cout << x << ' ' << y << '\n';
  }
  return 0;
}