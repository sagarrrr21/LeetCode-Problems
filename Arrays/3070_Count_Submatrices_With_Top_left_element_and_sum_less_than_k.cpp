/*
3070. Count Submatrices with Top-Left Element and Sum Less Than k
Solved
Medium
Topics
premium lock icon
Companies
You are given a 0-indexed integer matrix grid and an integer k.

Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.



Example 1:


Input: grid = [[7,6,3],[6,6,1]], k = 18
Output: 4
Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
Example 2:


Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
Output: 6
Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.


Constraints:

m == grid.length
n == grid[i].length
1 <= n, m <= 1000
0 <= grid[i][j] <= 1000
1 <= k <= 109
*/

// Time Complexity : O(n x m)
// Space Complexity : O(n x m)
class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> pf(n, vector<int>(m, 0));
        pf[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
        {
            pf[i][0] = pf[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < m; i++)
        {
            pf[0][i] = pf[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                pf[i][j] = (pf[i - 1][j] + pf[i][j - 1] + grid[i][j]) -
                           pf[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (pf[i][j] <= k)
                    ans++;
        }
        return ans;
    }
};

// Time Comeplxity : O(n x m)
// Space Complexity : O(m)

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();

        vector<int> prev(m, 0), cur(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = (i > 0 ? prev[j] : 0);
                int left = (j > 0 ? cur[j - 1] : 0);
                int diag = (i > 0 && j > 0 ? prev[j - 1] : 0);

                cur[j] = grid[i][j] + up + left - diag;

                if (cur[j] <= k)
                    ans++;
            }
            prev = cur;
        }
        return ans;
    }
};