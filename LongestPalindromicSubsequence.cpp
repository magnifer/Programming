/*
 * @author Deepesh Soni
 * Problem: Given a string find Longest Palindromic Subsequence in a string
 * Time Complexity: O(n2)
 * Space Complexity: O(n2)
 */

#include <iostream>
using namespace std;

void LongestPalindromSubsequence(string input)
{
	int inputLen = input.length();
	int dp[inputLen][inputLen];

	for (int i = 0; i < inputLen; i++)
	{
		for (int j = 0; j < inputLen; j++)
		{
			dp[i][j] = (i == j) ? 1 : 0;
		}
	}

	// for (int i = 0; i < inputLen; i++)
	// {
	// 	for (int j = 0; j < inputLen; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";

	for (int length = 2; length <= inputLen; length++)
	{
		for (int i = 0; i < inputLen - length + 1; i++)
		{
			int j = i + length - 1;
			if (length == 2 && input[i] == input[j])
				dp[i][j] = 2;
			if (input[i] == input[j])
			{
				dp[i][j] = 2 + dp[i + 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}

	// for (int i = 0; i < inputLen; i++)
	// {
	// 	for (int j = 0; j < inputLen; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << dp[0][inputLen - 1];
}

int main()
{
	string input = "agbdba";
	LongestPalindromSubsequence(input);

	return 0;
}