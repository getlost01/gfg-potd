## 11. Find kth element of spiral matrix

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1)

### My Approach

To find the **kth** element of the spiral matrix, I used a **spiral traversal approach**.

The algorithm maintains four variables that represent the boundaries of the matrix: `istart` (starting row index), `iend` (ending row index), `jstart` (starting column index), and `jend` (ending column index). The following steps are performed:

- Initialize `kth` (count of extracted elements) to 0 and set the initial boundaries (`istart`, `iend`, `jstart`, `jend`).
- While the boundaries have not been exhausted, repeat the following steps:
   - Traverse the top boundary row from `jstart` to `jend` and increment `kth`.
   - Increment `istart` to move to the next row.
   - Traverse the right boundary column from `istart` to `iend` and increment `kth`.
   - Decrement `jend` to move to the previous column.
   - Traverse the bottom boundary row from `jend` to `jstart` in reverse order and increment `kth`.
   - Decrement `iend` to move to the previous row.
   - Traverse the left boundary column from `iend` to `istart` in reverse order and increment `kth`.
   - Increment `jstart` to move to the next column.
- If `kth` is equal to `k`in any step during treversing, return the corresponding element from the matrix.

To gain a clearer concept of this spiral matrix algorithm, it is advisable to refer to the following image:

![Concept-of-Spiral-Matrix](https://github.com/getlost01/gfg-potd/assets/79409258/43a66011-5f7e-4360-9853-3b0d588985ac)

Please note that this image was not created by me; its ownership belongs to its respective owner.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n*m)`, where `n` and `m` are the dimensions of the matrix. We need to traverse all the elements of the matrix in the worst case.
- **Auxiliary Space Complexity**: `O(1)` as we are using a constant amount of extra space to store variables.

### Code (C++)

```cpp
class Solution {
public:
    int findK(int a[MAX][MAX], int n, int m, int k) {
        
        int kth = 0;
        int istart = 0, iend = n - 1, jstart = 0, jend = m - 1;
        
        while (istart <= iend && jstart <= jend) {
            for (int j = jstart; j <= jend; ++j) {
                ++kth;
                if (k == kth) return a[istart][j];
            }
            ++istart;
            
            for (int i = istart; i <= iend; ++i) {
                ++kth;
                if (k == kth) return a[i][jend];
            }
            --jend;
            
            for (int j = jend; j >= jstart; --j) {
                ++kth;
                if (k == kth) return a[iend][j];
            }
            --iend;
            
            for (int i = iend; i >= istart; --i) {
                ++kth;
                if (k == kth) return a[i][jstart];
            }
            ++jstart;
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.