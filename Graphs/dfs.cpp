#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];

void dfs(int node) {
  vis[node] = 1;
  for(int to : adj[node]) {
    if(!vis[to]) {
      dfs(to);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}