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
    ll l = 0, r = v[1] - v[0], ans = 0;
    for(int i = 1 ; i < n ; i++){
        ll u = l, u1 = r;
        l = max(v[i] - v[i-1] - u1, 0LL);
        r = max(v[i] - v[i-1] - u, 0LL);
        ll l1 = 0, r1 = v[i] - v[i-1];
        if(i != n - 1) r1 = min(r1, v[i+1] - v[i]);
        if(l >= r){
            l = 0, r = r1;
            continue;
        }
        if(r1 <= l || l1 >= r){
            l = 0, r = r1;
        }
        else{
            l = max(l, l1), r = min(r, r1);
            ans++;
        }

    }
    cout << ans << "\n";
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
