/*
76. Minimum Window Substring
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length();
        int l = 0, r = 0, min_len = 1e9, idx = -1, cnt = 0;
        unordered_map<char, int> h;

        for (char c : t)
            h[c]++;

        while (r < n)
        {
            if (h[s[r]] > 0)
                cnt = cnt + 1;
            h[s[r]]--;

            while (cnt == m)
            {
                if (r - l + 1 < min_len)
                {
                    min_len = r - l + 1;
                    idx = l;
                }

                h[s[l]]++;
                if (h[s[l]] > 0)
                    cnt--;

                l++;
            }
            r++;
        }
        return idx == -1 ? "" : s.substr(idx, min_len);
    }
};