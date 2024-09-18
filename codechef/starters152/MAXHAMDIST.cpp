// author: rshohruh
// create time: Sep 18 2024, 19:35

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n, m; cin >> n >> m;
    vector a(n, vector(3, 0));
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i){
            char c; cin >> c;
            if(c == '0') a[i][0] ++;
            else if(c == '1') a[i][1] ++;
            else a[i][2] ++;
        }
    }
    ll ans = 0;
    for(auto &arr: a){
        for(int i = 0; i < arr[2]; ++i)
            if(arr[0] < arr[1]) arr[0] ++;
            else arr[1] ++;
        ans += 1ll * arr[0] * arr[1];
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