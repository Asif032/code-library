#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int dis[N];

void bfs(int src) {
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
  queue<int> q;
  q.push(src);
  vis[src] = 1;
  dis[src] = 0;
  while (!q.empty()) {
    int node = q.front(); q.pop();
    for (int to : adj[node]) {
      if (!vis[to]) {
        vis[to] = 1;
        dis[to] = dis[node] + 1;
        q.push(to);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}