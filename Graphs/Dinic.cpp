#include<bits/stdc++.h>
using namespace std;

struct Dinic {
  struct Edge {
    int x, y;
    long long cap, flow = 0;
    Edge(int x, int y, long long cap) : x(x), y(y), cap(cap) {}
  };

  const long long inf = 1e18;
  vector<vector<int>> adj;
  vector<Edge> edges;
  vector<int> level, ptr;
  int s, t;
  int n, m = 0;

  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }

  void add_edge(int x, int y, long long cap) {
    edges.emplace_back(x, y, cap);
    adj[x].push_back(m++);
    edges.emplace_back(y, x, 0);   // cap for undirected graphs
    adj[y].push_back(m++);
  }

  bool bfs() {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (int id : adj[node]) {
        int to = edges[id].y;
        long long w = edges[id].cap - edges[id].flow;  // current capacity
        if (w && level[to] == -1) {
          level[to] = level[node] + 1;
          q.push(to);
        }
      }
    }
    return level[t] != -1;
  }

  long long dfs(int node, long long flow) {
    if (node == t) {
      return flow;
    }
    for (int& cid = ptr[node]; cid < (int) adj[node].size(); cid++) {
      int id = adj[node][cid];
      int to = edges[id].y;
      long long w = edges[id].cap - edges[id].flow;
      if (w && level[to] == level[node] + 1) {
        long long bottle_neck = dfs(to, min(flow, w));
        if (bottle_neck) {
          edges[id].flow += bottle_neck;
          edges[id ^ 1].flow -= bottle_neck;
          return bottle_neck;
        }
      }
    }
    return 0;
  }

  long long maxflow() {
    long long _maxflow = 0;
    while (bfs()) {
      fill(ptr.begin(), ptr.end(), 0);
      while (long long flow = dfs(s, inf)) {
        _maxflow += flow;
      }
    }
    return _maxflow;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--; t--;
    Dinic dinic(n, s, t);
    while (m--) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      long long cap;
      cin >> cap;
      dinic.add_edge(x, y, cap);
    }
    cout << dinic.maxflow() << '\n';
  }
  return 0;
}