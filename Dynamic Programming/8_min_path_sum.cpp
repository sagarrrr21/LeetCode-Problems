/*
Ninjaland is a country in the shape of a 2-dimensional grid 'grid' , with ,'n' rows and 'M' columns. Each point in the grid has some cost associated with it.

find a path from top left i.e (0,0) to the bottom right i.e (n-1 , m-1) which minimizes the sum of the cost of all the numbers along the path. you need to tell the minimum sum of that path.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Recursion(int i, int j, vector<vector<int>> &grid)
// Time Complexity:-  O(2^(n + m)) , Space Complexity: O(n + m)

{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9; // cannot use INT_MAX because up and left will overflow
    int up = grid[i][j] + Recursion(i - 1, j, grid);
    int left = grid[i][j] + Recursion(i, j - 1, grid);

    return min(up, left);
}

int memoization(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
// Time Complexity:-  O(n * m) , Space Complexity: O(n * m) + O(n + m)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + memoization(i - 1, j, grid, dp);
    int left = grid[i][j] + memoization(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}

int tabulation(int n, int m, vector<vector<int>> &grid)
// Time Complexity:-  O(n * m) , Space Complexity: O(n * m)

{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[0][0];
                continue;
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int Optimal_approach(int n, int m, vector<vector<int>> &grid)
// Time Complexity:-  O(n * m) , Space Complexity: O(m)

{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, 0);

        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                cur[j] = grid[0][0];
                continue;
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = grid[i][j] + prev[j];
                if (j > 0)
                    left = grid[i][j] + cur[j - 1];
                cur[j] = min(up, left);
            }
        }
        prev = cur;
    }
    return prev[m - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3, 1}, {4, 5, 1, 2}, {1, 3, 5, 0}, {0, 1, 3, 2}};
    int n = grid.size();
    int m = grid[0].size();

    cout << "Recursion : " << Recursion(n - 1, m - 1, grid) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << "memoization : " << memoization(n - 1, m - 1, grid, dp) << endl;

    cout << "tabulation : " << tabulation(n, m, grid) << endl;

    cout << "Optimal approach : " << Optimal_approach(n, m, grid) << endl;
    return 0;
}