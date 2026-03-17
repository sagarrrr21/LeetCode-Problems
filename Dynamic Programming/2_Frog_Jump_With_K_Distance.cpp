/*
A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.


To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int Recursion(int idx, vector<int> &Heights, int k) // time complexity O(n*k) , space complexity O(n)
{
    if (idx == 0)
        return 0;

    int minEnergy = INT8_MAX;

    for (int i = 1; i <= k; i++)
    {
        int jump = INT8_MAX;
        if (idx - i >= 0)
            jump = Recursion(idx - i, Heights, k) + abs(Heights[idx] - Heights[idx - i]);
        minEnergy = min(minEnergy, jump);
    }
    return minEnergy;
}

int memoization(int idx, vector<int> &Heights, int k, int t[]) // time complexity O(2) * k , space complexity O(n) + O(n)
{
    if (idx == 0)
        return 0;

    if (t[idx] != -1)
        return t[idx];

    int minEnergy = INT8_MAX;

    for (int i = 1; i <= k; i++)
    {
        int jump = INT8_MAX;
        if (idx - i >= 0)
            jump = memoization(idx - i, Heights, k, t) + abs(Heights[idx] - Heights[idx - i]);
        minEnergy = min(minEnergy, jump);
    }
    return t[idx] = minEnergy;
}

int tabulation(vector<int> &Heights, int k) // time complexity O(n) * k , space complexity O(n)
{
    int n = Heights.size();
    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minEnergy = INT8_MAX;

        for (int j = 1; j <= k; j++)
        {
            int jump = INT8_MAX;
            if (i - j >= 0)
            {
                jump = dp[i - j] + abs(Heights[i] - Heights[i - j]);
                minEnergy = min(minEnergy, jump);
            }
        }
        dp[i] = minEnergy;
    }
    return dp[n - 1];
}

int main()
{
    vector<int> Heights = {30, 10, 60, 10, 60, 50};
    int n = Heights.size(), k = 3;

    cout << "Recursion : " << Recursion(n - 1, Heights, k) << endl;

    int t[n + 1];
    memset(t, -1, sizeof(t));
    cout << "memoization : " << memoization(n - 1, Heights, k, t) << endl;

    cout << "tabulation : " << tabulation(Heights, k) << endl;

    return 0;
}