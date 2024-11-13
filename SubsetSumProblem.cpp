/*
 * @author Deepesh Soni
 * Problem: Given an array of non negative integers and a total, find subset in array which adds upto total.
 * Time Complexity: O(length*total)
 * Space Complexity: )(length*total)
 */

#include <iostream>
using namespace std;

int SubsetSumProblem(int *input, int length, int total)
{
    bool dp[length + 1][total + 1];
    length += 1;
    total += 1;
    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), true);

    for (int j = 0; j < total; j++)
    {
        dp[0][j] = (j == 0) ? true : false;
    }

    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = 0; j < total; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for (int i = 1; i < length; i++)
    {
        for (int j = 1; j < total; j++)
        {
            if (j < input[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - input[i - 1]];
            }
        }
    }

    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = 0; j < total; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return dp[length - 1][total - 1];
}

int main()
{
    int total = 11;
    int input[] = {2, 3, 7, 8, 10};
    int length = sizeof(input) / sizeof(input[0]);
    cout << SubsetSumProblem(input, length, total);

    return 0;
}