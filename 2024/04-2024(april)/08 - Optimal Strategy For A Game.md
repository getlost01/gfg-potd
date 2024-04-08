## 08. Optimal Strategy For A Game
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1)

### My Approach
The approach involves using dynamic programming to solve the problem. 
- I created a 2D DP array to store the maximum possible value we can obtain by choosing from a certain range of coins. 
- At each step, we consider two choices: either pick the coin at the beginning or the end of the remaining coins. 
- We choose the option that gives us the maximum value. This process is repeated recursively for smaller subproblems, and the result is memoized in the DP array to avoid redundant computations.

### Time and Auxiliary Space Complexity
- **Time Complexity**: `O(n^2)`, where n is the number of coins.
- **Auxiliary Space Complexity**: `O(n^2)`, for the DP array.

### Code (C++)
```cpp
class Solution {
public:
    vector<vector<long long>> dp;
    
    long long solve(int arr[], int i, int j, int& n) {
        if (i >= n || j < 0 || j - i + 1 <= 0)
            return 0;
            
        if (dp[i][j] != -1)
            return dp[i][j];
        
        long long d1, d2;
        d1 = arr[i] + min(solve(arr, i + 2, j, n), solve(arr, i + 1, j - 1, n));
        d2 = arr[j] + min(solve(arr, i + 1, j - 1, n), solve(arr, i, j - 2, n));
        return dp[i][j] = max(d1, d2);
    }
    
    long long maximumAmount(int n, int arr[]) {
        dp = vector<vector<long long>>(1001, vector<long long>(1001, -1));
        return solve(arr, 0, n - 1, n);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.