## 16. Making A Large Island
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/making-a-large-island/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach

To solve this problem, we first have to identify each island in the grid and calculate its size using Depth-First Search (DFS). 
- Then assign a unique identifier to each island and store the size of each island in a hashmap. 
- Then, I iterate through the grid again and, for each water cell `0`, 
	- I check its neighbouring islands, calculate the combined size of these neighbouring islands, and determine the maximum size of an island that can be created by changing this water cell to land. 
	- I keep track of the maximum island size found during this process.

### Explain with example
Consider the following grid where 1 represents land and 0 represents water:

```cpp
Lets example :
n = 5
and grid = 1 1 0 0 0
           1 0 0 1 1
           0 1 0 0 1
           1 1 0 1 1

- Step 1: Identify and label the islands with unique using some id.
  2 2 0 0 0
  2 0 0 3 3
  0 4 0 0 3
  4 4 0 3 3
  
- Step 2: Calculate the size of each island.
  Island sizes: 
  | id | size |
  | 2  |   3  |
  | 3  |   5  | 
  | 4  |   3  |
  
- Step 3: Iterate through water cells and calculate the maximum island size that can be created by changing the water cell to land.
- Calculate the combined size of neighbouring islands and determine the maximum size for each water cell. 

Let's try some cases:
  2  2  0 0 0
  2 [1] 0 3 3    => Island formed of size = 3 + 3 + 1 = 7
  0  4  0 0 3
  4  4  0 3 3
  
  2  2 0 0 0
  2  0 0 3 3    => Island formed of size = 3 + 3 + 1= 7
 [1] 4 0 0 3
  4  4 0 3 3
  
  2 2  0  0 0
  2 0  0  3 3    => Island formed of size = 3 + 5 + 1= 9
  0 4  0  0 3
  4 4 [1] 3 3

- Max island size found during this process: 9
```

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N^2)`, where `N` is the size of the grid.
- **Auxiliary Space Complexity**: `O(N^2)` for the hashmap to store island sizes.

### Code (C++)
```cpp
class Solution {
public:
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int& id, int& n) {
        grid[i][j] = id;
        int c = 1;
        for (int d = 0; d < 4; ++d) {
            int x = dx[d] + i;
            int y = dy[d] + j;
            if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1)
                c += dfs(grid, x, y, id, n);
        }
        return c;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int out = 0;
        unordered_map<int, int> mp;
        int id = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++id;
                    int c = dfs(grid, i , j, id, n);
                    mp[id] = c;
                    out = max(out, c);
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int c = 1;
                    set<int> st;
                    for (int d = 0; d < 4; ++d) {
                        int x = dx[d] + i;
                        int y = dy[d] + j;
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1)
                            st.insert(grid[x][y]);
                    }
                    for (auto i : st)
                        c += mp[i];
                    out = max(out, c);
                }
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.