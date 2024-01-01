## 22. Make Matrix Beautiful
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1)

### My Approach

The concept involves determining the highest sum of every row and column, and then executing actions on the rows and columns with sums lower than the maximum calculated sum. To do so I follow these steps.

- Calculate the sum of each row and column while traversing the matrix.
- Track the maximum sum of rows and columns.
- Calculate the total sum of all elements in the matrix.
- Return the maximum of (maxRow * n) and (maxCol * n) minus the total sum.

### Explanation with Example
Let's illustrate this approach with an example:
Suppose we have the following 3x3 matrix:
```
1 2 3
4 5 6
7 8 9
```
1. Calculate the sum of each row and column:
   - Row sums: `[6, 15, 24]`
   - Column sums: `[12, 15, 18]`
2. Find the maximum sum among rows and columns, which is `24` (from row sums) so we focus on this sum and try to make all row and column sums equal to 24.
3. Calculate the total sum of all elements, which is `45`.
4. The minimum number of operations =>
(Maximum sum) x (n) - (Total sum) = `(24 x 3 ) - 45` = `72 - 45` = `27` operations are required to make the matrix beautiful.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)` - We iterate through the matrix once to calculate row and column sums.
- **Auxiliary Space Complexity**: `O(1)` - We use a few variables to store sums and results, and not any additional data structures.

### Code (C++)

```cpp
class Solution {
public:
    int findMinOpeartion(vector<vector<int>> a, int n) {
        long long sumRow, sumCol;
        long long maxRow = 0, maxCol = 0, total = 0;

        for (int i = 0; i < n; i++) {
            sumRow = sumCol = 0;

            for (int j = 0; j < n; j++) {
                sumRow += a[i][j];
                sumCol += a[j][i];
                total += a[i][j];
            }

            maxRow = max(maxRow, sumRow);
            maxCol = max(maxCol, sumCol);
        }

        return max(maxRow * n, maxCol * n) - total;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.