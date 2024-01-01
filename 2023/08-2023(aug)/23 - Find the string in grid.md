## 23. Find the string in grid

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1)

### My Approach

I have used a straightforward approach to solve this problem. 
- Start iterating through each cell in the `grid`. 
	- For each cell, I check if the first character of the word matches the character in the current cell. 
	- If it does, I explore in all eight possible directions `(up, down, left, right, and diagonally)` to see if the entire word can be formed. 
		- To do this, I use the `canForm` function that checks if the word can be formed starting from the current cell in a given direction. 
		- If I find a match, I add the starting cell's coordinates to the `out` vector.
	- I continue this process until I have searched the entire grid.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The code iterates through each cell in the grid exactly once, and for each cell, it explores eight possible directions to check if the word can be formed. So, the time complexity is `O(N * M * 8 * W)`, where `N` is the number of rows in the grid, `M` is the number of columns, and `W` is the length of the target word.

- **Auxiliary Space Complexity**: The auxiliary space used is minimal. The `out` vector stores the starting positions of the target word, which can be at most the size of the grid, so the space complexity is `O(N * M)`.

### Code (C++)
```cpp
class Solution {
public:
    int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    bool canForm(vector<vector<char>>& grid, string& word, int i, int j, int dir) {
        int ii = i, jj = j;
        for (int k = 1; k < word.size(); ++k) {
            ii = dx[dir] + ii;
            jj = dy[dir] + jj;
            if (ii < 0 || jj < 0 || ii >= grid.size() || jj >= grid[0].size() || grid[ii][jj] != word[k]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> searchWord(vector<vector<char>>& grid, string word) {
        vector<vector<int>> out;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == word[0]) {
                    for (int dir = 0; dir < 8; ++dir) {
                        if (canForm(grid, word, i, j, dir)) {
                            out.push_back({ i, j });
                            break;
                        }
                    }
                }
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.