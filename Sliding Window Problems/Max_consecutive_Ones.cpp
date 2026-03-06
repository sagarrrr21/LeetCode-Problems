// you can flip zero's kth time to get maximum numbers of consecutive ones
#include <iostream>

using namespace std;

int Brute_Force(int *a, int k, int n)
{
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        int zeros = 0;
        for (int j = i; j < n; j++)
        {
            if (a[j] == 0)
                zeros++;
            if (zeros <= k)
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

int Optimal_Approach(int *a, int k, int n)
{
    int max_len = 0, l = 0, r = 0, zeros = 0;

    while (r < n)
    {
        if (a[r] == 0)
        {
            zeros++;
        }
        while (zeros > k)
        {
            if (a[l] == 0)
                zeros--;
            l++;
        }
        if (zeros <= k)
        {
            max_len = max(max_len, r - l + 1);
        }
        r++;
    }
    return max_len;
}

int more_Optimal_Approach(int *a, int k, int n)
{
    int l = 0, r = 0, zeros = 0, max_len = 0;

    while (r < n)
    {
        if (a[r] == 0)
            zeros++;
        if (zeros > k)
        {
            if (a[l] == 0)
                zeros--;
            l++;
        }
        if (zeros <= k)
        {
            max_len = max(max_len, r - l + 1);
        }
        r++;
    }
    return max_len;
}

int main()
{
    int a[] = {1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1};
    int k = 2;

    int n = sizeof(a) / sizeof(a[0]);

    cout << "Brute Force of finding consecutive ones : " << Brute_Force(a, k, n) << endl;

    cout << "Optimal Approach of finding consecutive ones : " << Optimal_Approach(a, k, n) << endl;

    cout << "more Optimal Approach of finding consecutive ones : " << more_Optimal_Approach(a, k, n) << endl;

    return 0;
}