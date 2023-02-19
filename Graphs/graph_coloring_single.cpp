#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> adj[1005];
string s = "#RGBY";
int n, m, x, y, col[1005];

void printColor() {
  for(int i = 1; i <= n; i++) {
    cout << s[col[i]] << ' ';
  }
  cout << '\n';
}
bool color(int v)  {
  if(v == n + 1) {
    return true;
  }
  for(int i = 1; i < s.size(); i++) {
    bool flag = true;
    col[v] = i;
    for(int to : adj[v]) {
      if(col[to] == col[v]) {
        flag = false;
        break;
      }
    }
    if(flag == false) continue;
    if(color(v + 1) == true) return true;
    col[v] = 0;
  }
  return false; 
}

int main() {
  cin >> n >> m;
  while(m--) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  if(color(1) == true) {
    printColor();
  } else {
    cout << "No solution exists\n";
  }
  return 0;
}
/*
4 6
1 2
2 3
3 4
4 1
1 3
2 4
*/