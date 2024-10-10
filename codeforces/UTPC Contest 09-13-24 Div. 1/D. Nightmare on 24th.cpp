// author: rshohruh
// create time: Oct 10 2024, 14:19

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #include "/home/rshohruh/cpp-dump/cpp-dump.hpp"
    #define debug(...) cpp_dump(__VA_ARGS__)
    namespace cp = cpp_dump;
#else
    #define debug(...) 42
#endif
using namespace std;
using ll = long long;

// #define with_testcases
void t_main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    partial_sum(a.begin(), a.end(), a.begin());
    for(int i = 0, x; i < m; ++i){
        cin >> x;
        if(x > a.back()) cout << -1 << '\n';
        else if(x <= a.front()) cout << 1 << '\n';
        else if(x == 0) cout << 0 << '\n';
        else {
            int l = 0, r = n-1;
            while(l < r) {
                int m = (l + r + 1) / 2;
                if(a[m] >= x) r = m - 1;
                else l = m;
            }
            cout << l + 2 << '\n';
        }
    }
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