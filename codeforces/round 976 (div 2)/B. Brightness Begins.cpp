// author: rshohruh
// create time: Sep 29 2024, 20:40
// https://codeforces.com/contest/2020/problem/B

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    ll k; cin >> k;
    ll l = 0, r = 1e9;
    while(l < r){
        ll m = (l + r + 1) / 2;
        if((m-1)*m <= k) l = m;
        else r = m-1;
    }
    ll t = k - (l-1) * l;
    cout << l * l + t + (t > 0);
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