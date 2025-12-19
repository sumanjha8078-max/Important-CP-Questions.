/*
    Quote of the Day : 
 
        "Don't lose the moon, while counting for stars."
 
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
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < m ; i++) cin >> b[i];
    ll val = a[0];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll idx = 0;
    for(int i = 0 ; i < n ; i++) if(a[i] == val) idx = i;
    vector<ll> use(m);
    for(int i = 0 ; i < m ; i++){
        auto it = lower_bound(a.begin(),a.end(),b[i]);
        if(*it <= a[idx]) use[i] = 1;
        else use[i] = distance(it, a.end()) + 1;
    }
    sort(use.begin(),use.end());

    for(int i = 1 ; i <= m; i++){
        ll sum = 0;
        for(int j = i ; j <= m ; j+=i){
            sum += use[j-1];
        }
        cout << sum << " ";
    }
    cout << "\n";
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
// Thursday, December 18, 2025
