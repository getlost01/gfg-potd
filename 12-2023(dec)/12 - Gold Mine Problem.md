## 12. Gold Mine Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
This problem can be solved using dynamic programming. I use a recursive approach to traverse through the possible paths and memoize the results using a 2D vector `dp` to avoid recomputation. 
- The function `traverse` calculates the maximum gold collected starting from each cell in the first column and moving to adjacent cells in the next columns `[-1, 0 , 1]`(to right up , to right or to right down). The result is the maximum gold collected among all starting cells in the first column.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n * m)`, where n is the number of rows and m is the number of columns in the grid.
- **Auxiliary Space Complexity**: `O(n * m)`, for the memoization table.

### Code (C++)
```cpp
class Solution {
public:
    vector<vector<int>> dp;

    bool isValid(int& i, int& j, int& n, int& m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int traverse(int i, int j, vector<vector<int>>& M, int& n, int& m) {
        int out = 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        for (int d = -1; d <= 1; ++d) {
            int x = i + d;
            int y = j + 1;
            if (isValid(x, y, n, m))
                out = max(out, traverse(x, y, M, n, m));
        }
        return dp[i][j] = out + M[i][j];
    }

    int maxGold(int n, int m, vector<vector<int>> M) {
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int out = 0;
        for (int i = 0; i < n; ++i) {
            out = max(out, traverse(i, 0, M, n, m));
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.