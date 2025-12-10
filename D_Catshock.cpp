/*
    Quote of the Day : 
 
        "There is a girl, that always crushes your hopes, and then there are
        friends that offers a bottle of beer to move on, avoid both!!!"
 
*/
 
#define ll long long
#define mod (1000000007)
 
#include <bits/stdc++.h>
using namespace std;
 
void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(vector<vector<ll>>& adj, vector<ll>& vis, vector<vector<ll>>& ans, int node){
    vis[node] = 1;
    queue<ll> q;
    q.push(node);
    while(!q.empty()){
        ll s = q.size();
        vector<ll> use;
        for(int i = 0 ; i < s ; i++){
            ll use1 = q.front();
            q.pop();
            for(int i = 0 ; i < adj[use1].size() ; i++){
                if(!vis[adj[use1][i]]){
                    q.push(adj[use1][i]);
                    vis[adj[use1][i]] = 1;
                }
            }
            use.push_back(use1);
        }
        ans.push_back(use);
    }
}

void dfs(vector<vector<ll>>& adj, vector<ll>& vis, vector<ll>& ans, vector<ll>& use, int node){
    vis[node] = 1;
    use.push_back(node);
    if(node == vis.size() - 1){
        ans = use;
        return;
    }
    ll c = 0;
    for(int i = 0 ; i < adj[node].size() ; i++){
        if(!vis[adj[node][i]]){
            dfs(adj, vis, ans, use, adj[node][i]);
            c++;
        }
    }
    use.pop_back();
}
 
void solve(){
    ll n; cin >> n;
    vector<vector<ll>> adj(n+1);
    for(int i = 1 ; i < n ; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> vis(n+1,0), vis1(n+1,0);
    vector<vector<ll>> v;
    vector<ll> v1;
    vector<ll> u2;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]) bfs(adj, vis, v, i);
        if(!vis1[i]) dfs(adj, vis1, v1, u2, i);
    }
    vector<ll> search = v1;
    set<ll> st;
    for(ll t : search) st.insert(t);
    ll s = v.size();
    ll flag = 0;
    vector<pair<ll,ll>> ans;
    for(int i = s - 1 ; i >= 0 ; i--){
        for(int j = 0 ; j < v[i].size() ; j++){
            if(st.find(v[i][j]) != st.end()) continue;
            if(i % 2 == flag){
                flag = !flag;
                ans.emplace_back(1,0);
            }
            ans.emplace_back(2, v[i][j]);
            ans.emplace_back(1,0);
            flag = !flag;
        }
    }
    for(int i = 0 ; i < search.size() - 1 ; i++){
        if(i % 2 == flag){
            ans.emplace_back(1,0);
            flag = !flag;
        }
        ans.emplace_back(2, search[i]);
    }
    cout << ans.size() << "\n";
    for(auto p : ans){
        if(p.second != 0) cout << p.first << " " << p.second << "\n";
        else cout << p.first << "\n";
    }
}
 
int main(){
    fast_io();
    ll Test_Cases = 1; cin >> Test_Cases;
    while(Test_Cases--){
        solve();
    }
    return 0;
}
 
// Country : INDIA
// Monday, December 10, 2025
