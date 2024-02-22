## 22. Distinct occurrences
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/distinct-occurrences/1)

### My Approach
This is a question of the take-non take type of dynamic programming, which involves breaking a string into multiple strings based on a specific condition. So I also used dynamic programming to solve this problem.
  - I define a recursive function `solve` to compute the number of distinct occurrences of string `t` in string `s` starting from indices `i` and `j`.
  - At each step, we have two choices: 
    1. Not take the current character of `s`.
    2. If the current character of `s` matches the current character of `t`, then we advance both pointers.
  - We memoize the results to avoid redundant computations.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `(O(n x m))`, where `(n)` is the length of string `s` and `(m)` is the length of string `t`.
- **Auxiliary Space Complexity**: `(O(n x m))` due to the memoization table.

### Code (C++)

```cpp
class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int i, int j, int n, int m, string s, string t, vector<vector<int>>& dp) {
        if (j == m)
            return 1;
        if (i == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ntake = solve(i + 1, j, n, m, s, t, dp);
        int take = 0;
        if (s[i] == t[j])
            take = solve(i + 1, j + 1, n, m, s, t, dp);

        return dp[i][j] = (take + ntake) % mod;
    }

    int subsequenceCount(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, n, m, s, t, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.