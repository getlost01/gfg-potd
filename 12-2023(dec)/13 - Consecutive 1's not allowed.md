## 13. Consecutive 1's not allowed
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
To count the number of binary strings of length `n` such that there are no consecutive 1's, I use dynamic programming. 
- I maintain a dynamic programming array `dp`, where `dp[i]` represents the count of valid binary strings of length `i`. 
- The recurrence relation is `dp[i] = dp[i-1] + dp[i-2]`, as for each position, I can either append a '0' or '1' to the strings of length `i-1` and `i-2`. I use modular arithmetic to handle large numbers and avoid overflow.

### Explain with example
Let's take an example with `n = 4`.

- For `n = 1`, there are 2 strings: `"0"` and `"1"`.
- For `n = 2`, there are 3 strings: `"00"`, `"01"`, and `"10"`.
- For `n = 3`, there are 5 strings: `"000"`, `"001"`, `"010"`, `"100"`, and `"101"`.
- For `n = 4` (the target), there are 8 strings: `"0000"`, `"0001"`, `"0010"`, `"0100"`, `"0101"`, `"1000"`, `"1001"`, and `"1010"`.

### Time and Auxiliary Space Complexity

- **Time Complexity**:  `O(N)`, where N is the size of the array.
- **Auxiliary Space Complexity**: `O(n)`, where n is the size of the dp array.

### Code (C++)
```cpp
class Solution {
public:
    int mod = 1e9 + 7;

    long long countStrings(int n) {
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }

        return dp[n];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.