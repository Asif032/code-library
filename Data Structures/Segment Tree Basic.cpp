#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t[4 * N];
const int NEUTRAL_ELEMENT = 0;   // modify this
int a[N];

void build(int x, int lx, int rx) {
  if (lx == rx) {
    t[x] = a[lx];   
    return;
  }
  int mid = (lx + rx) >> 1;
  build(2 * x + 1, lx, mid);
  build(2 * x + 2, mid + 1, rx);
  t[x] = (t[2 * x + 1] | t[2 * x + 2]);   // modify this
}

void update(int i, int v, int x, int lx, int rx) {
  if (lx == rx) {
    t[x] = 1 << v;   // modify this
    return;
  }
  int mid = (lx + rx) >> 1;
  if (i <= mid) {
    update(i, v, 2 * x + 1, lx, mid);
  } else {
    update(i, v, 2 * x + 2, mid + 1, rx);
  }
  t[x] = (t[2 * x + 1] | t[2 * x + 2]);   // modify this
}

int query(int l, int r, int x, int lx, int rx) {
  if (lx > r || rx < l) return NEUTRAL_ELEMENT;
  if (lx >= l && rx <= r) return t[x];
  int mid = (lx + rx) >> 1;
  int lc = query(l, r, 2 * x + 1, lx, mid);
  int rc = query(l, r, 2 * x + 2, mid + 1, rx);
  return (lc | rc);    // modify this
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}