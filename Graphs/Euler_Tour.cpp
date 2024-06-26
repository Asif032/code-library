#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int tin[N], tout[N], flat[N];
int timer;

void dfs(int node, int par) {
  tin[node] = ++timer;
  for (int to : adj[node]) {
    if (to != par) {
      dfs(to, node);
    }
  }
  tout[node] = timer;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << i << ' ' << tin[i] << ' ' << tout[i] << '\n';
  }
  for (int i = 1; i <= n; i++) {
    flat[tin[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << flat[i] << " \n"[i == n];
  }
  return 0;
}