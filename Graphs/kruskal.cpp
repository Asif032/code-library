#include<bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (Edge const& other) const {
    if (w == other.w) {
      return make_pair(u, v) < make_pair(other.u, other.v);
    }
    return w < other.w;
  }
};

struct DSU {
  vector<int> par, rank, size;
  int cc;
  DSU(int n) : par(n + 5, 0), rank(n + 5, 0), size(n + 5, 1), cc(n) {
    for (int i = 1; i <= n; i++) {
      par[i] = i;
    }
  }
  int find(int i) {
    return par[i] == i ? i : par[i] = find(par[i]);
  }
  int get_size(int i) {
    return size[find(i)];
  }
  int cc_count() {
    return cc;
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    cc--;
    if (rank[j] > rank[i]) swap(i, j);
    par[j] = i;
    size[i] += size[j];
    if (rank[i] == rank[j]) rank[i]++;
    return i;
  }
};

long long kruskal(vector<Edge>& edges, int n) {
  DSU dsu(n);
  long long min_cost = 0;
  vector<Edge> mst;
  sort(edges.begin(), edges.end());
  for (auto e : edges) {
    if (dsu.same(e.u, e.v)) continue;
    mst.push_back(e);
    min_cost += e.w;
    dsu.merge(e.u, e.v);
  }
  return dsu.cc_count() == 1 ? min_cost : -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({u, v, w});
    }
    cout << kruskal(edges, n) << '\n';
  }
  return 0;
}