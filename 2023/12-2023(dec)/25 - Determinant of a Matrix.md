## 25. Determinant of a Matrix
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1)

![](https://badgen.net/badge/Level/So Call Easy/green)

### My Approach

To calculate the determinant of a matrix, I have implemented the following steps:

1. If the matrix is 1x1, return the only element (`mat[0][0]`)
2. If the matrix is 2x2, return the determinant using the standard formula (`mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]`)
3. For larger matrices, use a recursive approach:
   - Create a submatrix for each element in the first row.
   - Recursively calculate the determinant of each submatrix.
   - Sum the products of each element in the first row, its corresponding submatrix determinant, and a `sign` factor.
   - The sign factor alternates between 1 and -1.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n!)`, factorial time complexity due to recursive calls
- **Auxiliary Space Complexity**: `O(n^2)`, space for the submatrix

### Code (C++)

```cpp
class Solution {
public:
    int determinantOfMatrix(vector<vector<int>> mat, int n) {
        if (n == 1) {
            return mat[0][0];
        }
        if (n == 2) {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        }

        int sign = 1, ans = 0;
        vector<vector<int>> m(n - 1, vector<int>(n - 1));

        for (int row = 0; row < n; ++row) {
            int k = 0;
            for (int i = 0; i < n; ++i) {
                if (i != row) {
                    for (int j = 1; j < n; ++j)
                        m[k][j - 1] = mat[i][j];

                    k++;
                }
            }
            ans += sign * (mat[row][0]) * determinantOfMatrix(m, n - 1);
            sign *= -1;
        }
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
```

Please replace the placeholders like `step 1: explanation` with your actual explanation of the approach.