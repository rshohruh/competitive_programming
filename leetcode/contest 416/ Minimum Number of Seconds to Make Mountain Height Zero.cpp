#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/contest/weekly-contest-416/problems/minimum-number-of-seconds-to-make-mountain-height-zero

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;
        ll l = 0, r = 1e18;
        while(l < r){
            ll m = (l + r) / 2;
            ll k = 0;
            for(int x: workerTimes){
                int L = 0, R = mountainHeight;
                while(L < R){
                    ll M = (L + R + 1) / 2;
                    if(M*(M+1)/2 * x > m) R = M-1;
                    else L = M;
                }
                k += L;
            }
            if(k >= mountainHeight) r = m;
            else l = m+1;
        }
        return l;
    }
};