// author: rshohruh
// create time: Sep 23 2024, 06:52

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// #define with_testcases
void t_main(){
    int n, m; cin >> n >> m;
    vector a(n, 0);
    vector b(m, 0);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    for(int bit = 0; bit < (1<<9); ++bit){
        int rr = 1;
        for(int &x: a){
            int tt = 0;
            for(int &y: b){
                int t = x&y;
                int ok = 1;
                for(int i = 0; i < 9; ++i)
                    if(((bit>>i) & 1) < ((t>>i) & 1))
                        ok = 0;

                tt |= ok;
            }
            rr &= tt;
        }
        if(rr){
            cout << bit;
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