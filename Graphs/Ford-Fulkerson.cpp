#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int inf = 1e9;
vector<int> adj[N];
int capacity[N][N];
int vis[N];
int s, t;
int maxflow;

int augment(int node, int flow) {
  vis[node] = 1;
  if (node == t) {
    return flow;
  }
  for (int to : adj[node]) {
    if (!vis[to] && capacity[node][to]) {
      int bottle_neck = augment(to, min(flow, capacity[node][to]));
      if (bottle_neck) {
        capacity[node][to] -= bottle_neck;
        capacity[to][node] += bottle_neck;
        return bottle_neck;
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back(y);
    adj[y].push_back(x);
    capacity[x][y] = w;
  }
  cin >> s >> t;
  int flow;
  while (flow = augment(s, inf)) {
    maxflow += flow;
    memset(vis, 0, sizeof vis);
  }
  cout << maxflow << '\n';
  return 0;
}