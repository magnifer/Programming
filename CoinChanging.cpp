/*
 * @author Deepesh Soni
 * Problem: Given an array of denomination of coins and a amount, find subset in array which adds upto amount.
 * Time Complexity: O(length*amount)
 * Space Complexity: )(length*amount)
 */

#include <iostream>
#include <vector>
using namespace std;

int NoOfCoins(vector<int> &coins, int amount)
{
    vector<long> dp(amount + 1, INT32_MAX);
    dp[0] = 0;

    for (int j = 0; j <= amount; j++)
    {
        cout << dp[j] << " ";
    }
    cout << "\n";

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            cout << dp[j] << " ";
        }
        cout << "\n";
    }

    return dp[amount] == INT32_MAX ? -1 : dp[amount];
}

int main()
{
    int amount = 11;
    vector<int> coins = {1, 2, 5};
    int length = sizeof(coins) / sizeof(coins[0]);
    cout << NoOfCoins(coins, amount);

    return 0;
}