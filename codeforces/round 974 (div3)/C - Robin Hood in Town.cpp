// author: rshohruh
// create time: Sep 21 2024, 19:42
// https://codeforces.com/contest/2014/problem/C    

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n; cin >> n;
    vector a(n, 0);
    for(int &x: a) cin >> x;
    if(n <= 2) return cout << -1, void();
    sort(a.begin(), a.end());
    ll cur = accumulate(a.begin(), a.end(), 0ll);
    ll k = 1ll * a[n/2] * n * 2;
    // cout << k;
    ll l = 0, r = 1e18;
    while(l < r){
        ll m = (l + r) / 2;
        if(cur + m > k) r = m;
        else l = m + 1;
    }
    cout << l;
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