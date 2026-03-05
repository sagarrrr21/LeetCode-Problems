/* You have to find the first negative number in every window of size k
ex :
input : nums = {-8 , 2 , 3 , -6, 10};
ouput : {-8 , 0 , -6 , -6}
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)

vector<int> printFirstNegInt(vector<int> nums, int n, int k)
{
    vector<int> result;
    deque<int> deq;

    int i = 0, j = 0;

    while (j < n)
    {
        if (nums[j] < 0)
        {
            deq.push_back(nums[j]);
        }
        if (j - i + 1 == k)
        {
            if (!deq.empty())
            {
                result.push_back(deq.front());
            }
            else
            {
                result.push_back(0);
            }
            if (nums[i] < 0 && !deq.empty())
            {
                deq.pop_front();
            }
            i++;
        }
        j++;
    }
    return result;
}

int main()
{
    vector<int> nums = {2, -5, 5, -2, -1, 1, 10, -3, 8, 7, -3};
    int n = nums.size();
    int k = 3;

    vector<int> ans = printFirstNegInt(nums, n, k);

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}