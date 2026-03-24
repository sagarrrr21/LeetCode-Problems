/*
You are given:

An integer balance → total money you have
An integer cost → cost of 1 chocolate
An integer k → number of wrappers required to exchange for 1 free chocolate
An integer bonus → extra money you receive for each wrapper exchange

Rules:
You can initially buy chocolates using your balance.
Each chocolate gives you 1 wrapper.
You can exchange k wrappers → 1 free chocolate.
For every such exchange, you also receive bonus money.
The bonus money can be used to buy more chocolates.
This process continues until:
You cannot exchange wrappers anymore AND
You don't have enough money to buy a new chocolate.
Task:

Return the total number of chocolates you can eat.

Constraints:
0 ≤ balance ≤ 10^9
1 ≤ cost ≤ 10^9
0 ≤ k ≤ 10^9
0 ≤ bonus ≤ 10^9

Example 1:
Input:

balance = 100
cost = 10
k = 2
bonus = 5

Output:
19

Explanation:
Buy 10 chocolates → 10 wrappers
Exchange wrappers:
10 wrappers → 5 chocolates + ₹25
Continue process using wrappers + bonus money
Final total = 19 chocolates

Example 2:
Input:

balance = 100
cost = 10
k = 0
bonus = 0

Output:
10

Explanation:
No wrapper offer → only direct purchase
100 / 10 = 10 chocolates
Edge Case:
Input:
balance = 100
cost = 0

Output:
Error (invalid input)
*/

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int solution(int balance, int cost, int k, int bonus)
{
    if (cost <= 0)
    {
        cout << "Error" << endl;
        return 0;
    }

    int chocolates = balance / cost;
    int wrappers = chocolates;
    balance = balance % cost;

    while (wrappers >= k && k > 0 || balance >= cost)
    {

        if (k > 0 && wrappers >= k)
        {
            int newchoco = wrappers / k;
            wrappers = wrappers % k;

            chocolates += newchoco;
            wrappers += newchoco;
            balance += newchoco * bonus;
        }

        if (balance >= cost)
        {
            int newchoco = balance / cost;
            chocolates += newchoco;
            wrappers += newchoco;
            balance = balance % cost;
        }
    }

    return chocolates;
}

int main()
{
    cout << solution(100, 10, 2, 5) << endl;
    return 0;
}