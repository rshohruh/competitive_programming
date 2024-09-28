// author: rshohruh
// create time: Sep 27 2024, 20:00

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;
vector<vector<int>> g;
vector<int> d;
vector<int> dp;
int dfs(int u, int p, int b){
    d[u] = dp[u] = b;
    for(int v: g[u]){
        if(v != p){
            dp[u] = max(dp[u], dfs(v, u, b+1));
        }
    }
    return dp[u];
}
#define with_testcases
void t_main(){
    cin >> n;
    g.assign(n+1, vector<int>());
    dp.assign(n+1, 0);
    d.assign(n+1, 0);

    for(int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 1);
    // for(int x: d) cout << x << ' '; cout << endl;
    // for(int x: dp) cout << x << ' '; cout << endl;
    vector p(n+1, 0);
    vector pd(n+1, 0);
    for(int i = 1; i <= n; ++i){
        p[d[i]] ++;
        pd[dp[i]] ++;
    }
    int ans = n;
    int mn = n;
    for(int i = 1; i <= n; ++i){
        ans -= p[i];
        ans += pd[i-1];
        // cout << ans << ' ';
        mn = min(mn, ans);
    }
    cout << mn;
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