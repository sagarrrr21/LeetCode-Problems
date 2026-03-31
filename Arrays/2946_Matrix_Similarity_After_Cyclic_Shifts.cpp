/*
2946. Matrix Similarity After Cyclic Shifts
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.

The following proccess happens k times:

Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.


Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.


Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.



Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4

Output: false

Explanation:

In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).



Example 2:

Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2

Output: true

Explanation:



Example 3:

Input: mat = [[2,2],[2,2]], k = 3

Output: true

Explanation:

As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.



Constraints:

1 <= mat.length <= 25
1 <= mat[i].length <= 25
1 <= mat[i][j] <= 25
1 <= k <= 50
*/
class Solution1
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> org = mat;
        k = k % m;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                rotate(begin(mat[i]), begin(mat[i]) + k, end(mat[i]));
            }
            else
                rotate(rbegin(mat[i]), rbegin(mat[i]) + k, rend(mat[i]));
        }
        return org == mat;
    }
};
class Solution2
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> org = mat;
        k = k % m;
        if (k == 0)
            return true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cur_idx = j;
                int final_idx;

                if (i % 2 == 0)
                    final_idx = (j + k) % m;
                else
                    final_idx = (j - k + m) % m;

                if (mat[i][cur_idx] != mat[i][final_idx])
                    return false;
            }
        }
        return true;
    }
};