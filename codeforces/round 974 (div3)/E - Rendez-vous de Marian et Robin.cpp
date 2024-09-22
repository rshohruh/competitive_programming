// author: rshohruh
// create time: Sep 21 2024, 19:42
// https://codeforces.com/contest/2014/problem/E
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int long long
#define with_testcases


int n;
vector<vector<pair<int, int>>> g;
vector<int> h;

vector<int> bfs(int s){
    vector<int> a(n+1, 1e18);
    vector<int> b(n+1, 1e18);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq2;

    auto add1 = [&](int u, int w){
        if(a[u] <= w) return;
        a[u] = w;
        pq1.emplace(w, u);
    };

    auto add2 = [&](int u, int w){
        if(b[u] <= w) return;
        b[u] = w;
        pq2.emplace(w, u);
    };

    add1(s, 0);

    while(!pq1.empty()){
        auto [w, u] = pq1.top();
        pq1.pop();
        if(a[u] < w) continue;
        for(auto [v, cur] : g[u])
            add1(v, w+cur);
    }


    for(int u = 1; u <= n; ++u){
        if(h[u]) add2(u, a[u]);
    }


    while(!pq2.empty()){
        auto [w, u] = pq2.top();
        pq2.pop();
        if(b[u] < w) continue;
        for(auto [v, cur]: g[u]){
            add2(v, w+cur/2);
        }
    }

    // for(int x: a) cout << (x == 1e18 ? -1 : x) << ' '; cout << endl;
    // for(int x: b) cout << (x == 1e18 ? -1 : x) << ' '; cout << endl;
    for(int i = 1; i <= n; ++i)
        a[i] = min(a[i], b[i]);
    return a;
}

void t_main(){
    int m, d; cin >> n >> m >> d;
    g.assign(n+1, vector<pair<int, int>>());
    h.assign(n+1, 0);
    for(int i = 0, x; i < d; ++i){
        cin >> x;
        h[x] = 1;
    }
    for(int i = 0, u, v, w; i < m; ++i){
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector a = bfs(1);
    vector b = bfs(n);
    int mn = 1e18;

    for(int i = 1; i <= n; ++i)
        mn = min(mn, max(a[i], b[i]));
    cout << (mn == 1e18 ? -1 : mn);
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