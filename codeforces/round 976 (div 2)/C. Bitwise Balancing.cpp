// author: rshohruh
// create time: Sep 29 2024, 20:40
// https://codeforces.com/contest/2020/problem/C

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    ll b, c, d;
    cin >> b >> c >> d;
    ll a = 0;
    for(int i = 0; i < 61; ++i)
        if(((d>>i) & 1) != ((b>>i) & 1))
            if(((d>>i) & 1) == ((c>>i) & 1)) return cout << -1, void();
            else a += (1ll<<i);
    
    cout << a;
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