#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
vector<int> adj[N];
bool vis[N], is_bridge[2 * N], used[2 * N];
int in[N], low[N];
int timer, ec;
vector<pair<int, int>> edges;

void dfs(int node, int par = -1) {
  vis[node] = 1;
  in[node] = low[node] = timer++;
  for (int id : adj[node]) {
    int to = edges[id].second;
    if (to == par) continue;
    if (vis[to]) {
      if (in[node] > in[to]) {
        used[id] = 1;
      }
      low[node] = min(low[node], in[to]);
    } else {
      dfs(to, node);
      low[node] = min(low[node], low[to]);
      if (low[to] > in[node]) {
        is_bridge[id] = 1;
        is_bridge[id ^ 1] = 1;
      } else {
        used[id] = 1;
      }
    }
  }
}

int cc_size;

void dfs1(int node) {
  vis[node] = 1;
  cc_size++;
  for (int id : adj[node]) {
    int to = edges[id].second;
    if (!vis[to] && !is_bridge[id]) {
      dfs1(to);
    }
  }
}

void dfs2(int node) {
  vis[node] = 1;
  for (int id : adj[node]) {
    int to = edges[id].second;
    if (!vis[to]) {
      dfs2(to);
      if (is_bridge[id]) {
        used[id ^ 1] = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    edges.push_back({x, y});
    adj[x].push_back(ec++);
    edges.push_back({y, x});
    adj[y].push_back(ec++);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
  int start = -1, max_size = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cc_size = 0;
      dfs1(i);
      if (cc_size > max_size) {
        max_size = cc_size;
        start = i;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
  dfs2(start);
  cout << max_size << '\n';
  for (int i = 0; i < edges.size(); i++) {
    if (used[i]) {
      cout << edges[i].first << ' ' << edges[i].second << '\n';
    }
  }
  return 0;
}