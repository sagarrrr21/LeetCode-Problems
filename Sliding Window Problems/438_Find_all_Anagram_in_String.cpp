/*
438. Find All Anagrams in a String
Solved
Medium
Topics
premium lock icon
Companies
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.



Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.length(), k = p.length();
        if (n < k)
            return {};

        vector<int> f(26, 0);

        for (char c : p)
            f[c - 'a']++;

        vector<int> ans;
        int l = 0, r = 0;
        int cnt = k;

        while (r < n)
        {

            if (f[s[r] - 'a'] > 0)
                cnt--;

            f[s[r] - 'a']--;
            r++;

            if (cnt == 0)
                ans.push_back(l);

            if (r - l == k)
            {
                if (f[s[l] - 'a'] >= 0)
                    cnt++;
                f[s[l] - 'a']++;
                l++;
            }
        }
        return ans;
    }
};