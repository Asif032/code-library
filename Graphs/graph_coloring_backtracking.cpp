#include<bits/stdc++.h>
using namespace std;

string s = "#RGB";
vector<int> a[101];
int res;
int col[101];
int n, m, x, y;

void print() {
  for(int i = 1; i <= n; i++) {
    cout << s[col[i]] << ' ';
  }
  cout << '\n';
}
void graph_coloring(int v) {

  if(v == n + 1) {
    print();
    res++;
    return;
  }
  for(int i = 1; i < s.size(); i++) {
    col[v] = i;
    bool flag = true;
    for(int to : a[v]) {
      if(col[to] == col[v]) {
        flag = false;
        break;
      }
    }
    if(flag == true) graph_coloring(v + 1);
    col[v] = 0;
  }
}
int main() {

  cin >> n >> m;
  while(m--) {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  graph_coloring(1);
  cout << "Total number of solutions : " << res << '\n';
  return 0;
}

/*
6 6
1 2
2 3
3 4
4 5
5 6
6 1
*/