/*
30. Substring with Concatenation of All Words
Solved
Hard
Topics
premium lock icon
Companies
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.



Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].



Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;


// Time Complexity	O(len x w_s)
// Space Complexity	O(n)
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> freq;
        for (string &word : words)
            freq[word]++;

        int len = s.size();
        int n = words.size();
        int w_s = words[0].size();
        int win_s = w_s * n;

        vector<int> ans;

        for (int i = 0; i < w_s; i++)
        {
            int left = i, count = 0;
            unordered_map<string, int> cur;

            for (int j = i; j <= len - w_s; j += w_s)
            {
                string word = s.substr(j, w_s);
                if (freq.count(word))
                {
                    cur[word]++;
                    count++;

                    while (cur[word] > freq[word])
                    {
                        string leftWord = s.substr(left, w_s);
                        cur[leftWord]--;
                        count--;
                        left += w_s;
                    }

                    if (count == n)
                        ans.push_back(left);
                }
                else
                {
                    cur.clear();
                    count = 0;
                    left = j + w_s;
                }
            }
        }

        return ans;
    }
};