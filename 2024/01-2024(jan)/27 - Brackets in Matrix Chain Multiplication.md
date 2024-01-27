## 27. Brackets in Matrix Chain Multiplication
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1)

### My Approach

I implemented the matrix chain multiplication using dynamic programming with bottom-up tabulation. The steps are as follows:

- Create a 2D DP array to store minimum costs and corresponding expressions.
- For subsequences of length 1, initialize the costs and expressions.
- Iterate over the matrix chain lengths, calculating the optimal cost and expression.
- The result is stored in `dp[0][n-1].second`, which represents the optimal expression.

### Time and Auxiliary Space Complexity

- **Time Complexity:** `O(n^3)` - The nested loops iterate over all subproblems in the bottom-up approach.
- **Auxiliary Space Complexity:** `O(n^2)` - The DP array of size n x n.

### Code (C++)

```cpp
class Solution {
public:
    string matrixChainOrder(int p[], int n) {
        pair<int, string> dp[n][n];

        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                if (gap == 1) {
                    string res = "0";
                    res[0] = 'A' + i;
                    dp[i][j] = {0, res};
                } else {
                    dp[i][j] = {INT_MAX, "-1"};
                    for (int k = i + 1; k <= j - 1; k++) {
                        int cost = p[i] * p[k] * p[j] + dp[i][k].first + dp[k][j].first;
                        if (dp[i][j].first > cost) {
                            dp[i][j].first = cost;
                            dp[i][j].second = "(" + dp[i][k].second + dp[k][j].second + ")";
                        }
                    }
                }
            }
        }

        return dp[0][n - 1].second;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.