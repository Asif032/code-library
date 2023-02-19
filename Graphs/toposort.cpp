#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> a[N];
int in[N];
vector<int> res;

void kahn(int n) {
  queue<int> Q;
  for(int i = 1; i <= n; i++) {
    if(in[i] == 0) Q.push(i);
  }
  while(!Q.empty()) {
    int node = Q.front();
    res.push_back(node);
    Q.pop();
    for(int to : a[node]) {
      in[to]--;
      if(in[to] == 0) Q.push(to);
    }
  }
}

int main() {
  int n, m, x, y;
  cin >> n >> m;
  while(m--) {
    cin >> x >> y;
    a[x].push_back(y);
    in[y]++;
  }
  kahn(n);
  for(auto x : res) {
    cout << x << ' ';
  }
  cout << '\n';
  res.clear();
  return 0;
}