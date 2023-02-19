#include<iostream>
#include<vector>
using namespace std;

int lower_bound(vector<int> a, int l, int r, int x) {
  int res = -1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(a[mid] > x) {
      res = mid;
      r = mid - 1;
    } else if(a[mid] < x) {
      l = mid + 1;
    } else {
      res = mid;
      r = mid - 1;
    }
  }
  return res;
}

int main() {
  vector<int> a{1, 2, 2, 2, 4, 4, 4, 7};
  cout << lower_bound(a, 0, a.size() - 1, 3);
  return 0;
}