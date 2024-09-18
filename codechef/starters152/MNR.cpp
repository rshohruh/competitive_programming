// author: rshohruh
// create time: Sep 18 2024, 19:30

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// #define with_testcases
void t_main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());
    int ans = a.back() - a.front();
    ans = min(ans, a[n-3] - a.front());
    ans = min(ans, a[n-2] - a[1]);
    ans = min(ans, a[n-1] - a[2]);
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