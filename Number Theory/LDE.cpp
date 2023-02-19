#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if(c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

bool find_positive_solution(int a, int b, int c, int &x0, int &y0, int &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if(c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  if(x0 >= 0 && y0 >= 0) return true;
  if(x0 < 0 && y0 < 0) return false;
  int k;
  if(x0 < 0) {
    k = ceil((double) -x0 * g / b);
  } else {
    k = y0 * g / a;
  }
  int x1 = x0 + k * b / g;
  int y1 = y0 - k * a / g;
  if((x0 < 0 && y1 < 0) || (y0 < 0 && x1 < 0)) return false;
  x0 = x1;
  y0 = y1;
  return true;
}

void shift_solution(int &x, int &y, int a, int b, int k) {
  x += k * b;
  y -= k * a;
}

long long find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
  if(a == 0 && b == 0) {
    return (c != 0 ? 0LL : abs(maxx - minx + 1) * 1LL *  abs(maxy - miny + 1));
  }
  int x, y, g;
  if(!find_any_solution(a, b, c, x, y, g)) return 0;
  if(a == 0) return (c / b >= miny && c / b <= maxy ? abs(maxx - minx + 1) : 0);
  if(b == 0) return (c / a >= minx && c / a <= maxx ? abs(maxy - miny + 1) : 0);
  a /= g;
  b /= g;
  int sign_a = a > 0 ? +1 : -1;
  int sign_b = b > 0 ? +1 : -1;;

  shift_solution(x, y, a, b, (minx - x) / b);
  if(x < minx) shift_solution(x, y, a, b, sign_b);
  if(x > maxx) return 0;
  int lx1 = x;

  shift_solution(x, y, a, b, (maxx - x) / b);
  if(x > maxx) shift_solution(x, y, a, b, -sign_b);
  int rx1 = x;

  shift_solution(x, y, a, b, -(miny - y) / a);
  if(y < miny) shift_solution(x, y, a, b, -sign_a);
  if(y > maxy) return 0;
  int lx2 = x;

  shift_solution(x, y, a, b, -(maxy - y) / a);
  if(y > maxy) shift_solution(x, y, a, b, sign_a);
  int rx2 = x;

  if(lx2 > rx2) swap(lx2, rx2);
  int lx = max(lx1, lx2);
  int rx = min(rx1, rx2);
  if(lx > rx) return 0;
  return (rx - lx) / abs(b) + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    
  }
  return 0;
}