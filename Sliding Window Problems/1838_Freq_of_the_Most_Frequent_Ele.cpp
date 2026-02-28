#include <bits/stdc++.h>

using namespace std;

/*
Time Complexity : O(n x log(n))
Space Complexity : O(n)
*/
class Solution
{
public:
    int Binary_search(int idx, vector<int> &nums, vector<long long> &pf, int k)
    {
        int low = 0, high = idx;
        int target = nums[idx];

        int res = idx;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int total_ele = idx - mid + 1;

            long long total_sum = 1LL * total_ele * target;
            long long cur_sum = pf[idx] - (mid > 0 ? pf[mid - 1] : 0);
            long long ops = total_sum - cur_sum;

            if (ops <= k)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return idx - res + 1;
    }
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<long long> pf(n, 0);
        pf[0] = nums[0];
        for (int i = 1; i < n; i++)
            pf[i] = pf[i - 1] + nums[i];

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, Binary_search(i, nums, pf, k));
        }
        return ans;
    }
};

/*
Time Complexity = O(n x log(n))
Space Complexity = constant O(1)
*/

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int l = 0, r = 0;
        int res = 0;

        long long sum = 0;

        while (r < n)
        {
            long long target = nums[r];
            sum += nums[r];

            if (((r - l + 1) * target - sum) > k)
            {
                sum -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};