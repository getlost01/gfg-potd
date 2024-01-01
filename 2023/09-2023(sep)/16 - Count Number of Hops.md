## 16. Count Number of Hops

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1)

### My Approach

I am solving this problem using recursion and memoization.
- I maintain an array `dp`, where `dp[i]` represents the number of ways to reach step `i` in the steps. 
- I started from step 0 and calculate the number of ways to reach the next three steps (1, 2, or 3 steps at a time) recursively until I reach step `n`. 

This problem is similar to a modified Fibonacci series.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` - We calculate the number of ways for each step from 0 to `n` only once.
- **Auxiliary Space Complexity**: `O(n)` - We use an additional array `dp` of size `n`.

### Code (C++)
```cpp
class Solution {
public:
    int mod = 1e9 + 7;

    long long solve(int n, int i, vector<long long>& dp) {
        if (i == n)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        long long cnt = 0;
        for (int d = 1; d <= 3; ++d) {
            if (i + d <= n)
                cnt = (cnt + solve(n, i + d, dp)) % mod;
        }

        return dp[i] = cnt;
    }

    long long countWays(int n) {
        vector<long long> dp(n, -1);
        return solve(n, 0, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.