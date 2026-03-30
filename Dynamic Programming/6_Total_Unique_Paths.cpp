/*
You are present at point 'A' which is the top-left cell of an M x N Grid. Your destination is point 'B' which is the bottom-right cell of the same Grid, Your task is to find the total number of unique paths from 'A' to point 'B' in other words, You will be fiven the dimensions of the Grid as integers 'M' and 'N'. Your task is to find the total number of unique paths from the cell Grid[0][0] to Grid['M' - 1]['N' - 1].

To traverse in the Grid you can either move right or down at each step. For example in a given point Grid[i][j]. You can move to either Grid[i+1][j] or Grid[i][j + 1];
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int Recursion(int i, int j, vector<vector<int>> &Grid)
// time complexity O(2^n*m) , space complexity  O(path length((n-1) + (n-1)));
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = Recursion(i - 1, j, Grid);
    int left = Recursion(i, j - 1, Grid);

    return up + left;
}

int memoization(int i, int j, vector<vector<int>> &Grid, vector<vector<int>> &dp)
// time complexity O(n*m) , space complexity  O((n-1) + (m-1)) + O(n*m)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = memoization(i - 1, j, Grid, dp);
    int left = memoization(i, j - 1, Grid, dp);

    return dp[i][j] = up + left;
}

int tabulation(vector<vector<int>> &Grid, int n, int m) // time complexity O(n*m) , space complexity  O(n*m)
{
    int dp[n][m] = {0};

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
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

int Optimal_approach(vector<vector<int>> &Grid, int n, int m)
{
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                cur[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[i];
                if (j > 0)
                    left = cur[j - 1];
                cur[j] = up + left;
            }
        }
        prev = cur;
    }
    return prev[m - 1];
}

int main()
{
    vector<vector<int>> Grid = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int n = Grid.size(), m = Grid[0].size();

    cout << "Recursion : " << Recursion(n - 1, m - 1, Grid) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "memoization : " << memoization(n - 1, m - 1, Grid, dp) << endl;

    cout << "tabulation : " << tabulation(Grid, n, m) << endl;

    return 0;
}