/*
2953. Count Complete Substrings
Hard
Topics
premium lock icon
Companies
Hint
You are given a string word and an integer k.

A substring s of word is complete if:

Each character in s occurs exactly k times.
The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in their positions in the alphabet is at most 2.
Return the number of complete substrings of word.

A substring is a non-empty contiguous sequence of characters in a string.



Example 1:

Input: word = "igigee", k = 2
Output: 3
Explanation: The complete substrings where each character appears exactly twice and the difference between adjacent characters is at most 2 are: igigee, igigee, igigee.
Example 2:

Input: word = "aaabbbccc", k = 3
Output: 6
Explanation: The complete substrings where each character appears exactly three times and the difference between adjacent characters is at most 2 are: aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc.


Constraints:

1 <= word.length <= 105
word consists only of lowercase English letters.
1 <= k <= word.length
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int solve(int start, int end, string &word, int k)
    {
        int result = 0;

        for (int uni_c = 1; uni_c <= 26 && uni_c * k <= end - start + 1;
             uni_c++)
        {

            vector<int> f(26, 0);
            int good_char = 0;
            int i = start;
            int window_len = uni_c * k;

            for (int j = start; j <= end; j++)
            {

                char c = word[j];
                f[c - 'a']++;

                if (f[c - 'a'] == k)
                    good_char++;
                else if (f[c - 'a'] == k + 1)
                    good_char--;

                if (j - i + 1 > window_len)
                {
                    if (f[word[i] - 'a'] == k)
                        good_char--;
                    else if (f[word[i] - 'a'] == k + 1)
                        good_char++;

                    f[word[i] - 'a']--;
                    i++;
                }
                if (good_char == uni_c)
                    result++;
            }
        }
        return result;
    }
    int countCompleteSubstrings(string word, int k)
    {
        int n = word.length();
        int ans = 0, last = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i == n || abs(word[i] - word[i - 1]) > 2)
            {
                ans += solve(last, i - 1, word, k);
                last = i;
            }
        }
        return ans;
    }
};