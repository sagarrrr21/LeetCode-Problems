/*
5. Longest Palindromic Substring
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// time Complexity : O(n x n)
// Space Complexity : O(n x n)
class Solution
{
public:
    int t[1001][1001];
    bool solve(string &s, int i, int j)
    {
        if (i >= j)
        {
            return 1;
        }
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        if (s[i] == s[j])
        {
            return solve(s, i + 1, j - 1);
        }
        return t[i][j] = 0;
    }
    string longestPalindrome(string s)
    {
        int n = s.length();

        int max_len = INT_MIN;

        memset(t, -1, sizeof(t));

        int start_point = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (solve(s, i, j))
                {
                    if (j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;
                        start_point = i;
                    }
                }
            }
        }
        return s.substr(start_point, max_len);
    }
};

// Time Complexity : O(n x n)
// Space Complexity : O(n x n)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();

        int max_len = INT_MIN, start_idx = 0;
        auto helper = [&](int l, int r)
        {
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > max_len)
                {
                    start_idx = l;
                    max_len = r - l + 1;
                }
                l--, r++;
            }
        };

        for (int i = 0; i < n; i++)
        {
            helper(i, i);
            helper(i, i + 1);
        }
        return s.substr(start_idx, max_len);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string t = "#";
        for (char c : s)
        {
            t += c;
            t += '#';
        }

        int n = t.length();
        vector<int> p(n, 0);

        int c = 0, r = 0;

        int max_len = 0, longest_center = 0;

        for (int l = 0; l < n; l++)
        {
            int mirror = 2 * c - l;

            if (l < r && mirror >= 0)
                p[l] = min(p[mirror], r - l);

            int left = l - (p[l] + 1);
            int right = l + (p[l] + 1);

            while (left >= 0 && right < n && t[left] == t[right])
            {
                p[l]++;
                left--, right++;
            }

            if (l + p[l] > r)
            {
                c = l;
                r = l + p[l];
            }

            if (p[l] > max_len)
            {
                max_len = p[l];
                longest_center = l;
            }
        }
        int start = (longest_center - max_len) / 2;
        return s.substr(start, max_len);
    }
};