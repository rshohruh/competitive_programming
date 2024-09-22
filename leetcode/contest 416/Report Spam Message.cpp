#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/contest/weekly-contest-416/problems/report-spam-message
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> st(bannedWords.begin(), bannedWords.end());
        int ans = 0;
        for(string &s: message)
            ans += st.count(s);
        return ans >= 2;
    }
};