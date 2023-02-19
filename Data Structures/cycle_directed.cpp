#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int col[N];

bool dfs(int node) {
  col[node] = 1;
  for(int to : adj[node]) {
    if (col[to] == 0) {
      if (dfs(to)) return true;
    } else if (col[to] == 1) {
      return true;
    }
  }
  col[node] = 2;
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
  }
  bool cycle = false;
  for (int i = 1; i <= n; i++) {
    if (col[i] == 0) {
      if (dfs(i)) {
        cycle = true;
        break;
      }
    }
  }
  cout << (cycle ? "YES\n" : "NO\n");
  return 0;
}