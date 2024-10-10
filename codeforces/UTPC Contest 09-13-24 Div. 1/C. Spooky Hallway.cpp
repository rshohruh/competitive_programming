// author: rshohruh
// create time: Oct 04 2024, 14:26

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// #define with_testcases
void t_main(){
    int n, cnt = 0; string s; cin >> n >> s; for(int i = 1; i < n; ++i) cnt += s[i] != s[i-1]; cout << cnt/2;
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