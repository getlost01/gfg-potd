## 13. Shortest Common Supersequence
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

The idea behind this question is to find the longest common part in two sequences. The longest string we can make is of size m+n, but when we take away the common subsequence part, we get the smallest possible string after putting them together in the same order.

To find the shortest common supersequence of two strings `X` and `Y`,
- I use the concept of the Longest Common Subsequence (LCS). 
- The idea is to find the LCS of the two strings and then subtract it from the sum of the lengths of the two strings.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(m * n)`, where m and n are the lengths of strings `X` and `Y`, respectively.
- **Auxiliary Space Complexity**: `O(m * n)`, where `m` and `n` are the lengths of strings `X` and `Y`, respectively.

### Code (C++)
```cpp
class Solution {
public:
    int LCS(string& X, string& Y, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        if (X[i] == Y[j])
            return dp[i][j] = 1 + LCS(X, Y, i - 1, j - 1, dp);

        return dp[i][j] = max(LCS(X, Y, i, j - 1, dp), LCS(X, Y, i - 1, j, dp));
    }

    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int lcs = LCS(X, Y, m - 1, n - 1, dp);
        return m + n - lcs;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.