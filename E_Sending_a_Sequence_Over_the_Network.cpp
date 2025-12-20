/*
    Quote of the Day : 
 
        "If you are the smartest person in the room, you are in the wrong room."    

                                                                          -Confucius
 
*/
 
#define ll long long
#define mod (1000000007)
 
#include <bits/stdc++.h>
using namespace std;
 
void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve(){
    ll n; cin >> n;
    vector<ll> v(n); for(int i = 0 ; i < n ; i++) cin >> v[i];
    vector<bool> dp(n+1,false);
    dp[0] = true;
    for(int i = 1 ; i <= n ; i++){
        if(i - v[i-1] >= 1 && dp[i] == false) dp[i] = dp[i-v[i-1]-1];
        if(i + v[i-1] <= n && dp[i+v[i-1]] == false) dp[i+v[i-1]] = dp[i-1];
    }
    if(dp[n]) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
 
int main(){
    fast_io();
    ll Test_Cases = 1; cin >> Test_Cases;
    while(Test_Cases--){
        solve();
    }
    return 0;
}
 
// Author : Krishna Chandra Jha
// Country : INDIA
// Saturday, December 20, 2025
