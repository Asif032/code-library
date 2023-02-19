#include<bits/stdc++.h>
using namespace std;

int n;

long long sumXor(vector<int>& a) {
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      sum += a[i] ^ a[j];
    }
  }
  return sum;
}

long long sumOr(vector<int>& a) {
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      sum += a[i] |  a[j];
    }
  }
  return sum;
}

long long sumAnd(vector<int>& a) {
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      sum += a[i] &  a[j];
    }
  }
  return sum;
}

int main() {
  freopen("inputf.in", "r", stdin);
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // cout << sumXor(a) << '\n';
  // cout << sumOr(a) << '\n';
  cout << sumAnd(a) << '\n';
  return 0;
}