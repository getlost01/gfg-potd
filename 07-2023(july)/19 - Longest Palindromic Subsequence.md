## 19. Longest Palindromic Subsequence

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1)

### My Approach

In order to determine the length of the longest palindromic subsequence within a given string, I used the concept of the longest common subsequence. This involved finding the longest common subsequence between the original string, denoted as `A`, and its reverse, denoted as `rev`. Let's find that out using recursion and memoization.

- The `check` function is a recursive auxiliary function that receives the current indices `i` and `j` of the original string `A` and the reversed string `rev`, respectively. It also takes the length `n` of the string and a 2D vector `dp` for memoization as parameters.
- The base case of the recursion is when either `i` or `j` reaches the end of the string. In that case, the function returns 0.
- If the result for the current indices `i` and `j` is already computed and stored in `dp`, it is directly returned.
- If the characters at indices `i` and `j` are the same, we increment the result by 1 and recursively call the function with the incremented indices.
- We also recursively call the function with the same `i` but incremented `j` and vice versa, and store the maximum of the three results in `dp[i][j]`.
- Finally, the function returns the result stored in `dp[0][0]`, which represents the length of the longest palindromic subsequence.

### Time and Auxiliary Space Complexity

- **Time Complexity**: Each recursive call reduces the problem size by 1 until `i` or `j` reaches the end of the string. Hence, the time complexity can be considered as `O(n^2)`, where `n` is the length of the string.
- **Auxiliary Space Complexity**: Since memoization array `dp`, which is of size `n x n`. Therefore, the auxiliary space complexity is `O(n^2)`.

### Code (C++)

```cpp
class Solution {
public:
    int check(int i, int j, int n, string& A, string& rev, vector<vector<int>>& dp) {
        if (i == n || j == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (A[i] == rev[j]) {
            dp[i][j] = 1 + check(i + 1, j + 1, n, A, rev, dp);
        }
        dp[i][j] = max(dp[i][j], check(i, j + 1, n, A, rev, dp));
        dp[i][j] = max(dp[i][j], check(i + 1, j, n, A, rev, dp));

        return dp[i][j];
    }

    int longestPalinSubseq(string A) {
        int n = A.size();
        string rev = A;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return check(0, 0, n, A, rev, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.