#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE APPROACH
    // Time Complexity : O(N^3)
    // Space Complexity : O(1)

    bool allUnique(string &s, int start, int end)
    {
        vector<int> freq(256, 0);

        for (int i = start; i <= end; i++)
        {
            if (freq[s[i]] == 1)
                return false;
            freq[s[i]]++;
        }
        return true;
    }

    int bruteForce(string s)
    {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (allUnique(s, i, j))
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }

    // BETTER APPROACH (Sliding Window + Set)
    // Time Complexity : O(2N) ≈ O(N)
    // Space Complexity : O(N)

    int betterApproach(string s)
    {

        int l = 0, r = 0;
        int maxLen = 0;
        unordered_set<char> st;

        while (r < s.length())
        {

            while (st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }

    // OPTIMAL APPROACH (Hashing + Sliding Window)
    // Time Complexity : O(N)
    // Space Complexity : O(1)

    int optimalApproach(string s)
    {

        int l = 0, r = 0;
        int max_len = 0;

        int hash[256];
        memset(hash, -1, sizeof(hash));

        while (r < s.length())
        {

            if (hash[s[r]] != -1 && hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }

            max_len = max(max_len, r - l + 1);

            hash[s[r]] = r;
            r++;
        }

        return max_len;
    }
};
