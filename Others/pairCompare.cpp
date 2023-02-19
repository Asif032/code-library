#include<bits/stdc++.h>
using namespace std;

struct compare {  // for binary_search, upper_bound, lower_bound
  bool operator() (const pair<int, int>& value, const int& key) {
    return (value.first < key);
  }
  bool operator() (const int& key, const pair<int, int>& value) {
    return (key < value.first);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while(T--) {
    
  }
  return 0;
}