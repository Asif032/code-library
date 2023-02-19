#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> a(N + 5);
vector<pair<int, int>> t(4 * N + 5);

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {   // modify this
  if(a.first < b.first) return a;
  if(a.first > b.first) return b;
  return {a.first, a.second + b.second};
}

void build(int x, int lx, int rx) {
  if(lx == rx) {
    t[x].first = a[lx];
    t[x].second = 1;
    return;
  }
  int mid = (lx + rx) / 2;
  build(2 * x + 1, lx, mid);
  build(2 * x + 2, mid + 1, rx);
  t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
}

void update(int i, int v, int x, int lx, int rx) {
  if(lx == rx) {
    t[x].first = v;
    t[x].second = 1;
    return;
  }
  int mid = (lx + rx) / 2;
  if(i <= mid) {
    update(i, v, 2 * x + 1, lx, mid);
  } else {
    update(i, v, 2 * x + 2, mid + 1, rx);
  }
  t[x] = merge(t[2 * x + 1], t[2 * x + 2]);  
}

pair<int, int> query(int l, int r, int x, int lx, int rx) {
  if(lx > r || rx < l) return {INT_MAX, 0};
  if(lx >= l && rx <= r) return t[x];
  int mid = (lx + rx) / 2;
  auto lc = query(l, r, 2 * x + 1, lx, mid);
  auto rc = query(l, r, 2 * x + 2, mid + 1, rx);
  return merge(lc, rc);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, 0, n - 1);
  while(m--) {
    int type;
    cin >> type;
    if(type == 1) {
      int i, v;
      cin >> i >> v;
      update(i, v, 0, 0, n - 1);
    } else {
      int l, r;
      cin >> l >> r;
      auto x = query(l, r, 0, 0, n - 1);
      cout << x.first << ' ' << x.second << '\n';
    }
  }
  return 0;
}