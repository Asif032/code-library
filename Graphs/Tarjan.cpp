#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N], scc[N];
int col[N], in[N], low[N];
int timer = 1;

void dfs(int node) {
  col[node] = 1;
  in[node] = low[node] = timer++;
  for (int to : adj[node]) {
    if (col[to] == 0) {
      dfs(to);
      low[node] = min(low[node], low[to]);
    } else if (col[to] == 1) {
      low[node] = min(low[node], in[to]);
    }
  }
  col[node] = 2;
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
  }
  for (int i = 1; i <= n; i++) {
    if (col[i] == 0) {
      dfs(i);
    }
  }
  int scc_count = 0;
  for (int i = 1; i <= n; i++) {
    scc[low[i]].push_back(i);
    if (scc[low[i]].size() == 1) {
      scc_count++;
    }
  }
  cout << scc_count << '\n';
  for (int i = 1; i <= n; i++) {
    if (!scc[i].empty()) {
      for (auto x : scc[i]) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}