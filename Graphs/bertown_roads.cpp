#include<bits/stdc++.h>
using namespace std;

vector<int> a[100005];
bool vis[100005], hasBridge;
int in[100005], low[100005], timer;
vector<pair<int, int>> res;

void dfs(int node, int par) {
  vis[node] = 1;
  in[node] = low[node] = timer++;
  for(int to : a[node]) {
    if(to == par) continue;
    if(vis[to]) {
      low[node] = min(low[node], in[to]);
      if(in[node] > in[to]) res.push_back({node, to});
    } else {
      dfs(to, node);
      if(low[to] > in[node]) {
        hasBridge = 1;
        return;
      }
      low[node] = min(low[node], low[to]);
      res.push_back({node, to});
    }
  }
}
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, x, y;
  cin >> n >> m;
  while(m--) {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dfs(1, -1);
  if(hasBridge) {
    cout << 0 << '\n';
  } else {
    for(auto x : res) {
      cout << x.first << ' ' << x.second << '\n';
    }
  }
  return 0;
}