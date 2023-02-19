#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll tc;

vector<vector<ll>> multiplyMatrix(vector<vector<ll>> &A, vector<vector<ll>> &B) {
  ll r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
  vector<vector<ll>> res(r1, vector<ll> (c2));
  for(ll i = 0; i < r1; i++) {
    for(ll j = 0; j < c2; j++) {
      for(ll k = 0; k < c1; k++) {
        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }
  return res;
}

vector<vector<ll>> power(vector<vector<ll>> &M, ll n) {
  ll m = M.size();
  vector<vector<ll>> I(m, vector<ll> (m));
  for(int i = 0; i < m; i++) {
    I[i][i] = 1;
  }
  while(n) {
    if(n % 2 == 1) I = multiplyMatrix(I, M);
    M = multiplyMatrix(M, M);
    n /= 2;
  }
  return I;
}

ll nth_term(ll n) {
  if(n == 0) return 0;
  vector<vector<ll>> M(2, vector<ll> (2, 1));
  vector<vector<ll>> F(1, vector<ll> (2, 1));
  M[0][0] = 0;
  M = power(M, n - 1);
  F = multiplyMatrix(F, M);
  return F[0][0];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll T = 1;
  cin >> T;
  while(T--) {
    ll n;
    cin >> n;
    // cout << "Case " << ++tc << ": ";
    // cout << "F("<< n <<") = ";
    cout << nth_term(n) << '\n';
  }
  return 0;
}