#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int K = 20;
int a[N], st[K][N];

void build(int n) {
  for (int i = 0; i < n; i++) {
    st[0][i] = a[i];
  }
  for (int i = 1; i < K; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
}

long long query(int l, int r) {
  long long sum = 0;
  for (int i = 0; i < K; i++) {
    if ((1 << i) <= r - l + 1) {
      sum += st[i][l];
      l += 1 << i;
    }
  }
  return sum;
}

int rmq(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(n);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout << rmq(l, r) << '\n';
  }
  return 0;
}