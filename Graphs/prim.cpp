#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
vector<pair<int, int>> adj[N];
int par[N];
bool mst[N];
long long key[N];
int n, m;

long long prim() {
  for (int i = 1; i <= n; i++) {
    key[i] = inf;
    mst[i] = 0;
  }
  long long res = 0;
  key[1] = 0;
  priority_queue<pair<long long, int>> q;
  q.push({0, 1});
  while (!q.empty()) {
    int node = q.top().second; 
    long long w = -q.top().first;
    q.pop();
    if (mst[node]) continue;
    res += w;
    mst[node] = true;
    for (auto [to, w] : adj[node]) {
      if (mst[to] == false && w < key[to]) {
        key[to] = w;
        q.push({-key[to], to});
        par[to] = node;
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
  cout << prim() << '\n';
  for (int i = 2; i <= n; i++) {
    cout << par[i] << ' ' << i << '\n';
  }
  return 0;
}