/*
Given an integer array height[] where height[i] represents the height of
the i-th stair, a frog starts from the first stair and wants to reach
the top. From any stair i, the frog has two options: it can either jump
to the (i+1)-th stair or the (i+2)-th stair. The cost of a jump is the
absolute difference in height between the two stairs. The task is to
find the minimum total cost required for the frog to reach the top.

*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int recursion(int idx, vector<int> &Heights) // time complexity O(2^n) , space complexity O(n)
{
    if (idx == 0)
    {
        return 0;
    }

    int left = recursion(idx - 1, Heights) + abs(Heights[idx] - Heights[idx - 1]);

    int right = INT8_MAX;
    if (idx > 1)
    {
        right = recursion(idx - 2, Heights) + abs(Heights[idx] - Heights[idx - 2]);
    }
    return min(left, right);
}

int memoization(int idx, vector<int> &Heights, int t[]) // time complexity O(n) , space complexity O(n + n)
{
    if (idx == 0)
    {
        return 0;
    }
    if (t[idx] != -1)
    {
        return t[idx];
    }
    int left = memoization(idx - 1, Heights, t) + abs(Heights[idx] - Heights[idx - 1]);

    int right = INT8_MAX;
    if (idx > 1)
    {
        right = memoization(idx - 2, Heights, t) + abs(Heights[idx] - Heights[idx - 2]);
    }
    return t[idx] = min(left, right);
}

int tabulation(vector<int> &Heights) // n , ntime complexity O(n) , space complexity O(n)
{
    int n = Heights.size();
    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int first = dp[i - 1] + abs(Heights[i] - Heights[i - 1]);
        int second = INT8_MAX;
        if (i > 1)
            second = dp[i - 2] + abs(Heights[i] - Heights[i - 2]);

        dp[i] = min(first, second);
    }

    return dp[n - 1];
}

int Optimal_approach(vector<int> &Heights) // time complexity O(n) , space complexity O(1)
{
    int n = Heights.size();
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int first = prev + abs(Heights[i] - Heights[i - 1]);
        int second = INT8_MAX;
        if (i > 1)
            second = prev2 + abs(Heights[i] - Heights[i - 2]);

        int cur = min(first, second);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main()
{
    vector<int> Heights = {30, 10, 60, 10, 60, 50};
    int n = Heights.size();
    cout << "Recursion : " << recursion(n - 1, Heights) << endl;

    int t[n + 1];
    memset(t, -1, sizeof(t));
    cout << "memoization : " << memoization(n - 1, Heights, t) << endl;

    cout << "tabulation : " << tabulation(Heights) << endl;

    cout << "Optimal_approach : " << Optimal_approach(Heights) << endl;
    return 0;
}