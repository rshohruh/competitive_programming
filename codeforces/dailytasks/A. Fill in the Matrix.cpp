// author: rshohruh
// create time: Sep 24 2024, 20:05
// https://codeforces.com/problemset/problem/1868/A

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n, m; cin >> n >> m;
    if(m == 1){
        for(int i = 0; i <= n; ++i)
            cout << 0 << '\n';
        return;
    }
    int k = min(n, m);
    cout << max(2, k) << '\n';
    
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j)
            if(i != j) cout << j << ' ';
        cout << i << ' ';
        for(int j = k; j < m; ++j)
            cout << j << ' ';
        cout << '\n';
    }
    for(int i = k; i < n; ++i){
        for(int j = 0; j < m; ++j)
            cout << (j+1)%m << ' ';
        cout << '\n';
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