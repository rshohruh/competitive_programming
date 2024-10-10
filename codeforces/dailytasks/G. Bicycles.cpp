// author: rshohruh
// create time: Oct 10 2024, 14:48
// https://codeforces.com/problemset/problem/1915/G

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #include "/home/rshohruh/cpp-dump/cpp-dump.hpp"
    #define debug(...) cpp_dump(__VA_ARGS__)
    namespace cp = cpp_dump;
    CPP_DUMP_SET_OPTION_GLOBAL(max_iteration_count, 100);
#else
    #define debug(...) 42
#endif
using namespace std;
using ll = long long;
#define int long long
#define with_testcases
void t_main(){
    int n, m; cin >> n >> m;
    vector a(n, vector(n, (ll) 1e18));
    for(int i = 0, u, v, w; i < m; ++i){
        cin >> u >> v >> w;
        --u; --v;
        a[u][v] = min(a[u][v], (ll) w);
        a[v][u] = min(a[v][u], (ll) w);
    }
    vector s(n, 0ll);
    for(ll &x: s) cin >> x;

    vector temp(n, vector(0, make_pair(0, 0)));

    for(int u = 0; u < n; ++u)
        for(int v = 0; v < n; ++v)
            if(a[u][v] != (ll)1e18) 
                temp[u].emplace_back(v, a[u][v]);
            
    vector g(n*n, vector(0, make_pair(0, 0)));



    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<>> b;
    b.emplace(0, 0);
    debug(g);
    vector dist(n*n, (int)1e18);

    while(!b.empty()) {
        auto [q, u] = b.top();
        b.pop();
        if(dist[u] <= q) continue;
        dist[u] = q;
        for(auto [v, w]: g[u]) 
            b.emplace(q + w, v);
    }

    int ans = 1e18;
    for(int i = 1; i <= n; ++i)
        ans = min(ans, dist[n*i-1]);
    
    cout << ans;

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