## 30. LCS of three strings
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1)

### My Approach
I have used dynamic programming to solve this problem. I created a 3D array `dp` to store the length of the Longest Common Subsequence (LCS) of substrings of A, B, and C. The recurrence relation is based on comparing characters at each position. If the characters are equal, I update the length based on the LCS of the substrings without these characters. The final answer is stored in `dp[n1][n2][n3]`, representing the LCS of the entire strings A, B, and C.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n1 * n2 * n3)` where n1, n2, and n3 are the lengths of strings A, B, and C, respectively.
- **Auxiliary Space Complexity**: `O(n1 * n2 * n3)` for the dp array.

### Code (C++)
```cpp
class Solution {
public:
    int LCSof3(string A, string B, string C, int n1, int n2, int n3) {
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                for (int k = 1; k <= n3; k++) {
                    if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - 1][k - 1]);
                    dp[i][j][k] = max({dp[i][j][k], dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
        return dp[n1][n2][n3];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.