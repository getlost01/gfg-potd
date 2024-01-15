## 15. Grinding Geek
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/grinding-geek/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

This is a standard DP problem of take and not take type problem.
I have implemented a recursive solution using dynamic programming to solve the problem. The `solve` function explores all possible combinations of courses to maximize the number of courses taken within the given budget. It considers both scenarios: `taking` the current course and `not taking` it.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of the solution is dependent on the number of subproblems computed, which is proportional to the product of the number of courses (`n`) and the total budget (`total`). Therefore, the time complexity is `O(n * total)`.

- **Auxiliary Space Complexity**: The space complexity is determined by the memory used for the memoization table (`dp`). It is `O(n * total)` since we need to store solutions for all possible subproblems.

### Code (C++)

```cpp
class Solution {
public:
    int solve(int i, int total, vector<int>& cost, vector<vector<int>>& dp){
        if(i == cost.size())
            return 0;

        if(dp[i][total] != -1)
            return dp[i][total];

        int t = 0, nt = 0;
        if(total >= cost[i]){   // for taking case
            int ac = cost[i] - floor(0.9 * cost[i]);    // actual cost that the user bears
            t = 1 + solve(i + 1, total - ac, cost, dp);
        }
        nt = solve(i + 1, total, cost, dp);	// for non taking case

        return dp[i][total] = max(t, nt);
    }

    int max_courses(int n, int total, vector<int>& cost) {
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        return solve(0, total, cost, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.