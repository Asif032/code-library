#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
ll tc;

ll gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
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

void shift_solution(ll &x, ll &y, ll a, ll b, ll k) {
  x += k * b;
  y -= k * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
  if(a == 0 && b == 0) {
    return (c != 0 ? 0LL : abs(maxx - minx + 1) * abs(maxy - miny + 1));
  }
  ll x, y, g;
  if(!find_any_solution(a, b, c, x, y, g)) return 0;
  if(a == 0) return (c / b >= miny && c / b <= maxy ? abs(maxx - minx + 1) : 0LL);
  if(b == 0) return (c / a >= minx && c / a <= maxx ? abs(maxy - miny + 1) : 0LL);
  a /= g;
  b /= g;
  ll sign_a = a > 0 ? +1 : -1;
  ll sign_b = b > 0 ? +1 : -1;;

  shift_solution(x, y, a, b, (minx - x) / b);
  if(x < minx) shift_solution(x, y, a, b, sign_b);
  if(x > maxx) return 0;
  ll lx1 = x;

  shift_solution(x, y, a, b, (maxx - x) / b);
  if(x > maxx) shift_solution(x, y, a, b, -sign_b);
  ll rx1 = x;

  shift_solution(x, y, a, b, -(miny - y) / a);
  if(y < miny) shift_solution(x, y, a, b, -sign_a);
  if(y > maxy) return 0;
  ll lx2 = x;

  shift_solution(x, y, a, b, -(maxy - y) / a);
  if(y > maxy) shift_solution(x, y, a, b, sign_a);
  ll rx2 = x;

  if(lx2 > rx2) swap(lx2, rx2);
  ll lx = max(lx1, lx2);
  ll rx = min(rx1, rx2);
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