#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int in[N], out[N];
bool vis[N];
int n, m, x, y;
vector<int> path;

int dfs(int node) {
  vis[node] = 1;
  for(int to : adj[node]) {
    if(!vis[to]) {
      return 1 + dfs(to);
    }
  }
  return 1;
}

int cc_count() {
  int res = 0;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      int x = dfs(i);
      if(x > 1) res++;
    }
  }
  return res;
}

bool hasEuilerianPath() {
  if(cc_count() > 1) return false;
  int start_point = 0, end_point = 0;
  for(int i = 1; i <= n; i++) {
    if(abs(out[i] - in[i]) > 1) return false;
    if(out[i] - in[i] == 1) {
      start_point++;
    } else if(in[i] - out[i] == 1) {
      end_point++;
    }
  }
  if(start_point == 0 && end_point == 0) return true;
  if(start_point == 1 && end_point == 1) return true;
  return false;
}

int getStartingPoint() {
  int start_point = 1;
  for(int i = 1; i <= n; i++) {
    if(out[i] - in[i] == 1) return start_point;
    if(out[i] > 1) start_point = i;
  }
  return start_point;
}

void dfs1(int node) {
  while(out[node]) {
    int to = adj[node][--out[node]];
    dfs(to);
  }
  path.push_back(node);
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    in[x]++; out[x]++;
    in[y]++; out[y]++;
  }
  if(hasEuilerianPath() == false) {
    cout << -1 << '\n';
  } else {
    int start_point = getStartingPoint();
    dfs1(start_point);
    // path.push_back(start_point);
    cout << path.size() << '\n';
    if(path.size() != m + 1) {
      cout << -1 << '\n';
    } else {
      reverse(path.begin(), path.end());
      for(auto x : path) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}