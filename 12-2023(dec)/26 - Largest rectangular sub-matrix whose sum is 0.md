## 26. Largest rectangular sub-matrix whose sum is 0
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach

This problem, is now updated by GFG, we can solve this problem using prefix sum.
Here are the steps.

1. **Prefix Sum Matrix Construction:**
   - A prefix sum matrix `pre` is constructed from the given matrix `a`.
   - This matrix is built by iterating through the original matrix and updating each element with the sum of the elements above and to the left.

2. **Iterative Submatrix Search:**
   - The code then iterates through each element of the matrix, considering it as the `top-left` corner of a potential submatrix.
   - For each potential submatrix, it efficiently computes the sum using the prefix sum matrix.
   - Nested loops are used to explore all possible submatrices starting from the current element.
   - Submatrices are considered by varying both the bottom-right corner (`x` and `y` variables) and the top-left corner (`i` and `j` variables).

3. **Checking for Sum Zero:**
   - If the sum of the submatrix is zero, it checks whether the area of the current submatrix is greater than the maximum found so far (`area` variable).

4. **Updating Maximum Submatrix:**
   - If a submatrix with a sum of zero and a larger area is found, it updates the maximum submatrix coordinates (`nax` struct).
   - In case of a tie in area, the code implements tie-breaking conditions:
     - It prefers the submatrix with a smaller starting column (`nax.y1`).
     - If the starting columns are the same, it prefers the submatrix with a larger width (`nax.x2 - nax.x1`).

5. **Result Construction:**
   - After iterating through all possible submatrices, it constructs the result matrix based on the coordinates of the maximum submatrix.

6. **Handling No Solution Case:**
   - If no submatrix with a sum of zero is found, an empty matrix is returned.

### Time and Auxiliary Space Complexity

- **Time Complexity:** `(O(n^4))` - The nested loops result in a time complexity of `(O(n^2))`, and for each sub-matrix, we calculate the sum in `(O(n^2))` time.
- **Auxiliary Space Complexity:** `(O(n^2))` - Additional space is required for the prefix sum matrix.

### Code (C++)

```cpp
class Solution {
public:
    struct cood {
        int x1, y1, x2, y2;
    };

    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> pre = a;

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < m; ++j)
                pre[i][j] += pre[i - 1][j];

        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j)
                pre[i][j] += pre[i][j - 1];

        cood nax = { -1, -1, -1, -1 };
        int area = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = 0;
                if (i > 0 && j > 0)
                    sum += pre[i - 1][j - 1];

                for (int y = m - 1; y >= j; --y) {
                    for (int x = n - 1; x >= i; --x) {
                        if (area <= (x - i + 1) * (y - j + 1)) {
                            int s = sum + pre[x][y];
                            if (i > 0)
                                s -= pre[i - 1][y];
                            if (j > 0)
                                s -= pre[x][j - 1];

                            if (s == 0) {
                                if (area != (x - i + 1) * (y - j + 1)) {
                                    area = (x - i + 1) * (y - j + 1);
                                    nax = { i, j, x, y };
                                }
                                else {
                                    if (nax.y1 > j) {
                                        area = (x - i + 1) * (y - j + 1);
                                        nax = { i, j, x, y };
                                    }
                                    else if (nax.y1 == j) {
                                        if (nax.x2 - nax.x1 < x - i) {
                                            area = (x - i + 1) * (y - j + 1);
                                            nax = { i, j, x, y };
                                        }
                                    }
                                }
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }

        vector<vector<int>> out;
        if (area == 0)
            return out;

        for (int i = nax.x1; i <= nax.x2; ++i) {
            vector<int> arr;
            for (int j = nax.y1; j <= nax.y2; ++j) {
                arr.push_back(a[i][j]);
            }
            out.push_back(arr);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.