/*
3546. Equal Sum Grid Partition I
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

Each of the two resulting sections formed by the cut is non-empty.
The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false.



Example 1:

Input: grid = [[1,4],[2,3]]

Output: true

Explanation:



A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.

Example 2:

Input: grid = [[1,3],[2,4]]

Output: false

Explanation:

No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.



Constraints:

1 <= m == grid.length <= 105
1 <= n == grid[i].length <= 105
2 <= m * n <= 105
1 <= grid[i][j] <= 105
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<long long> row(n, 0), col(m, 0);
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                total += grid[i][j];
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        if (total % 2 != 0)
            return false;

        long long target = total / 2;
        long long sum = 0;

        for (int i = 0; i < n - 1; i++)
        {
            sum += row[i];
            if (sum == target)
                return true;
        }
        sum = 0;
        for (int j = 0; j < m - 1; j++)
        {
            sum += col[j];
            if (sum == target)
                return true;
        }
        return false;
    }
    // [1 4]
    // [2 3]
};