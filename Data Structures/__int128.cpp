#include<bits/stdc++.h>
using namespace std;

istream& operator >> (istream& in, __int128& x) {
  __int128 f = 1;
  x = 0;
  char c = cin.get();
  while (c < '0' || c > '9') {
    if (c == '-') {
      f = -1;
    }
    c = cin.get();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = cin.get();
  }
  x *= f;
  return in;
}

ostream& operator << (ostream& os, __int128 x) {
  bool neg = false;
  if (x < 0) {
    neg = true;
    x *= -1;
  }
  string res = "";
  while (x) {
    res += x % 10 + '0';
    x /= 10;
  }
  if (neg) {
    res += '-';
  }
  reverse(res.begin(), res.end());
  return os << res;
}

bool cmp(__int128 x, __int128 y) {
  return x < y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  __int128 a, b;
  cin >> a >> b;
  cout << a + b;
  return 0;
}