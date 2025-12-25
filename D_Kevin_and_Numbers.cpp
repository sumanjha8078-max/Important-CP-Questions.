/*
    Quote of the Day : 
 
        "Jingle Bells, Jingle Bells, Jingle all the way, Oh what fun it is to ride
         in a One horse open sleigh"

                                    - James Pierpont
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
    vector<ll> v(n); for(int i = 0 ; i < n ; i++) cin >> v[i];
    vector<ll> b(m); for(int i = 0 ; i < m ; i++) cin >> b[i];
    multiset<ll> st, st1;
    for(int i = 0 ; i < n ; i++) st.insert(v[i]);
    for(int i = 0 ; i < m ; i++) st1.insert(b[i]);
    while((!st.empty()) && (!st1.empty())){
        auto it = st.end(), it1 = st1.end();
        it--, it1--;
        ll mx1 = *it, mx2 = *it1;
        if(mx1 > mx2){
            cout << "No" << "\n";
            return;
        }
        else if(mx1 < mx2){
            st1.erase(it1);
            if(mx2 % 2 == 0){
                st1.insert(mx2/2);
                st1.insert(mx2/2);
            }
            else{
                st1.insert(mx2/2);
                st1.insert(mx2/2 + 1);
            }
        }
        else{
            st.erase(it);
            st1.erase(it1);
        }
        if(st.size() < st1.size()){
            cout << "No" << "\n";
            return;
        }
    }
    if(st.size() == st1.size()) cout << "Yes" << "\n";
    else cout << "No" << "\n";
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
// Froday, December 25, 2025
