#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
  ll n,x;
  cin>>n>>x;

  vector<ll> v(n);
  for(int i=0; i<n; i++) {
    cin>>v[i];
  }

  vector<ll> dp(x+1 , 1e18);
  dp[0] = 0;

  for(int sum=1; sum<=x; sum++) {
    for(auto c : v) {
      if(sum < c) {
        continue;
      }
      
      dp[sum] = min(dp[sum] , dp[sum - c] + 1);
    }
  }

  if(dp[x] == 1e18) {
    cout<<-1<<endl;
  }
  else {
    cout<<dp[x]<<endl;
  }
  return 0;
}