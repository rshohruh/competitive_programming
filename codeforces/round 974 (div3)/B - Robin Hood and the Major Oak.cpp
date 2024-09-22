// author: rshohruh
// create time: Sep 21 2024, 19:42
// https://codeforces.com/contest/2014/problem/B

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n, k; cin >> n >> k;
    k %= 4;
    if(n & 1){
        cout << (k == 0 || k == 3 ? "Yes" : "No");
    } else {
        cout << (k == 0 || k == 1 ? "Yes" : "No");
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