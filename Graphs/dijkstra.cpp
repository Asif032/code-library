#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
vector<pair<int, int>> adj[N];
bool vis[N];
long long dis[N];
int p[N], n, m, x, y, w;

void printPath(int src, int des) {
  vector<int> v;
  for(int i = des; i != src; i = p[i]) {
    v.push_back(i);
  }
  v.push_back(src);
  for(int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << ' ';
  }
  cout << '\n';
}

void dijkstra(int src) {
  priority_queue<pair<long long, int>> q;
  for(int i = 1; i <= n; i++) {
    dis[i] = inf;
    vis[i] = 0;
  }
  dis[src] = 0;
  q.push({0, src});
  while(!q.empty()) {
    int node = q.top().second; q.pop();
    if(vis[node]) continue;
    vis[node] = 1;
    for(auto [to, w] : adj[node]) {
      if(dis[node] + w < dis[to]) {
        dis[to] = dis[node] + w;
        q.push({-dis[to], to});
        p[to] = node;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while(T--) {
    cin >> n >> m;
    while(m--) {
      cin >> x >> y >> w;
      adj[x].push_back({y, w});
      adj[y].push_back({x, w});
    }
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
    }
  }
  return 0;
}