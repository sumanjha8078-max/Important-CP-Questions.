/*
    Quote of the Day : 
 
        "Two roads diverged in a wood, and I took the one less travelled by,
            and that has made all the difference.	                            -Robert Frost"
 
*/
 
#define ll long long
#define mod (1000000007)
 
#include <bits/stdc++.h>
using namespace std;
 
void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

bool bipartite(vector<vector<ll>>& adj, vector<ll>& color, ll node){
    color[node] = 0;
    queue<pair<ll,ll>> q;
    q.push({node,0});
    while(!q.empty()){
        ll x = q.front().first, y = q.front().second;
        q.pop();
        for(ll t : adj[x]){
            if(color[t] == y) return true;
            if(color[t] == -1){
                ll y1 = 0;
                if(y1 == y) y1 = 1;
                q.push({t,y1});
                color[t] = y1;
            }
        }
    }
    return false;
}
 
void solve(ll count){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> color(n+1,-1);
    for(int i = 1 ; i <= n ; i++){
        if(color[i] == -1){
            if(bipartite(adj, color, i)){
                cout << "Scenario #" << count << ": \nSuspicious bugs found!" << "\n";
                return;
            }
        }
    }
    cout << "Scenario #" << count << ": \nNo suspicious bugs found!" << "\n";
}
 
int main(){
    fast_io();
    ll Test_Cases = 1; cin >> Test_Cases;
    ll count = 1;
    while(Test_Cases--){
        solve(count);
        count++;
    }
    return 0;
}
 
// Author : Krishna Chandra Jha
// Country : INDIA
// Wednesday, December 17, 2025
