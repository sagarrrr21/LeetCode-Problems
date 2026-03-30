/*
Ninja is planing this 'N' days-long training schedule.Each day, he perform any one of these three activities. (Running, Fighting practice and learning new moves). Each activity has some merit points on each day. As Ninja has to improve all his skils, He can't do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points ninja can earn ?

you are given a 2D array of size N*3 'POINTS' with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points of merit point that ninja can earn.
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int Recursion(int day, vector<vector<int>> &POINTS, int last) // time complexity O(3^n) , space complexity O(n)
{
    if (day == 0)
    {
        int max_Points = INT8_MIN;
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
                max_Points = max(max_Points, POINTS[0][i]);
        }
        return max_Points;
    }

    int max_Points = INT8_MIN;

    for (int i = 0; i <= 2; i++)
    {

        int points = INT8_MIN;
        if (i != last)
        {
            points = POINTS[day][i] + Recursion(day - 1, POINTS, i);
        }
        max_Points = max(max_Points, points);
    }
    return max_Points;
}

int memoization(int day, vector<vector<int>> &POINTS, int last, int t[][4]) // time complexity O(n*4*3) , space complexity O(n) + O(n*4)
{
    if (day == 0)
    {
        int max_Points = INT8_MIN;

        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
            {
                max_Points = max(max_Points, POINTS[day][i]);
            }
        }
        return max_Points;
    }
    if (t[day][last] != -1)
        return t[day][last];

    int max_Points = INT8_MIN;
    for (int i = 0; i <= 2; i++)
    {
        int points = INT8_MIN;
        if (i != last)
        {
            points = POINTS[day][i] + memoization(day - 1, POINTS, i, t);
            max_Points = max(max_Points, points);
        }
    }
    return t[day][last] = max_Points;
}

int tabulation(vector<vector<int>> &POINTS)

// time complexity O(n*4)*3 , space complexity  O(n*4)
{
    int n = POINTS.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(POINTS[0][1], POINTS[0][2]);
    dp[0][1] = max(POINTS[0][0], POINTS[0][2]);
    dp[0][2] = max(POINTS[0][0], POINTS[0][1]);
    dp[0][3] = max(POINTS[0][0], max(POINTS[0][1], POINTS[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            int maxi = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = POINTS[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[n - 1][3];
}

int Optimal_approach(vector<vector<int>> POINTS)
// time complexity O(n*4*3) , space complexity  O(4)
{
    int n = POINTS.size();

    vector<int> prev(4, 0);

    prev[0] = max(POINTS[0][1], POINTS[0][2]);
    prev[1] = max(POINTS[0][0], POINTS[0][2]);
    prev[2] = max(POINTS[0][0], POINTS[0][1]);
    prev[3] = max(POINTS[0][0], max(POINTS[0][1], POINTS[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last <= 3; last++)
        {
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                    temp[last] = max(temp[last], POINTS[day][task] + prev[task]);
            }
        }
        prev = temp;
    }
    return prev[3];
}
int main()
{
    vector<vector<int>> POINTS = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    int n = POINTS.size();
    // Output : 25

    cout << "Recursion : " << Recursion(n - 1, POINTS, 3) << endl;

    int t[n][4];
    memset(t, -1, sizeof(t));
    cout << "memoization : " << memoization(n - 1, POINTS, 3, t) << endl;

    cout << "Tabulation : " << tabulation(POINTS) << endl;

    cout << "Optimal_approach : " << Optimal_approach(POINTS) << endl;

    return 0;
}