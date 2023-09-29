## 29. Number Of Enclaves

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/number-of-enclaves/1)

### My Approach

The concept is simple: mark all land connected with a boundary as `-1`, and then calculate the unmarked land as our answers.

The steps for doing so are as follows:

- **Depth-First Search (DFS):**
I've used a Depth-First Search (DFS) algorithm to traverse the grid and mark the land cells connected to the boundary as uncounted (-1).

- **Traverse the Top and Bottom Boundaries:**
I iterate through the first and last rows, checking if there are any land cells. If I find any, I initiate DFS from those cells to mark them and their connected land cells.
- **Traverse the Left and Right Boundaries:**
Similarly, I iterate through the first and last columns, initiating DFS from land cells to mark them and their connected land cells.
- **Count Remaining Land Cells:**
-Finally, I count the remaining land cells (with a value of 1) in the grid, which represents the number of enclaves.

### Time and Auxiliary Space Complexity
- **Time Complexity**: The DFS traversal of the grid takes `O(N*M)`, where N is the number of rows and M is the number of columns in the grid.
- **Auxiliary Space Complexity**: The DFS stack can use `O(N*M)` space in the worst case. Additionally, the recursive function call stack can use `O(N*M)` space in the worst case. Therefore, the total auxiliary space complexity is `O(N*M)`.

### Code (C++)
```cpp
class Solution {
public:
    int dx[4] = { -1 ,0 ,0, 1};
    int dy[4] = { 0, -1, 1, 0};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& n, int& m) {
        grid[i][j] = -1;
        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                dfs(grid, x, y, n, m);
        }
    }
    
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 1)
                dfs(grid, 0, i, n, m);
            if (grid[n - 1][i] == 1)
                dfs(grid, n - 1, i, n, m);
        }

        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, n, m);
            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1, n, m);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cnt += (grid[i][j] == 1);
        }
        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.