/*
 * @author Deepesh Soni
 * Problem: Given an array of denomination of coins and a total, find subset in array which adds upto total.
 * Time Complexity: O(length*totalWeight)
 * Space Complexity: )(length*totalWeight)
 */

#include <iostream>
using namespace std;

int NoOfCoins(int *coin, int length, int total)
{
    int dp[length][++total];
    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0);

    // for (int j = 0; j < total; j++)
    // {
    //     dp[0][j] = j;
    // }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < total; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 0; i < length; i++)
    {
        for (int j = 1; j < total; j++)
        {
            if (j < coin[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coin[i]]);
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < total; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return dp[length][total - 1];
}

int main()
{
    int total = 11;
    int coin[] = {1, 5, 6, 8};
    int length = sizeof(coin) / sizeof(coin[0]);
    cout << NoOfCoins(coin, length, total);

    return 0;
}