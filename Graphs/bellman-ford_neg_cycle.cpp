#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 1e4 + 5;
const ll INF = 1e18;
vector<tuple<int, int, int>> edges;
ll dis[maxN];
int p[maxN];
int n, m, x, y, w, src = 1, des, v;

void neg_cycle() {
  for(int i = 1; i <= n; i++) {
    dis[i] = 0;
  }
  for(int i = 0; i < n; i++) {
    v = -1;
    for(auto e : edges) {
      tie(x, y, w) = e;
      if(dis[x] + w < dis[y]) {
        dis[y] = dis[x] + w;
        p[y] = x;
        v = y;
      }
    }
  }
  if(v == -1) {
    cout << "No negative cycle detected\n";
    return;
  }
  int y = v;
  for(int i = 1; i <= n; i++) {
    y = p[y];
  }
  vector<int> path;
  for(int cur = y; ; cur = p[cur]) {
    path.push_back (cur);
    if (cur == y && path.size() > 1)
      break;
  }
  reverse (path.begin(), path.end());
  cout << "Negative cycle : ";
  for(int i = 0; i < path.size(); i++) {
    cout << path[i] << ' ';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--) {
    cin >> x >> y >> w;
    edges.push_back({x, y, w});
  }
  neg_cycle();
  return 0;
}