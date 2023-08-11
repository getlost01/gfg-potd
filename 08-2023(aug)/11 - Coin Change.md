## 11.Coin Change

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/coin-change2448/1)

### My Approach

To solve this problem, I use dynamic programming. I create a 2D DP array `dp` where `dp[i][s]` represents the number of ways to make the sum `s` using the first `i` coins. I initialize `dp[0][s]` with `1` if `s` is divisible by the value of the first coin as base case.

Then, I iterate through the coins and the target sum. For each combination, I calculate two possibilities:
1. Not taking the current coin (`nottake = dp[i - 1][s]`)
2. Taking the current coin (`take = dp[i][s - coins[i]]` if `s - coins[i] >= 0`)

The total number of ways to make the sum `s` using the first `i` coins is `dp[i][s] = take + nottake`.

### Explanation with Example

Consider the example `coins = [1, 2, 3]`, `N = 3`, and `sum = 4`. The DP table would look like this:

|     | 0 | 1 | 2 | 3 | 4 |
|-----|---|---|---|---|---|
| 0   | 1 | 1 | 1 | 1 | 1 |
| 1   | 1 | 1 | 2 | 2 | 3 |
| 2   | 1 | 1 | 2 | 3 | 4 |

The value at `dp[2][4]` represents the number of ways to make the sum 4 using coins `[1, 2, 3]`, which is 4.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N * sum)`, where `N` is the number of coins and `sum` is the given target sum.
- **Auxiliary Space Complexity**: `O(N * sum)`, as we use a 2D DP array to store intermediate results.

### Code (C++)
```cpp
class Solution {
public:
    long long int count(int coins[], int N, int sum) {
        long long int dp[N][sum + 1];

        for (int i = 0; i <= sum; ++i)
            dp[0][i] = (i % coins[0] == 0);

        for (int i = 1; i < N; ++i) {
            for (int s = 0; s <= sum; ++s) {
                long long int nottake = dp[i - 1][s];
                long long int take = 0;

                if (s - coins[i] >= 0)
                    take = dp[i][s - coins[i]];

                dp[i][s] = take + nottake;
            }
        }

        return dp[N - 1][sum];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.