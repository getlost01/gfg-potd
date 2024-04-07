## 07. Maximize dot product
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1)

### My Approach
To solve this problem, we use dynamic programming. We initialize a 2D array `dp` of size `(n+1) x (m+1)` to store the maximum dot product for subarrays of `a` and `b`. - We initialize `dp[0][j]` to `INT_MIN` for handling cases where one of the arrays is empty. 
- Then, we iterate over the arrays `a` and `b`, and for each pair of elements, we update `dp[i][j]` to be the maximum of either the dot product of the subarrays ending at index `i` and `j` or the dot product of the subarrays ending at index `i-1` and `j`. 
- Finally, we return `dp[n][m]` which represents the maximum dot product.

### Time and Auxiliary Space Complexity
- **Time Complexity** : `O(n * m)`, where `n` is the size of array `a` and `m` is the size of array `b`.
- **Auxiliary Space Complexity** : `O(n * m)`, for the `dp` array.

### Code (C++)
```cpp
class Solution {
public:
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int j = 1; j <= m; ++j)
            dp[0][j] = INT_MIN;
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * b[j - 1]);
        
        return dp[n][m];
    } 
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.