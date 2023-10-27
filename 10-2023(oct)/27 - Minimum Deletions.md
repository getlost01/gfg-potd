## 27. Minimum Deletions
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
Usually, to see if a string is a palindrome, we compare the given string with its reverse. Similarly, we look at the Longest Common Subsequence between the original string and its reverse to find the minimum deletions needed to make a string a palindrome. So, the minimum deletions required are the difference between the string's length and the LCS length.

To do this, we follow these steps:
- We use recursion and memoization to compute the Longest Common Subsequence (LCS) of the string and its reverse.
	- Define a function `lcs` that takes two strings `S` and `revS`, two integers `i` and `j`, and a 2D vector `dp`.
	- Check if either `i` or `j` is -1. If true, return 0 as base cases.
	- Check if `dp[i][j]` is not computed (`dp[i][j] != -1`). If it's computed, return `dp[i][j]`.
	- Check if `S[i]` equals `revS[j]`. If true, compute `dp[i][j]` as `1 + lcs(S, revS, i - 1, j - 1, dp)` as we find one common character and add it for further steps.
	- If `S[i]` and `revS[j]` are different, compute two values:
	   - `checkS` as `lcs(S, revS, i - 1, j, dp)`.
	   - `checkRevS` as `lcs(S, revS, i, j - 1, dp)`.
	   - return the `dp[i][j]` as the maximum of `checkS` and `checkRevS`.
- The minimum number of deletions required is determined by the difference between the string's length and the length of the LCS.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N^2)`, where `N` is the length of the input string `S`. This is because we use dynamic programming to calculate the LCS.
- **Auxiliary Space Complexity**: `O(N^2)`, as we use a 2D DP array to store intermediate results.

### Code (C++)
```cpp
class Solution {
public:
    int lcs(string &S, string &revS, int i, int j, vector<vector<int> > &dp) {
        if (i == -1 || j == -1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (S[i] == revS[j])
            return dp[i][j] = 1 + lcs(S, revS, i - 1, j - 1, dp);

        int checkS = lcs(S, revS, i - 1, j, dp);
        int checkRevS = lcs(S, revS, i, j - 1, dp);
        return dp[i][j] = max(checkS, checkRevS);
    }

    int minimumNumberOfDeletions(string S) {
        int n = S.size();
        string revS = S;
        reverse(revS.begin(), revS.end());
        vector<vector<int> > dp(n, vector<int>(n, -1));

        return n - lcs(S, revS, n - 1, n - 1, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.