// author: rshohruh
// create time: Sep 23 2024, 06:42
// https://codeforces.com/problemset/problem/1155/A

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// #define with_testcases
void t_main(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 1; i < n; ++i){
        if(s[i] < s[i-1]){
            cout << "YES\n";
            cout << i << ' ' << i+1;
            return;
        }
    }
    cout << "NO";
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