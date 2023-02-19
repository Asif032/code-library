#include<bits/stdc++.h>
using namespace std;

/* detecting all the cycles in a grapht is a NP Hard problem
   we can not find all the cycles with a single dfs
*/
const int N = 1e5 + 5;
vector<int> adj[N];
int col[N], p[N];
int n, m;

void dfs(int node, int par) {
  col[node] = 1;
  for(int to : adj[node]) {
    if(col[to] == 0) {
      p[to] = node;
      dfs(to, node);
    } else if (col[to] == 1 && to != par) {
      cout << "cycle detected\n";
      cout << to << ' ';
      for (int i = node; i != to; i = p[i]) {
        cout << i << ' ';
      }
      cout << to << '\n';
    }
  }
  col[node] = 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  bool cycle = false;
  for (int i = 1; i <= n; i++) {
    if (col[i] == 0) {
      dfs(i, -1);
    }
  }
  return 0;
}