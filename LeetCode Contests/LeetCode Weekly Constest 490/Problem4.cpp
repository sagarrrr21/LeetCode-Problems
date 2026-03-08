/*
3850. Count Sequences to K
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given an integer array nums, and an integer k.

Start with an initial value val = 1 and process nums from left to right. At each index i, you must choose exactly one of the following actions:

Multiply val by nums[i].
Divide val by nums[i].
Leave val unchanged.
After processing all elements, val is considered equal to k only if its final rational value exactly equals k.

Return the count of distinct sequences of choices that result in val == k.

Note: Division is rational (exact), not integer division. For example, 2 / 4 = 1 / 2.



Example 1:

Input: nums = [2,3,2], k = 6

Output: 2

Explanation:

The following 2 distinct sequences of choices result in val == k:

Sequence	Operation on nums[0]	Operation on nums[1]	Operation on nums[2]	Final val
1	Multiply: val = 1 * 2 = 2	Multiply: val = 2 * 3 = 6	Leave val unchanged	6
2	Leave val unchanged	Multiply: val = 1 * 3 = 3	Multiply: val = 3 * 2 = 6	6
Example 2:

Input: nums = [4,6,3], k = 2

Output: 2

Explanation:

The following 2 distinct sequences of choices result in val == k:

Sequence	Operation on nums[0]	Operation on nums[1]	Operation on nums[2]	Final val
1	Multiply: val = 1 * 4 = 4	Divide: val = 4 / 6 = 2 / 3	Multiply: val = (2 / 3) * 3 = 2	2
2	Leave val unchanged	Multiply: val = 1 * 6 = 6	Divide: val = 6 / 3 = 2	2
Example 3:

Input: nums = [1,5], k = 1

Output: 3

Explanation:

The following 3 distinct sequences of choices result in val == k:

Sequence	Operation on nums[0]	Operation on nums[1]	Final val
1	Multiply: val = 1 * 1 = 1	Leave val unchanged	1
2	Divide: val = 1 / 1 = 1	Leave val unchanged	1
3	Leave val unchanged	Leave val unchanged	1


Constraints:

1 <= nums.length <= 19
1 <= nums[i] <= 6
1 <= k <= 1015
*/

class Solution
{
public:
    typedef long long ll;
    map<tuple<int, int, int, int>, ll> dp;
    vector<vector<int>> f = {{}, {0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {2, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    ll Recursion(int i, int e2, int e3, int e5, vector<int> &nums, int k2,
                 int k3, int k5)
    {
        if (i == nums.size())
            return (e2 == k2 && e3 == k3 && e5 == k5);

        auto key_ = make_tuple(i, e2, e3, e5);

        if (dp.count(key_))
            return dp[key_];

        ll ans_ = 0;
        auto f_ = f[nums[i]];

        ans_ += Recursion(i + 1, e2, e3, e5, nums, k2, k3, k5);

        ans_ += Recursion(i + 1, e2 + f_[0], e3 + f_[1], e5 + f_[2], nums, k2,
                          k3, k5);

        ans_ += Recursion(i + 1, e2 - f_[0], e3 - f_[1], e5 - f_[2], nums, k2,
                          k3, k5);

        return dp[key_] = ans_;
    }
    ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
    int countSequences(vector<int> &nums, long long k)
    {
        dp.clear();
        int k2 = 0, k3 = 0, k5 = 0;

        while (k % 2 == 0)
            k2++, k /= 2;
        while (k % 3 == 0)
            k3++, k /= 3;
        while (k % 5 == 0)
            k5++, k /= 5;

        if (k != 1)
            return 0;

        return Recursion(0, 0, 0, 0, nums, k2, k3, k5);
    }
};