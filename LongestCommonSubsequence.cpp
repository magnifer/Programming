#include<iostream>
using namespace std;

int LongestCommonSubsequence(string szSequence, string szSubSequence)
{
    int nSequenceLength = szSequence.length();
    int nSubSequenceLength = szSubSequence.length();

    cout << "Sequence: " << szSequence << " length: " << nSequenceLength << "\n";
    cout << "SubSequence: " << szSubSequence << " length: " << nSubSequenceLength << "\n";

    int dpArray[nSubSequenceLength + 1][nSequenceLength + 1] = { 0 };

    // Print the array
    /*for (int i = 0; i < nSubSequenceLength; i++)
    {
        for (int j = 0; j < nSequenceLength; j++)
        {
            cout << dpArray[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int i = 0; i < nSubSequenceLength; i++)
    {
        for (int j = 0; j < nSequenceLength; j++)
        {
            cout << dpArray[i][j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}

int main()
{
    string szSequence; cin >> szSequence;
    string szSubSequence; cin >> szSubSequence;
    cout << szSequence << " " << szSubSequence << "\n";

    cout << LongestCommonSubsequence(szSequence, szSubSequence);

    return 0;
}
