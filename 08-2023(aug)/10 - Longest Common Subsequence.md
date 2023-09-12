## 10. Longest Common Subsequence

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)

### My Approach

This is a standard dynamic programming problem. To solve it, I follow these logic:

- Initialize a 2D array `dp` of size `(n+1) * (m+1)` to store the lengths of the longest common subsequences of substrings at each instance.
- Initialize the first row and the first column of `dp` with zeros since they represent the base case: the longest common subsequence with an empty string is zero.
- Iterate through the strings `s1` and `s2`. For each character:
    - If they match, update `dp[i][j]` as `1 + dp[i-1][j-1]`.
    - Otherwise, set it to the maximum of `dp[i-1][j]` and `dp[i][j-1]`.
- The final value at `dp[n][m]` will be the length of the longest common subsequence.

### Explanation with Example

Consider the strings:
```js
s1 = "AGGTAB"
s2 = "GXTXAYB"
```
Using the dynamic programming approach, the `dp` table would look like this, where the value of `dp[i][j]` represents the longest subsequence found at that instance.

```js
   0  0  0  0  0  0  0
   0  0  1  1  1  1  1
   0  1  1  1  1  2  2
   0  1  1  1  1  2  2
   0  1  1  2  2  2  2
   0  1  1  2  2  3  3
```
The final value at `dp[6][7]` is `3`, which is the length of the longest common subsequence.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n * m)`, where `n` is the length of `s1` and `m` is the length of `s2`.
- **Auxiliary Space Complexity**: `O(n * m)`, as we are using a 2D array `dp` of size `(n+1)*(m+1)`.

### Code (C++)

```cpp
class Solution {
public:
    int lcs(int n, int m, string s1, string s2) {
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;

        for (int i = 0; i <= m; ++i)
            dp[0][i] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.