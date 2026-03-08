/*
3849. Maximum Bitwise XOR After Rearrangement
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given two binary strings s and t​​​​​​​, each of length n.

You may rearrange the characters of t in any order, but s must remain unchanged.

Return a binary string of length n representing the maximum integer value obtainable by taking the bitwise XOR of s and rearranged t.



Example 1:

Input: s = "101", t = "011"

Output: "110"

Explanation:

One optimal rearrangement of t is "011".
The bitwise XOR of s and rearranged t is "101" XOR "011" = "110", which is the maximum possible.
Example 2:

Input: s = "0110", t = "1110"

Output: "1101"

Explanation:

One optimal rearrangement of t is "1011".
The bitwise XOR of s and rearranged t is "0110" XOR "1011" = "1101", which is the maximum possible.
Example 3:

Input: s = "0101", t = "1001"

Output: "1111"

Explanation:

One optimal rearrangement of t is "1010".
The bitwise XOR of s and rearranged t is "0101" XOR "1010" = "1111", which is the maximum possible.


Constraints:

1 <= n == s.length == t.length <= 2 * 105
s[i] and t[i] are either '0' or '1'.
*/
class Solution
{
public:
    string maximumXor(string s, string t)
    {
        int n = s.length(), zeros = 0, ones = 0;
        for (char c_ : t)
        {
            c_ == '0' ? zeros++ : ones++;
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (zeros > 0)
                {
                    s[i] = '1';
                    zeros--;
                }
                else
                {
                    s[i] = '0';
                    ones--;
                }
            }
            else
            {
                if (ones > 0)
                {
                    s[i] = '1';
                    ones--;
                }
                else
                {
                    s[i] = '0';
                    zeros--;
                }
            }
        }
        return s;
    }
};