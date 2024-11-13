#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void LongestCommonSubsequence(string input1, string input2)
{
    string result;
    int len1 = input1.length() + 1;
    int len2 = input2.length() + 1;
    cout << len1 << " " << len2 << "\n";
    int T[len1][len2];
    std::fill(&T[0][0], &T[0][0] + sizeof(T) / sizeof(T[0][0]), 0);

    // for (int i = 0; i < len1; i++)
    // {
    //     for (int j = 0; j < len2; j++)
    //     {
    //         cout << T[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (input1[i - 1] == input2[j - 1])
            {
                T[i][j] = T[i - 1][j - 1] + 1;
            }
            else
            {
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);
            }
        }
    }
    // int i = len1 - 1;
    // int j = len2 - 1;
    // while (i >= 0)
    // {
    //     while (j >= 0)
    //     {
    //         if (input1[i - 1] == input2[j - 1])
    //         {
    //             result = input1[i - 1] + result;
    //             --j;
    //             break;
    //         }
    //         else
    //         {
    //             if (j - 1 != 0)
    //             {
    //                 --j;
    //             }
    //             else
    //                 break;
    //         }
    //     }
    //     --i;
    // }
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            cout << T[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "length of Longest Common Subsequence is: " << T[len1 - 1][len2 - 1];
    cout << "\nLongest common Subsequence is: " << result;
}

int main()
{
    string input1 = "acbcf";
    string input2 = "abcdef";
    // cin >> input1 >> input2;
    // cout << input1 << "\n" << input2 << "\n";

    LongestCommonSubsequence(input1, input2);

    return 0;
}