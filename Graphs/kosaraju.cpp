#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N], scc[N];
vector<int> rev[N];
bool vis[N];
int col[N];
vector<int> order;

int scc_count;

void dfs(int node) {
  vis[node] = 1;
  for (int to : adj[node]) {
    if (!vis[to]) dfs(to);
  }
  order.push_back(node);
}

void dfs1(int node) {
  vis[node] = 1;
  col[node] = scc_count;
  scc[scc_count].push_back(node);
  for (int to : rev[node]) {
    if (!vis[to]) dfs1(to);
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
    rev[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
  reverse(order.begin(), order.end());
  for (int x : order) {
    if (!vis[x]) {
      scc_count++;
      dfs1(x);
    }
  }
  cout << "Total number of scc : " << scc_count << '\n';
  for (int i = 1; i <= n; i++) {
    if (!scc[i].empty()) {
      cout << scc[i].size() << '\n';
      for (int x : scc[i]) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}