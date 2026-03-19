/*
1493. Longest Subarray of 1's After Deleting One Element
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.



Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

// Time Complexity : O(n x m)
// space Complexity : O(1) Constant
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find_ones(vector<int> &nums, int idx)
    {
        int cur = 0, max_len = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (j == idx)
                continue;
            if (nums[j] == 1)
            {
                cur++;
                max_len = max(max_len, cur);
            }
            else
                cur = 0;
        }
        return max_len;
    }
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        int zero = 0;
        for (int i = 0; i < n; i++)
        {

            if (nums[i] == 0)
            {
                ans = max(ans, find_ones(nums, i));
                zero++;
            }
        }
        if (zero == 0)
            return n - 1;
        return ans;
    }
};

// Time Complexity : O(n + n)
// space Complexity : O(1) Constant
class Solution2
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int zero = 0, ans = 0;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == 0)
                zero++;
            while (zero > 1)
            {
                if (nums[i] == 0)
                    zero--;
                i++;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};

// Time Complexity : O(n)
// space Complexity : O(1) Constant
class Solution3
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int last_zero = -1, ans = 0;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == 0)
            {
                i = last_zero + 1;
                last_zero = j;
            }

            ans = max(ans, j - i);
        }
        return ans;
    }
};