#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution
{
public:
    /*
        TIME COMPLEXITY:
        For each state → O(N)
        Total states   → N
        Overall        → O(N^2)

        SPACE COMPLEXITY:
        Queue + ops array → O(N)
    */
    int minOperations(string s, int k)
    {
        int n = s.length();
        int zeros = 0;

        for (char &c : s)
            if (c == '0')
                zeros++;

        if (zeros == 0)
            return 0;

        vector<int> ops(n + 1, -1);

        queue<int> q;
        q.push(zeros);
        ops[zeros] = 0;

        while (!q.empty())
        {
            int z = q.front();
            q.pop();

            int minF = max(0, k - n + z);
            int maxF = min(k, z);
            for (int f = minF; f <= maxF; f++)
            {
                int newZ = z + k - 2 * f;

                if (ops[newZ] == -1)
                {
                    ops[newZ] = ops[z] + 1;
                    if (newZ == 0)
                    {
                        return ops[newZ];
                    }
                    q.push(newZ);
                }
            }
        }
        return -1;
    }
};

// Optimal Approach
class Solution
{
public:
    /*
    TIME COMPLEXITY:
    Initialization      : O(N log N)
    BFS traversal       : O(N log N)
    Overall             : O(N log N)

    SPACE COMPLEXITY:
    Sets + queue + ops  : O(N)
    */
    int minOperations(string s, int k)
    {
        int n = s.length();
        int zeros = 0;

        for (char c : s)
            if (c == '0')
                zeros++;

        if (zeros == 0)
            return 0;

        set<int> even, odd;

        for (int i = 0; i <= n; i++)
        {
            if (i % 2)
                odd.insert(i);
            else
                even.insert(i);
        }

        vector<int> ops(n + 1, -1);
        queue<int> q;

        q.push(zeros);
        ops[zeros] = 0;

        if (zeros % 2)
            odd.erase(zeros);
        else
            even.erase(zeros);

        while (!q.empty())
        {
            int z = q.front();
            q.pop();

            int min_new_z = z + k - 2 * min(k, z);
            int max_new_z = z + k - 2 * max(0, k - n + z);

            set<int> &cur = (min_new_z % 2) ? odd : even;

            auto it = cur.lower_bound(min_new_z);

            while (it != cur.end() && *it <= max_new_z)
            {
                int newZ = *it;

                ops[newZ] = ops[z] + 1;

                if (newZ == 0)
                    return ops[newZ];

                q.push(newZ);

                it = cur.erase(it);
            }
        }

        return -1;
    }
};