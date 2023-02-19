#include<bits/stdc++.h>
using namespace std;

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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}