// author: rshohruh
// create time: Sep 27 2024, 18:46

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int long long

#define with_testcases
void t_main(){
    int n, k; cin >> n >> k;
    vector a(n, 0ll);
    for(int &x: a) cin >> x;
    int d = accumulate(a.begin(), a.end(), 0ll);
    int L = *max_element(a.begin(), a.end());
    for(int ans = n; ans > 0; --ans){
        int l = L, r = (k+d)/ans+1;
        while(l < r){
            int m = (l + r + 1) / 2;
            int x = (d + m - 1)/m;
            if(ans * m - d <= k) l = m;
            else r = m-1;
        }
        if(ans * l - d <= k && ans*l >= d){
            cout << ans;
            return;
        }
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