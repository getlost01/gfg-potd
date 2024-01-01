## 18. Longest Repeating Subsequence

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1)

### My Approach

To find the length of the longest repeating subsequence in a given string, I used a recursive approach with memoization.

- In function `maxSub` that takes the starting indices `i` and `j`, the length of the string `n`, the string `s`, and a memoization table `dp`.
- If `i` or `j` reaches the end of the string `n`, return 0.
- If the subproblem has already been computed and stored in `dp[i][j]`, return the result from `dp`.
- If the characters at indices `i` and `j` are equal and `i` is not equal to `j`, then the current characters contribute to the length of the repeating subsequence. Recursively call `maxSub` with `i + 1` and `j + 1` to find the length of the next repeating subsequence.
- If the characters at indices `i` and `j` are not equal, then one of them cannot be part of the repeating subsequence. Recursively call `maxSub` with either `i` and `j + 1` or `i + 1` and `j`, and take the maximum of the two results.
- Store the computed result in `dp[i][j]`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)` due to the nested recursive calls and the memoization table.
- **Auxiliary Space Complexity**: `O(n^2)` as we use a memoization table of size n * n.

### Code (C++)

```cpp
class Solution {
public:
    int maxSub(int i, int j, int n, string& s, vector<vector<int>>& dp) {
        if (i == n || j == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i != j && s[i] == s[j]) {
            dp[i][j] = 1 + maxSub(i + 1, j + 1, n, s, dp);
        } else {
            dp[i][j] = maxSub(i, j + 1, n, s, dp);
            dp[i][j] = max(dp[i][j], maxSub(i + 1, j, n, s, dp));
        }

        return dp[i][j];
    }

    int LongestRepeatingSubsequence(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return maxSub(0, 0, n, str, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
