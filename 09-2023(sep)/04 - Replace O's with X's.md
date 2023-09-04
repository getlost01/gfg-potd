## 04. Replace O's with X's

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1)

### My Approach

I've used a DFS approach to point out the regions of 'O' characters that were not completely 'X' surrounded. 
- To identify these regions, I have checked all the grid borders. If I encounter any 'O' character along the border, it indicates that the connected 'O' characters within this region is not entirely enclosed by 'X'. So, I label such 'O' characters as 'N'. 
- At last, I identify the 'O' characters that are entirely surrounded, and I replace them with 'X' and change 'N' to 'O' back.

The steps involved in implementing this: 

- I've defined two arrays, `dx` and `dy`, representing the four possible directions: up, down, left, and right.
- Two helper functions are at play:
   - `isValid` assesses whether a given cell resides within the matrix's boundaries.
   - `isBoundary` evaluates whether a given cell lies on the matrix's perimeter.
- I've implemented a recursive function, `setNotClosed`, which marks all connected 'O' characters as 'N' if they aren't enclosed (i.e., not surrounded by 'X').
- Within the `fill` function, I traverse the entire matrix. Whenever I encounter an 'O' character on the boundary, I invoke `setNotClosed` to label all connected 'O' characters as 'N.'
- Lastly, I iterate through the entire matrix once more. I replaced 'O' with 'X' and 'N' with 'O' to complete the transformation during this pass.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity is `O(n * m)`, where `n` is the number of rows, and m is the number of columns for traversing all cells of grid.
- **Auxiliary Space Complexity**: The space complexity is `O(1)` as we don't use any additional data structures that depend on the input size.

### Code (C++)
```cpp
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValid(int ii, int jj, int& n, int& m) {
        return (ii >= 0 && jj >= 0 && ii < n && jj < m); 
    }

    bool isBoundary(int i, int j, int &n, int &m) {
        return (i == 0 || j == 0 || i == n - 1 || j == m - 1);
    }

    void setNotClosed(int i, int j, int& n, int& m, vector<vector<char>>& mat) {
        mat[i][j] = 'N';

        for (int d = 0; d < 4; ++d) {
            int ii = dx[d] + i;
            int jj = dy[d] + j;
            if (isValid(ii, jj, n, m) && mat[ii][jj] == 'O')
                setNotClosed(ii, jj, n, m, mat);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isBoundary(i, j, n, m) && mat[i][j] == 'O')
                    setNotClosed(i, j, n, m, mat);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
                else if (mat[i][j] == 'N')
                    mat[i][j] = 'O';
            }
        }

        return mat;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.