/*
 * @author Deepesh Soni
 * Problem: Given an array of non negative integers and a totalWeight, find subset in array which adds upto totalWeight.
 * Time Complexity: O(length*totalWeight)
 * Space Complexity: )(length*totalWeight)
 */

#include <iostream>
using namespace std;

int KnapsackProblem(int *value, int *weight, int length, int totalWeight)
{
    int dp[++length][++totalWeight];
    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0);

    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = 0; j < totalWeight; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < totalWeight; j++)
        {
            if (j < weight[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
        }
    }

    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = 0; j < totalWeight; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return dp[length - 1][totalWeight - 1];
}

int main()
{
    int totalWeight = 7;
    int value[] = {1, 4, 5, 7};
    int weight[] = {1, 3, 4, 5};
    int length = sizeof(value) / sizeof(value[0]);
    cout << KnapsackProblem(value, weight, length, totalWeight);

    return 0;
}