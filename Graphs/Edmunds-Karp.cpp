#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int inf = 1e9;
vector<int> adj[N];
int capacity[N][N];
int n, m;

int bfs(int s, int t, vector<int>& par) {
  fill(par.begin(), par.end(), -1);
  par[s] = 0;
  queue<pair<int, int>> q;
  q.push({s, inf});
  while (!q.empty()) {
    int node = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int to : adj[node]) {
      if (par[to] == -1 && capacity[node][to]) {
        par[to] = node;
        int new_flow = min(flow, capacity[node][to]);
        if (to == t) {
          return new_flow;
        }
        q.push({to, new_flow});
      }
    }
  }
  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> par(n + 5);
  int new_flow;
  while (new_flow = bfs(s, t, par)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = par[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back(y);
    adj[y].push_back(x);
    capacity[x][y] = w;
  }
  int s, t;
  cin >> s >> t;
  cout << maxflow(s, t) << '\n';
  return 0;
}