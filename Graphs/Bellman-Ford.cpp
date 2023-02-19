#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 5;
const long long INF = 1e18;
vector<tuple<int, int, int>> edges;
long long dis[maxN];
int p[maxN];
int n, m, x, y, w, src, des;

void printPath(int des, int src) {
  vector<int> v;
  for(int i = des; i != src; i = p[des]) {
    v.push_back(i);
  }
  v.push_back(src);
  for(int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << ' ';
  }
  cout << '\n';
}

void bellman_ford() {
  for(int i = 1; i <= n; i++) dis[i] = INF;
  dis[src] = 0;
  for(int i = 1; i <= n - 1; i++) {
    for(auto e : edges) {
      tie(x, y, w) = e;
      if(dis[x] + w < dis[y]) {
        dis[y] = dis[x] + w;
        p[y] = x;
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
    
  }
  return 0;
}