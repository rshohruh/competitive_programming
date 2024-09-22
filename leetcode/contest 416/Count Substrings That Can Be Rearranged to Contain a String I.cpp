#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/contest/weekly-contest-416/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        using ll = long long;
        int n = word1.size();
        ll ans = 0;
        vector b(26, 0);
        for(char c: word2) b[c-'a'] ++;
        vector a(26, 0);
        for(int l = 0, r = 0; l < n; ++l){
            int ok = 0;
            for(int i = 0; i < 26; ++i)
                if(a[i] < b[i]) ok = 1;
            
            while(r < n && ok){
                a[word1[r++]-'a'] ++;
                ok = 0;
                for(int i = 0; i < 26; ++i)
                    if(a[i] < b[i]) ok = 1;
            }
            
            ok = 0;
            for(int i = 0; i < 26; ++i)
                if(a[i] < b[i]) ok = 1;
            if(!ok) ans += n-r+1;
            a[word1[l] - 'a'] --;
            // cout << l << ' ' << r << endl;
        }
        return ans;
    }
};