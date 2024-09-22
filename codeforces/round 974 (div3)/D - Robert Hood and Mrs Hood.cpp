// author: rshohruh
// create time: Sep 21 2024, 19:42
// https://codeforces.com/contest/2014/problem/D

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n, d, k; cin >> n >> d >> k;
    vector a(k, 0);
    vector b(k, 0);
    
    for(int i = 0; i < k; ++i) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    int cnt = 0;
    int ans1 = -1, ans2 = -1;
    int mx = 0, mn = 1e9;
    for(int q = 1; q <= n; ++q){

        while(i < k && a[i] == q) ++i, ++cnt;

        while(j < k && b[j] == q-d) ++j, --cnt;

        if(cnt < mn && q >= d){
            mn = cnt;
            ans1 = q-d+1;
        } 

        if(cnt > mx && q >= d){
            mx = cnt;
            ans2 = q-d+1;   
        }
    }
    cout << ans2 << ' ' << ans1;

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