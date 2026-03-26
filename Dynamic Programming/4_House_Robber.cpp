/*
Mr.X is a proffesional robber planning to rob houses algong a street. Each house has a certain amount of money hidden. All house along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile , adjacent houses have a security system connect, and it will automatically contact the police if two adjacent houses were broken into on the same night.
you are given an array of non-negative integers nums representing the amount of money of each house. Your task is to return the maximum amount of money Mr.X can rob tonight without alerting the police.
*/

#include <iostream>
#include <vector>
using namespace std;

int Optimal_approach(vector<int> nums) // time complexity O(n) , space complexity O(1)
{
    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int take = nums[i];

        if (i - 2 >= 0)
            take = nums[i] + prev2;
        int not_take = prev;

        int cur = max(take, not_take);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main()
{
    vector<int> nums = {2, 3, 1, 5, 1, 6, 7, 9, 0};
    vector<int> temp1, temp2;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }

    cout << "Optimal_approach : " << max(Optimal_approach(temp1), Optimal_approach(temp2)) << endl;

    
    return 0;
}