## 09. Minimum Points To Reach Destination
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1)

### My Approach
- We will use dynamic programming to solve this problem. 
- We initialize a 2D DP array `dp` of size `m x n`, where `dp[i][j]` represents the minimum points required to reach the destination starting from `(i, j)`.
- We start from the bottom-right corner and move upwards and leftwards, calculating the minimum points required at each cell to reach the destination.
- At each cell `(i, j)`, we calculate `dp[i][j]` using the formula: `dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - points[i][j])`.
- We return `dp[0][0]` which represents the minimum points required to reach the destination starting from the top-left corner.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(m * n)`, where m is the number of rows and n is the number of columns in the `points` matrix.

- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(m * n)` due to the dynamic programming matrix `dp`.

### Code (C++)
```cpp
class Solution {
public:
    int minPoints(int m, int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = max(1, 1 - points[m - 1][n - 1]);

        for (int i = m - 2; i >= 0; --i)
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - points[i][n - 1]);

        for (int i = n - 2; i >= 0; --i)
            dp[m - 1][i] = max(1, dp[m - 1][i + 1] - points[m - 1][i]);

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - points[i][j]);
            }
        }

        return dp[0][0];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.