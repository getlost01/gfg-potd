## 21. Surround the 1's

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/surround-the-1s2505/1)

### My Approach

This is a simple brute force approach, where it iterates through each cell, and check its surrounding eight cells, and increments a counter if the count of zeros in the surroundings is divisible by 2. Steps for implementing this solution.

- Initialize arrays `dx` and `dy` to represent the possible directions: (-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), and (1, 1).
- Define a function `isValid` to check if a given position is within the boundaries of the matrix.
- Iterate through each cell in the matrix.
   - If the cell value is 1, calculate the count `c` of adjacent 0's.
   - If `c` is non-zero and even, increment the `cnt` variable.
- Return the `cnt` variable as the result.

### Explanation with Example

Consider the following matrix:
```
5 5
0 1 0 0 0
0 1 1 0 1
0 0 1 1 0
0 0 0 0 0
```
- Cell (0, 1) has three neighboring 0's.
- Cell (1, 1) has five neighboring 0's.
- Cell (1, 2) has four neighboring 0's.
- Cell (1, 4) has four neighboring 0's.
- Cell (2, 2) has five neighboring 0's.
- Cell (2, 3) has five neighboring 0.

Since the counts are even for (1, 2), and (1, 4) we increment `cnt` by 2.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The code iterates through each cell once and checks its neighboring cells, resulting in `O(n * m)`, where `n` is the number of rows and `m` is the number of columns in the matrix.
- **Auxiliary Space Complexity**: The code uses a constant amount of extra space for the `dx` and `dy` arrays, as well as a few integer variables. Hence, the auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution {
public:
    int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    bool isValid(int &ii, int jj, int &n, int &m) {
        return ii < n && ii >= 0 && jj < m && jj >= 0;
    }

    int Count(vector<vector<int>>& mat) {
        int cnt = 0;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j]) {
                    int c = 0;
                    for (int k = 0; k < 8; ++k) {
                        int ii = dx[k] + i;
                        int jj = dy[k] + j;
                        if (isValid(ii, jj, n, m) && mat[ii][jj] == 0)
                            ++c;
                    }
                    if (c && c % 2 == 0)
                        ++cnt;
                }
            }
        }

        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.