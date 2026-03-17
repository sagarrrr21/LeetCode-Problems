/*
1727. Largest Submatrix With Rearrangements
Medium
Topics
premium lock icon
Companies
Hint
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.



Example 1:


Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
Example 2:


Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] is either 0 or 1.
*/

// Time Complexity : O(n x mlogm)
// Space Complexity : O(m)
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int max_area = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1 && i > 0)
                {
                    mat[i][j] += mat[i - 1][j];
                }
            }
            vector<int> heights = mat[i];
            sort(begin(heights), end(heights), greater<int>());

            for (int h = 0; h < m; h++)
            {
                int base = (h + 1);
                int height = heights[h];

                max_area = max(max_area, base * height);
            }
        }
        return max_area;
    }
};

// Time Complexity : O(n x mlogm)
// Space Complexity : O(m)
class Solution2
{
public:
    int largestSubmatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int max_area = 0;
        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++)
        {
            vector<int> cur = mat[i];

            for (int j = 0; j < m; j++)
            {
                if (cur[j] == 1)
                {
                    cur[j] += prev[j];
                }
            }
            vector<int> heights = cur;
            sort(begin(heights), end(heights), greater<int>());

            for (int h = 0; h < m; h++)
            {
                int base = (h + 1);
                int height = heights[h];

                max_area = max(max_area, base * height);
            }

            prev = cur;
        }
        return max_area;
    }
};
// Time Complexity : O(n x m)
// Space Complexity : O(m)
class Solution3
{
public:
    int largestSubmatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();

        int max_area = 0;

        vector<pair<int, int>> prev;

        for (int i = 0; i < n; i++)
        {

            vector<pair<int, int>> cur;
            vector<bool> seen(m, false);

            for (auto [height, col] : prev)
            {
                if (mat[i][col] == 1)
                {
                    cur.push_back({height + 1, col});
                    seen[col] = true;
                }
            }

            for (int j = 0; j < m; j++)
            {
                if (seen[j] == false && mat[i][j] == 1)
                    cur.push_back({1, j});
            }

            for (int j = 0; j < cur.size(); j++)
            {
                int h = cur[j].first;
                int b = j + 1;
                max_area = max(max_area, b * h);
            }
            prev = cur;
        }
        return max_area;
    }
};