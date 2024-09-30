// author: rshohruh
// create time: Sep 29 2024, 20:40
// https://codeforces.com/contest/2020/problem/A

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int long long

#define with_testcases
void t_main(){
    int n, k; cin >> n >> k;
    if(k == 1){
        cout << n;
        return;
    }
    int ans = 0;
    while(n){
        ans += n%k;
        n /= k;
    }
    cout << ans;
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