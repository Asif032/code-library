#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];

bool dfs(int node, int p) {
  vis[node] = 1;
  for(int to : adj[node]) {
    if(!vis[to]) {
      if (dfs(to, node)) return true;
    } else if (vis[to] && to != p) {
      return true;
    }
  }
  return false;
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
  bool cycle = false;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) {
      if (dfs(i, -1)) {
        cycle = true;
        break;
      }
    }
  }
  cout << (cycle ? "YES\n" : "NO\n");
  return 0;
}