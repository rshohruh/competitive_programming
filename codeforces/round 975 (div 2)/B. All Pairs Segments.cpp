// author: rshohruh
// create time: Sep 27 2024, 19:44

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n, q; cin >> n >> q;
    map<ll, ll> mp;
    ll cur = 0;
    int last = -1;
    for(int i = 0, x; i < n; ++i){
        cin >> x;
        if(last != -1) mp[cur] += (x - last - 1);
        cur += n-(i+1);
        mp[cur] ++;
        cur -= i;
        last = x;
    }
    while(q--){
        ll x; cin >> x;
        cout << mp[x] << ' ';
    }
    // for(auto [x, y]: mp) cout << x << ' ' << y << endl;
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