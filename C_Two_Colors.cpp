/*
    Great things take time, Just keep showing up everyday.

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
    vector<ll> v(m); for(int i = 0 ; i < m ; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> suff = v;
    suff.push_back(0);
    for(int i = m - 1 ; i >= 0 ; i--){
        suff[i] += suff[i+1];
    }
    ll idx = distance(v.begin(), lower_bound(v.begin(), v.end(), n));
    ll val = m - idx;
    ll ans = ((n-1)*val*(val - 1))/2;
    for(int i = 0 ; i < m ; i++){
        if(i == idx) break;
        auto it = lower_bound(v.begin(), v.end(), n - v[i]);
        ll idx1 = distance(v.begin(), it);
        idx1 = max(idx1, (ll)i+1);
        if(idx1 < idx){
            ll range = (idx - idx1);
            ans += (suff[idx1] - suff[idx]) + range*(v[i] + 1 - n);
        }
        ans += (m-idx)*v[i];
    }
    cout << 2*ans << "\n";
}

int main(){
    fast_io();
    ll t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}