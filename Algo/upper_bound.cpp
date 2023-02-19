#include<iostream>
#include<vector>
using namespace std;

int upper_bound(vector<int> a, int l, int r, int x) {
  int res = -1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(a[mid] > x) {
      r = mid - 1;
    } else if(a[mid] < x) {
      res = mid;
      l = mid + 1;
    } else {
      res = mid;
      l = mid + 1;
    }
  }
  return res + 1;
}
int main() {
  vector<int> a{1, 2, 3, 3, 4, 4, 4, 5, 6, 6};
  cout << upper_bound(a, 0, a.size() - 1, 9);
  return 0;
}