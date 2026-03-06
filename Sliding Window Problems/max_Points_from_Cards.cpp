#include <iostream>

using namespace std;
// You can either pick up from the front or you can either pick up from the back
int solve(int *a, int k, int n)
{
    int l_Sum = 0, r_Sum = 0, max_Sum = 0;
    for (int i = 0; i <= k - 1; i++)
    {
        l_Sum += a[i];
    }
    max_Sum = l_Sum;

    int r_index = n - 1;

    for (int i = k - 1; i >= 0; i--)
    {
        l_Sum = l_Sum - a[i];
        r_Sum += a[r_index];
        r_index--;

        max_Sum = max(max_Sum, l_Sum + r_Sum);
    }
    return max_Sum;
}

int main()
{
    int a[] = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 4;

    cout << solve(a, k, 9) << endl;

    return 0;
}