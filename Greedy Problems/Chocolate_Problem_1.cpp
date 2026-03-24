/*
🍫 Problem (Part 1: Chocolate Wrapper Only)

You are given:

An integer money → total money you have
An integer cost → cost of 1 chocolate
An integer k → number of wrappers required to exchange for 1 free chocolate
Rules:
You can buy chocolates using your money.
Each chocolate gives you 1 wrapper.
You can exchange k wrappers → 1 free chocolate.
The free chocolate also gives 1 wrapper.
This process continues until you cannot exchange wrappers anymore.
Task:

Return the total number of chocolates you can eat.

Constraints:
0 ≤ money ≤ 10^9
1 ≤ cost ≤ 10^9
1 ≤ k ≤ 10^9
Example 1:
Input:
money = 100
cost = 10
k = 2

Output:
19
Explanation:
Buy 10 chocolates → 10 wrappers
Exchange:
10 → 5 chocolates (wrappers = 5)
5 → 2 chocolates (wrappers = 3)
3 → 1 chocolate (wrappers = 2)
2 → 1 chocolate (wrappers = 1)
Total = 19 chocolates
Example 2:
Input:
money = 15
cost = 3
k = 3

Output:
7
Edge Case:
Input:
money = 10
cost = 0

Output:
Error
*/

#include <iostream>
using namespace std;

int totalChocolates(int money, int cost, int k)
{
    if (cost <= 0)
    {
        cout << "Error" << endl;
        return 0;
    }

    int chocolates = money / cost;
    int wrappers = chocolates;

    while (wrappers >= k)
    {
        int newChoco = wrappers / k;
        chocolates += newChoco;
        wrappers = (wrappers % k) + newChoco;
    }

    return chocolates;
}

int main()
{
    cout << totalChocolates(100, 10, 2) << endl; // Output: 19
    return 0;
}