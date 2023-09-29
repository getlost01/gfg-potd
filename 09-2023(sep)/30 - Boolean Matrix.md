## 30. Boolean Matrix

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1)

### My Approach

Simple problem just Identify the rows and columns containing at least one `1` and then completely replace all the elements in those rows and columns with `1`.

Here are the steps to do so:

- Create two vectors `r` and `c` to keep track of rows and columns that should be converted to all 1s.
- Iterate through the matrix to find cells with the value `1`.
	- For each cell with the value 1, set the corresponding entry in the `r` and `c` vectors to 1.
- Iterate through the `r` vector and convert rows to all 1s where `r[i]` is 1.
- Iterate through the `c` vector and convert columns to all 1s where `c[j]` is 1.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N*M)`, where `N` is the number of rows and `M` is the number of columns in the matrix.
- **Auxiliary Space Complexity**: `O(N+M)`, where `N` is the number of rows and `M` is the number of columns in the matrix.

### Code (C++)
```cpp
class Solution {
public:
    void booleanMatrix(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> r(n, 0), c(m, 0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j]) {
                    r[i] = true;
                    c[j] = true;
                }

        for (int i = 0; i < n; ++i)
            if (r[i])
                for (int j = 0; j < m; ++j)
                    matrix[i][j] = 1;

        for (int j = 0; j < m; ++j)
            if (c[j])
                for (int i = 0; i < n; ++i)
                    matrix[i][j] = 1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.