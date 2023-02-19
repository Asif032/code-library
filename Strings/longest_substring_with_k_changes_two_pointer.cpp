#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;

int f(char a) {
  int size = 0, j = 0, cnt = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] != a) cnt++;
    if(cnt > k) {
      while(s[j] == a) j++;
      j++;
      cnt--;
    }
    size = max(size, i - j + 1);
  }
  return size;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> s;
  int res = 0;
  for(int i = 0; i < 26; i++) {
    res = max(res, f('a' + i));
  }
  cout << res << '\n';
  return 0;
}