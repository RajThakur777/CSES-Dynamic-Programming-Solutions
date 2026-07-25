#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const ll mod = 1e9 + 7;

ll dp[1001][1001];

ll solve(ll i , ll j , ll x , ll y , vector<vector<char>> &v) {
  if(i == x-1 && j == y-1 && v[x-1][y-1] != '*') {
    return 1;
  }

  if(i < 0 || i >= x || j < 0 || j >= y || v[i][j] == '*') {
    return 0;
  }

  if(dp[i][j] != -1) {
    return dp[i][j];
  }

  ll right = solve(i , j+1 , x , y , v);
  ll down = solve(i+1 , j , x , y , v);

  return dp[i][j] = (right + down) % mod;
}

int main() {
  ll n;
  cin>>n;

  vector<vector<char>> v(n , vector<char>(n));
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>v[i][j];
    }
  }

  memset(dp , -1 , sizeof(dp));

  ll ans = solve(0 , 0 , n , n , v);

  ans %= mod;

  cout<<ans<<endl;
  return 0;
}