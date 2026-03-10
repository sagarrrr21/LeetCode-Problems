/*
904. Fruit Into Baskets
Solved
Medium
Topics
premium lock icon
Companies
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.



Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/

#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Time Complexity : O(n x n)
// Space Complexity : O(k)
int Brute_Force(vector<int> v, int k)
{
    int n = v.size(), max_len = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> st;

        for (int j = i; j < n; j++)
        {
            st.insert(v[j]);
            if (st.size() <= k)
            {
                max_len = max(max_len, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return max_len;
}

// Time Complexity : O(n)
// Space Complexity : O(k)
int optimal_Approach(vector<int> v, int k)
{
    int l = 0, r = 0, max_len = 0, n = v.size();
    unordered_map<int, int> mp;

    while (r < n)
    {
        mp[v[r]]++;
        if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[v[l]]--;
                if (mp[v[l]] == 0)
                    mp.erase(v[l]);
                l++;
            }
        }
        if (mp.size() <= k)
        {
            max_len = max(max_len, r - l + 1);
        }
        r++;
    }
    return max_len;
}

// Time Complexity : O(n)
// Space Complexity : O(k)
int more_Optimal(vector<int> v, int k)
{
    int l = 0, r = 0, max_len = 0, n = v.size();
    unordered_map<int, int> mp;

    while (r < n)
    {
        mp[v[r]]++;
        if (mp.size() > k)
        {
            mp[v[l]]--;
            if (mp[v[l]] == 0)
                mp.erase(v[l]);
            l++;
        }
        if (mp.size() <= k)
        {
            max_len = max(max_len, r - l + 1);
        }
        r++;
    }
    return max_len;
}
