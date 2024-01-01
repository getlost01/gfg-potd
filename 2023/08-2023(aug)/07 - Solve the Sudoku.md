## 07. Solve the Sudoku

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1)

### My Approach

To solve the Sudoku puzzle, I have implemented a backtracking algorithm. I define a function `isValid` that checks whether it's valid to place a number `num` at the given cell `(i, j)` on the Sudoku grid. This function checks the row, column, and the 3x3 subgrid containing the cell.

Then, I implement the `SolveSudoku` function using a recursive backtracking approach. I iterate through each cell of the grid, and if the cell is empty (filled with `0`), I try placing numbers from `1` to `9` and validate if the placement is valid using the `isValid` function. If valid, I proceed to the next cell and repeat the process. If a valid solution is found, the function returns `true`, otherwise, I backtrack and try a different number.

Lastly, I have a `printGrid` function to print the solved Sudoku grid.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The backtracking algorithm explores all possible configurations of the Sudoku grid, so in the worst case, the time complexity is exponential, approximately `O(9^(N*N))`, where `N` is the size of the grid (typically 9 for standard Sudoku).

- **Auxiliary Space Complexity**: In the worst case, it can go up to `O(N*N)`, where N is the size of the grid. The additional space used for the `isValid` function and temporary variables is relatively small and can be considered constant.

### Code (C++)

```cpp
class Solution {
public:
    bool isValid(int &num, int &i, int &j, int grid[N][N]) {
        for (int ii = 0; ii < 9; ii++) {
            if (grid[ii][j] == num) {
                return false;
            }
            if (grid[i][ii] == num) {
                return false;
            }
            if (grid[3 * (i / 3) + ii / 3][3 * (j / 3) + ii % 3] == num) {
                return false;
            }
        }
        return true;
    }

    bool SolveSudoku(int grid[N][N]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    for (int num = 1; num <= 9; ++num) {
                        if (isValid(num, i, j, grid)) {
                            grid[i][j] = num;
                            if (SolveSudoku(grid)) {
                                return true;
                            }
                            grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void printGrid(int grid[N][N]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) 
                cout << grid[i][j] << " ";
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.