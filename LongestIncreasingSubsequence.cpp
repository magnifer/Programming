/*
 * @author Deepesh Soni
 * Problem: Given an array of integers find longest increasing subsequence
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

int LongestIncreasingSubsequence(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";

    int i = 1;
    int j = 0;
    while (j < i)
    {
        if (nums[j] < nums[i])
        {
            dp[i] = max(dp[i], dp[j] + 1);
        }

        if (j + 1 == i)
        {
            if (i == nums.size() - 1 && j + 1 == nums.size() - 1)
            {
                break;
            }
            j = 0;
            ++i;
        }
        else
        {
            ++j;
        }
    }

    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result = max(dp[i], result);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";

    return result;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    LongestIncreasingSubsequence(nums);

    return 0;
}