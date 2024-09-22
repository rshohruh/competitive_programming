// author: rshohruh
// create time: Sep 21 2024, 19:42
// https://codeforces.com/contest/2014/problem/A

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n, k; cin >> n >> k;
    int a = 0, b = 0;
    for(int i = 0, x; i < n; ++i){
        cin >> x;
        if(x >= k) a += x;
        else if(x == 0 && a > 0) ++b, --a;
    }
    cout << b;
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