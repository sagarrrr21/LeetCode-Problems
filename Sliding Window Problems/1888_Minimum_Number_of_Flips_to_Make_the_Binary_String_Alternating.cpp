/*
1888. Minimum Number of Flips to Make the Binary String Alternating
Medium
Topics
premium lock icon
Companies
Hint
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.


Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating.
Example 3:

Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".


Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.length();

        s = (s + s);

        string s1, s2;

        for (int i = 0; i < 2 * n; i++)
        {
            s1 += (i & 1 ? '0' : '1');
            s2 += (i & 1 ? '1' : '0');
        }

        int ans = INT_MAX;

        int flip1 = 0, flip2 = 0, l = 0, r = 0;

        while (r < 2 * n)
        {
            if (s[r] != s1[r])
                flip1++;
            if (s[r] != s2[r])
                flip2++;
            if (r - l + 1 > n)
            {
                if (s[l] != s1[l])
                    flip1--;
                if (s[l] != s2[l])
                    flip2--;
                l++;
            }
            if (r - l + 1 == n)
            {
                ans = min({ans, flip1, flip2});
            }
            r++;
        }
        return ans;
    }
};