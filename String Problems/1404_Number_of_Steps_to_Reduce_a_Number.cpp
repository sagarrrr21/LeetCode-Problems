#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    void addOne(string &s)
    {
        int i;
        for (i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                break;
            }
            s[i] = '0';
        }

        if (i < 0)
            s = '1' + s;
    }

    // TC: O(n^2)
    // SC: O(1)
    int numSteps(string s)
    {
        int ops = 0;

        // Worst case:
        // addOne() takes O(n)
        // loop runs O(n) times
        // => Total O(n^2)

        while (s.length() > 1)
        {
            int n = s.length();

            if (s[n - 1] == '0')
                s.pop_back(); // divide by 2 -> O(1)
            else
                addOne(s); // add 1 -> O(n)

            ops++;
        }
        return ops;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    int numSteps(string s)
    {
        int n = s.length();

        int op = 0, carry = 0;

        // Single traversal from right to left
        for (int i = n - 1; i >= 1; i--)
        {
            if (((s[i] - '0') + carry) % 2 == 1)
            {
                op += 2; // add 1 + divide by 2
                carry = 1;
            }
            else
                op += 1; // only divide by 2
        }

        return op + carry;
    }
};