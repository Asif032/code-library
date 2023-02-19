#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int maxDepth, src = 1;

void dfs(int node, int p, int depth) {
  if (depth > maxDepth) {
    maxDepth = depth;
    src = node;
  }
  for (int to : adj[node]) {
    if (to != p) {
      dfs(to, node, depth + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1, 0);
  maxDepth = 0;
  int start = src;
  dfs(src, -1, 0);
  int end = src;
  cout << "End points of the diameter : " << start << ' ' << end << '\n';
  cout << "Diameter of the tree : " <<  maxDepth << '\n';
  return 0;
}