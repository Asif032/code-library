#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef complex<ld> pt;

struct circ { pt C; ld R; };

/**
 * builtin pt operations:
 * +, -: usual vector addition/subtraction
 * *, /: scalar multiplication/division (also complex multiplication / division if that's ever useful)
 * abs(p): vector length
 * norm(p): squared vector length888
 * arg(p): angle p forms with positive x axis
 * polar(r, th): vector with length r pointing in direction th
 * conj(p): reflects p over x axis
 */

#define X real()
#define Y imag()
#define CRS(a, b) (conj(a) * (b)).Y //scalar cross product
#define DOT(a, b) (conj(a) * (b)).X //dot product
#define U(p) ((p) / abs(p)) //unit vector in direction of p (don't use if Z(p) == true)
#define Z(x) (abs(x) < EPS)
#define A(a) (a).begin(), (a).end() //shortens sort(), upper_bound(), etc. for vectors

//constants (INF and EPS may need to be modified)
constexpr ld PI = acosl(-1), INF = 1e30, EPS = 1e-12;
constexpr pt I = {0, 1}, INV = {INF, INF};

namespace std {
  //lexicographical comparison
  bool operator<(pt a, pt b) { return Z(a.X - b.X) ? a.Y < b.Y : a.X < b.X; }
}

struct line {
  pt P, D;
  bool S; 

  // Two points
  line (pt a, pt b, bool s=0) : P(a), D(b-a), S(s) {}

  // Point and angle
  line (pt a, ld theta) : P(a), D(polar(1.l, theta)), S(0) {}
};

//true if d1 and d2 parallel (zero vectors considered parallel to everything)
bool parallel(pt d1, pt d2) { return Z(d1) || Z(d2) || Z(CRS(U(d1), U(d2))); }

//true if p is on line l
bool on_line(pt p, line l) { return parallel(l.P - p, l.D) && (!l.S || DOT(l.P - p, l.P + l.D - p) <= 0); }

pt intsct(line l1, line l2) {
  if (parallel(l1.D, l2.D)) return INV;
  pt p = l1.P + l1.D * CRS(l2.D, l2.P - l1.P) / CRS(l2.D, l1.D);
  return on_line(p, l1) && on_line(p, l2) ? p : INV;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pt p = {3, 5};
  cout << p.X << ' ' << p.Y << '\n';
  cout << abs(p) << ' ' << norm(p) << ' ' << arg(p) << '\n';
  pt q = polar(4.0, .5);
  cout << q.X << ' ' << q.Y << '\n';
  return 0;
}