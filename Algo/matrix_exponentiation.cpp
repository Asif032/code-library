#include<bits/stdc++.h>
using namespace std;

const int N = 105;

typedef long long ll;
const ll mod = 1e9 + 7;

vector<vector<ll>> multiplyMatrix(vector<vector<ll>> &A, vector<vector<ll>> &B) {
  ll r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
  vector<vector<ll>> res(r1, vector<ll> (c2));
  for(ll i = 0; i < r1; i++) {
    for(ll j = 0; j < c2; j++) {
      for(ll k = 0; k < c1; k++) {
        res[i][j] += A[i][k] * B[k][j] % mod;
        res[i][j] %= mod;
      }
    }
  }
  return res;
}

vector<vector<ll>> power(vector<vector<ll>> &M, ll n) {
  ll m = M.size();
  vector<vector<ll>> I(m, vector<ll>(m));
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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while(T--) {
    int dim, n;
    cin >> dim >> n;
    vector<vector<ll>> M(dim, vector<ll>(dim));
    for(int i = 0; i < dim; i++) {
      for(int j = 0; j < dim; j++) {
        cin >> M[i][j];
      }
    }
    power(M, n);
    for(int i = 0; i < dim; i++) {
      for(int j = 0; j < dim; j++) {
        cout << M[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}