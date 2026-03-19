/*
3212. Count Submatrices With Equal Frequency of X and Y
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:

grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.


Example 1:

Input: grid = [["X","Y","."],["Y",".","."]]

Output: 3

Explanation:



Example 2:

Input: grid = [["X","X"],["X","Y"]]

Output: 0

Explanation:

No submatrix has an equal frequency of 'X' and 'Y'.

Example 3:

Input: grid = [[".","."],[".","."]]

Output: 0

Explanation:

No submatrix has at least one 'X'.



Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 'X', 'Y', or '.'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pf_x(n, vector<int>(m, 0));
        vector<vector<int>> pf_y(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pf_x[i][j] = (grid[i][j] == 'X');
                pf_y[i][j] = (grid[i][j] == 'Y');

                if (i - 1 >= 0)
                {
                    pf_x[i][j] += pf_x[i - 1][j];
                    pf_y[i][j] += pf_y[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    pf_x[i][j] += pf_x[i][j - 1];
                    pf_y[i][j] += pf_y[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    pf_x[i][j] -= pf_x[i - 1][j - 1];
                    pf_y[i][j] -= pf_y[i - 1][j - 1];
                }
                if (pf_x[i][j] == pf_y[i][j] && pf_x[i][j] > 0)
                    cnt++;
            }
        }
        return cnt;
    }
};