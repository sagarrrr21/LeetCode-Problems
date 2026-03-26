/*
You are given an array of N integers. you are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int Recursion(int idx, vector<int> &nums) // time complexity O(2^n) , space complexity O(n)
{
    if (idx == 0)
        return nums[0];
    if (idx < 0)
        return 0;

    int take = nums[idx] + Recursion(idx - 2, nums);
    int not_take = 0 + Recursion(idx - 1, nums);

    return max(take, not_take);
}

int memoization(int idx, vector<int> &nums, int t[])
// time complexity O(n) , space complexity O(n) + O(n)
{
    if (idx == 0)
        return nums[0];

    if (idx < 0)
        return 0;

    if (t[idx] != -1)
        return t[idx];

    int take = nums[idx] + memoization(idx - 2, nums, t);
    int not_take = 0 + memoization(idx - 1, nums, t);

    return t[idx] = max(take, not_take);
}

int tabulation(vector<int> &nums) // time complexity O(n) , space complexity O(n)
{
    int n = nums.size();

    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int take, not_take;
        take = nums[i];

        if (i - 2 >= 0)
            take = nums[i] + dp[i - 2];

        not_take = 0 + dp[i - 1];

        dp[i] = max(take, not_take);
    }
    return dp[n - 1];
}

int Optimal_approach(vector<int> nums) // time complexity O(n) , space complexity O(1)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int take, not_take;

        take = nums[i];

        if (i - 2 >= 0)

            take = nums[i] + prev2;

        not_take = prev;
        int cur = max(take, not_take);

        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main()
{
    vector<int> nums = {2, 5, 1, 3, 6, 2, 6, 8, 0};
    // Output : 19
    int n = nums.size();

    cout << "Recursion : " << Recursion(n - 1, nums) << endl;

    int t[n];
    memset(t, -1, sizeof(t));
    cout << "memoization : " << memoization(n - 1, nums, t) << endl;

    cout << "tabulation : " << tabulation(nums) << endl;

    cout << "optimal_approach : " << Optimal_approach(nums) << endl;

    return 0;
}