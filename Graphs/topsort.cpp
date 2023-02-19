#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int indegree[N];
vector<int> res;
int n, m;

void topsort() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    res.push_back(node);
    for (int to : adj[node]) {
      indegree[to]--;
      if (indegree[to] == 0) {
        q.push(to);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    indegree[y]++;
    adj[x].push_back(y);
  }
  topsort();
  if (res.size() != n) {
    cout << -1 << '\n';
    return 0;
  }
  for (int x : res) {
    cout << x << ' ';
  }
  cout << '\n';
  res.clear();
  return 0;
}