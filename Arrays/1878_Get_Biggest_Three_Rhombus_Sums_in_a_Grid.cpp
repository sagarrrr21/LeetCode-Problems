/*
1878. Get Biggest Three Rhombus Sums in a Grid

You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.



Example 1:


Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
Example 2:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
Example 3:

Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 105
*/

// Time Complexity : O(n × m × min(n,m))
// Space Complexity : O(3) constant
class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        set<int> st;
        auto addSet = [&](int sum)
        {
            st.insert(sum);
            if (st.size() > 3)
                st.erase(st.begin());
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                addSet(grid[i][j]);
                for (int side = 1; i + side < n && i - side >= 0 &&
                                   j + side < m && j - side >= 0;
                     side++)
                {
                    int sum = 0;
                    for (int k = 0; k <= side - 1; k++)
                    {
                        sum += grid[i - side + k][j + k];
                        sum += grid[i + side - k][j - k];
                        sum += grid[i + k][j + side - k];
                        sum += grid[i - k][j - side + k];
                    }
                    addSet(sum);
                }
            }
        }
        return vector<int>(st.rbegin(), st.rend());
    }
};

// Time Complexity : O(n × m × min(n,m))
// Space Complexity : O(n x m)
class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        set<int> st;

        auto addSet = [&](int sum)
        {
            st.insert(sum);
            if (st.size() > 3)
                st.erase(st.begin());
        };

        vector<vector<int>> pf1(n, vector<int>(m, 0));
        vector<vector<int>> pf2(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pf1[i][j] = grid[i][j];
                if (i - 1 >= 0 && j - 1 >= 0)
                    pf1[i][j] += pf1[i - 1][j - 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                pf2[i][j] = grid[i][j];
                if (i - 1 >= 0 && j + 1 < m)
                    pf2[i][j] += pf2[i - 1][j + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                addSet(grid[i][j]);

                for (int side = 1; i + side < n && i - side >= 0 &&
                                   j + side < m && j - side >= 0;
                     side++)
                {

                    int t_r = i - side, t_c = j;
                    int r_r = i, r_c = j + side;
                    int b_r = i + side, b_c = j;
                    int l_r = i, l_c = j - side;

                    int sum = 0;

                    sum += pf1[r_r][r_c];
                    if (t_r - 1 >= 0 && t_c - 1 >= 0)
                        sum -= pf1[t_r - 1][t_c - 1];

                    sum += pf2[b_r][b_c];
                    if (r_r - 1 >= 0 && r_c + 1 < m)
                        sum -= pf2[r_r - 1][r_c + 1];

                    sum += pf1[b_r][b_c];
                    if (l_r - 1 >= 0 && l_c - 1 >= 0)
                        sum -= pf1[l_r - 1][l_c - 1];

                    sum += pf2[l_r][l_c];
                    if (t_r - 1 >= 0 && t_c + 1 < m)
                        sum -= pf2[t_r - 1][t_c + 1];

                    sum -= grid[t_r][t_c];
                    sum -= grid[r_r][r_c];
                    sum -= grid[b_r][b_c];
                    sum -= grid[l_r][l_c];

                    addSet(sum);
                }
            }
        }

        return vector<int>(st.rbegin(), st.rend());
    }
};