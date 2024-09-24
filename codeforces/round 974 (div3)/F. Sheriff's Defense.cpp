// author: rshohruh
// create time: Sep 24 2024, 19:49

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int long long
#define with_testcases

vector<vector<int>> g;
vector<pair<int, int>> dp;
vector<int> a;
int n, c;
void dfs(int u, int p){
    dp[u].second = a[u];
    for(int v: g[u]){
        if(v != p){
            dfs(v, u);
            dp[u].first += max(dp[v].first, dp[v].second);
            dp[u].second += max(dp[v].first, dp[v].second - 2*c);
        }
    }
}

void t_main(){
    cin >> n >> c;
    g.assign(n+1, vector<int>());
    dp.assign(n+1, {0, 0});
    a.assign(n+1, 0);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1].first, dp[1].second);
}

signed main(){
    signed t = 1;
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef with_testcases
        cin >> t;
    #endif
    while(t--){
        t_main();
        cout << '\n';
    }
    return 0;
}