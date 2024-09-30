// author: rshohruh
// create time: Sep 29 2024, 20:40
// https://codeforces.com/problemset/problem/253/B

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// #define with_testcases
void t_main(){
    int n; cin >> n;
    vector a(5001, 0);
    for(int i = 0, x; i < n; ++i){
        cin >> x;
        a[x] ++;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    int ans = n;
    for(int i = 1; i <= 2500; ++i){
        int cur = a[i*2] - a[i-1];
        ans = min(ans, n-cur);
    }
    cout << ans;
}

signed main(){
    signed t = 1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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