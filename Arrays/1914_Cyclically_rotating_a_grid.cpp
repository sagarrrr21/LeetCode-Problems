/*
1914. Cyclically Rotating a Grid
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:



A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:


Return the matrix after applying k cyclic rotations to it.



Example 1:


Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.
Example 2:


Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.


Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
Both m and n are even integers.
1 <= grid[i][j] <= 5000
1 <= k <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> extract_layer(vector<vector<int>> &grid, int top, int bottom, int left, int right)
    {
        vector<int> nums;

        for (int j = left; j <= right; j++)
            nums.push_back(grid[top][j]);

        for (int i = top + 1; i <= bottom; i++)
            nums.push_back(grid[i][right]);

        for (int j = right - 1; j >= left; j--)
            nums.push_back(grid[bottom][j]);

        for (int i = bottom - 1; i > top; i--)
            nums.push_back(grid[i][left]);

        return nums;
    }
    void reverse_array(int i, int j, vector<int> &nums)
    {
        while (i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverse_array(0, k - 1, nums);
        reverse_array(k, nums.size() - 1, nums);
        reverse_array(0, nums.size() - 1, nums);
    }
    void fill_layer(vector<vector<int>> &grid, int top, int bottom, int left, int right, vector<int> &nums)
    {
        int idx = 0;

        for (int j = left; j <= right; j++)
            grid[top][j] = nums[idx++];

        for (int i = top + 1; i <= bottom; i++)
            grid[i][right] = nums[idx++];

        for (int j = right - 1; j >= left; j--)
            grid[bottom][j] = nums[idx++];

        for (int i = bottom - 1; i > top; i--)
            grid[i][left] = nums[idx++];
    }
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++)
        {
            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            vector<int> nums = extract_layer(grid, top, bottom, left, right);

            rotate(nums, k);

            fill_layer(grid, top, bottom, left, right, nums);
        }

        return grid;
    }
};
