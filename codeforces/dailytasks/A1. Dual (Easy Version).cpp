// author: rshohruh
// create time: Oct 02 2024, 07:38

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define with_testcases
void t_main(){
    int n; cin >> n;
    vector a(n, 0);
    for(int &x: a) cin >> x;
    int id = *max_element(a.begin(), a.end());
    vector<pair<int, int>> ans;
    if(a[id] > 0){
        while(a[id] <= 20){
            ans.emplace_back(id, id);
            a[id] *= 2;
        }
        for(int i = 1; i < n; ++i){
            while(a[i] < a[i-1]){
                ans.emplace_back(i, id); 
                a[i] += a[id];
            }
        }
    } else {
        for(int i = 1; i < n; ++i){
            while(a[i] < a[i-1]){
                ans.emplace_back(i, i-1);
                a[i] += a[i-1];
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto [x, y]: ans)
        cout << x+1 << ' ' << y+1 << '\n';
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