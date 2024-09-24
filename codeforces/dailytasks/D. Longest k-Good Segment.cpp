// author: rshohruh
// create time: Sep 22 2024, 10:17
// https://codeforces.com/contest/616/problem/D

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[1'000'005];

// #define with_testcases
void t_main(){
    int n, k; cin >> n >> k;
    int cur = 0, mx = 0, id = 1;
    vector arr(n, 0);
    for(int &x: arr) cin >> x;
    for(int l = 0, r = 0; r < n; ++r){
        int x = arr[r];

        cur += a[x] == 0;
        a[x] ++;

        while(cur > k){
            int x = arr[l++];
            a[x] --;
            cur -= a[x] == 0;
        }
        if(r-l+1 > mx){
            mx = r-l;
            id = l+1;
        }
    }
    cout << id << ' ' << id+mx;
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