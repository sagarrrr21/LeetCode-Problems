/*
Given a 'N' * 'M' maze with obstacles, count and return the number of paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value -1 if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cell(i+1 , j) and (i , j + 1) only. Since the can we large, print it modulo 10^9 + 7;
*/

#include <iostream>
#include <vector>
using namespace std;

int Recursion(int i, int j, vector<vector<int>> &grid)
// - Time Complexity: O(2 ^  n) - Space Complexity: O(n + m)

{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (grid[i][j] == -1)
        return 0;

    int up = Recursion(i - 1, j, grid);
    int left = Recursion(i, j - 1, grid);

    return up + left;
}

int memoization(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
// Time Complexity: O(n x m) - Space Complexity: O(n x m ) + O(n + m)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (grid[i][j] == -1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = memoization(i - 1, j, grid, dp);
    int left = memoization(i, j - 1, grid, dp);

    return dp[i][j] = up + left;
}

int tabulation(vector<vector<int>> &grid, int n, int m)
// Time Complexity: O(n x m) - Space Complexity: O(n x m )

{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (grid[i][j] == -1)
            {
                dp[i][j] = 0;
            }
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }
    return dp[n - 1][m - 1];
}

int Optimal_approach(int n, int m, vector<vector<int>> &grid)
// Time Complexity: O(n x m) - Space Complexity: O(m)

{
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, 0);

        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == -1)
                cur[j] = 0;
            else if (i == 0 && j == 0)
                cur[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = cur[j - 1];
                cur[j] = (up + left);
            }
        }
        prev = cur;
    }
    return prev[m - 1];
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0},
        {0, 0, 0}};
    int n = grid.size();
    int m = grid[0].size();

    cout << "Recursion : " << Recursion(n - 1, m - 1, grid) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "memoization : " << memoization(n - 1, m - 1, grid, dp) << endl;

    cout << "tabulation : " << tabulation(grid, n, m) << endl;

    cout << "Optimal_approach : " << Optimal_approach(n, m, grid) << endl;
    return 0;
}