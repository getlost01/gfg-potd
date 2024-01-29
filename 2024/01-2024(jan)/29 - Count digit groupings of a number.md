## 29. Count digit groupings of a number
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1)

### My Approach
- I use a recursive approach where I start iterating through the string from left to right.
- For each digit, I add it to the current sum, and if the sum becomes greater than or equal to the current target sum, I recursively call the function with the updated parameters.
- I memoize the results to avoid redundant computations.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N * M)`, where `N` is the length of the string and `M` is the sum of digits in the string.
- **Auxiliary Space Complexity**: `O(N * M)`, for the memoization table.

### Code (C++)
```cpp
class Solution {
public:
    int solve(int cp, int cs, int sz, string s, vector<vector<int>>& dp) {
        if (cp == sz) 
            return 1;
            
        if (dp[cp][cs] != -1) 
            return dp[cp][cs];
            
        int sm = 0, cnt = 0;

        for (int i = cp; i < sz; i++) {
            sm += s[i] - '0';
            if (sm >= cs) 
                cnt += solve(i + 1, sm, sz, s, dp);
        }

        return dp[cp][cs] = cnt;
    }

    int TotalCount(string str) {
        int sm = 0;
        for (auto i : str) 
            sm += i - '0';
			
        vector<vector<int>> dp(str.size() + 1, vector<int>(sm + 1, -1));

        return solve(0, 0, str.size(), str, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.