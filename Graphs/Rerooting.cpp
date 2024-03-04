#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int sub[N];
long long dp[N], res = 0;

void dfs(int node, int par) {
  sub[node] = 1;
  dp[node] = 0;
  for (int to : adj[node]) {
    if (to != par) {
      dfs(to, node);
      sub[node] += sub[to];
      dp[node] += dp[to];
    }
  }
  dp[node] += sub[node];
}

void dfs1(int node, int par) {
  res = max(res, dp[node]);
  for (int to : adj[node]) {
    if (to != par) {
      dp[node] -= dp[to];
      dp[node] -= sub[to];
      sub[node] -= sub[to];

      sub[to] += sub[node];
      dp[to] += dp[node];
      dp[to] += sub[node];

      dfs1(to, node);

      sub[to] -= sub[node];
      dp[to] -= dp[node];
      dp[to] -= sub[node];

      dp[node] += dp[to];
      dp[node] += sub[to];
      sub[node] += sub[to];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  dfs1(1, -1);
  cout << res << '\n';
  return 0;
}