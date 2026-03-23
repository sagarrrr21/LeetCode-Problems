/*
1594. Maximum Non Negative Product in a Matrix
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

Notice that the modulo is performed after getting the maximum product.



Example 1:


Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
Output: -1
Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
Example 2:


Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
Example 3:


Input: grid = [[1,3],[0,-4]]
Output: 0
Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
-4 <= grid[i][j] <= 4
*/

class Solution
{
public:
    int M = 1e9 + 7;
    int m, n;
    typedef long long ll;
    pair<ll, ll> Recursion(int i, int j, vector<vector<int>> &grid)
    {
        if (i == m - 1 && j == n - 1)
            return {grid[i][j], grid[i][j]};

        ll max_val = LLONG_MIN;
        ll min_val = LLONG_MAX;

        if (i + 1 < m)
        {
            auto [downMax, downMin] = Recursion(i + 1, j, grid);
            max_val =
                max({max_val, grid[i][j] * downMax, grid[i][j] * downMin});
            min_val =
                min({min_val, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        if (j + 1 < n)
        {
            auto [rightMax, rightMin] = Recursion(i, j + 1, grid);

            max_val =
                max({max_val, grid[i][j] * rightMax, grid[i][j] * rightMin});
            min_val =
                min({min_val, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }
        return {max_val, min_val};
    }
    int maxProductPath(vector<vector<int>> &grid)
    {
        this->m = grid.size();
        this->n = grid[0].size();

        auto [maxProd, minProd] = Recursion(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % M;
    }
};

class Solution
{
public:
    int M = 1e9 + 7;
    int m, n;
    typedef long long ll;
    vector<vector<pair<ll, ll>>> dp;
    pair<ll, ll> Recursion(int i, int j, vector<vector<int>> &grid)
    {
        if (i == m - 1 && j == n - 1)
            return {grid[i][j], grid[i][j]};
        if (dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX))
            return dp[i][j];
        ll max_val = LLONG_MIN;
        ll min_val = LLONG_MAX;

        if (i + 1 < m)
        {
            auto [downMax, downMin] = Recursion(i + 1, j, grid);
            max_val =
                max({max_val, grid[i][j] * downMax, grid[i][j] * downMin});
            min_val =
                min({min_val, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        if (j + 1 < n)
        {
            auto [rightMax, rightMin] = Recursion(i, j + 1, grid);

            max_val =
                max({max_val, grid[i][j] * rightMax, grid[i][j] * rightMin});
            min_val =
                min({min_val, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }
        return dp[i][j] = {max_val, min_val};
    }
    int maxProductPath(vector<vector<int>> &grid)
    {
        this->m = grid.size();
        this->n = grid[0].size();
        dp = vector<vector<pair<ll, ll>>>(
            m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = Recursion(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % M;
    }
};