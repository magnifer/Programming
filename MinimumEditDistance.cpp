/*
 * @author Deepesh Soni
 * Problem: Given 2 strings how many minimum operations(update, delete or add) are required to convert 1 string to another
 * Time Complexity: O(m*n)
 * Space Complexity: (m*n)
 */

#include <iostream>
using namespace std;

int MinimumEditDistance(string input1, string input2)
{
    int len1 = input1.length() + 1;
    int len2 = input2.length() + 1;

    int dp[len1][len2];

    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0);
    for (int i = 0; i < len1; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j < len2; j++)
    {
        dp[0][j] = j;
    }

    // for (int i = 0; i < len1; i++)
    // {
    //     for (int j = 0; j < len2; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (input1[i - 1] == input2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }

    // for (int i = 0; i < len1; i++)
    // {
    //     for (int j = 0; j < len2; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return dp[len1 - 1][len2 - 1];
}

int main()
{
    // string input1, input2;
    // cin >> input1 >> input2;
    // cout << input1 << input2;

    cout << MinimumEditDistance("azced", "abcdef");

    return 0;
}