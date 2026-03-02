/*
992. Subarrays with K Different Integers
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].


Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
*/

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &nums, int k)
    {
        int l = 0, r = 0, cnt = 0;

        unordered_map<int, int> mp;

        while (r < nums.size())
        {
            mp[nums[r]]++;

            while (mp.size() > k)
            {
                mp[nums[l]]--;
                if (!mp[nums[l]])
                    mp.erase(nums[l]);
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> f;

        int i = 0, j = 0, big_idx = 0;
        int ans = 0;
        while (j < n)
        {
            f[nums[j]]++;

            while (f.size() > k)
            {
                f[nums[i]]--;
                if (f[nums[i]] == 0)
                    f.erase(nums[i]);
                i++;
                big_idx = i;
            }

            while (f[nums[i]] > 1)
            {
                f[nums[i]]--;
                i++;
            }

            if (f.size() == k)
            {
                ans += (1 + i - big_idx);
            }
            j++;
        }
        return ans;
    }
};