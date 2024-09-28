// author: rshohruh
// create time: Sep 27 2024, 18:38

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n; cin >> n;
    vector a(n, 0);
    for(int &x: a) cin >> x;
    int x = *max_element(a.begin(), a.end());
    for(int i = 0; i < n; ++i){
        if(x == a[i] && !(i & 1)){
            cout << (n+1)/2 + x;
            return;
        }
    }
    cout << x + n/2;
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