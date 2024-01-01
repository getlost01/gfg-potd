## 25. Unique Rows in Boolean Matrix

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1)

### My Approach

To find the unique rows in a boolean matrix, I have used the following approach:

- Initialize a boolean vector `vis` of size `row` to keep track of visited rows. Initially, all elements are set to `false`.
- Initialize an empty vector of vectors `out` to store the unique rows.
- Iterate over each row of the matrix.
  - If the current row is already marked as visited (`vis[i] = true`), skip to the next row.
  - Mark the current row as visited (`vis[i] = true`).
  - Create a vector `binArr` of size `col` to store the current unique row.
  - Convert the row from the matrix into a vector and store it in `binArr`.
  - Push `binArr` into the `out` vector to store the unique row.
  - Iterate over the remaining rows starting from `i + 1` to check for duplicate rows.
    - Compare each element of the current row (`M[i][k]`) with the corresponding element of the other row (`M[j][k]`).
    - If any element is different, mark the other row as visited (`vis[j] = true`).
- Return the `out` vector containing the unique rows.

### Time and Auxiliary Space Complexity

- **Time Complexity**:  `O(row * col * col)`, where `row` is the number of rows and `col` is the number of columns in the matrix. We compare each row with every other row, which requires checking each element of the rows.
- **Auxiliary Space Complexity**: `O(row * col)` since we are using additional space to store the unique rows in the output vector.

### Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
        vector<bool> vis(row, false);
        vector<vector<int>> out;
        
        for (int i = 0; i < row; ++i) {
            if (vis[i])
                continue;
            
            vis[i] = true;
            vector<int> binArr(col);
            
            for (int j = 0; j < col; ++j)
                binArr[j] = M[i][j];
                
            out.push_back(binArr);
            
            for (int j = i + 1; j < row; ++j) {
                bool isEqual = true;
                
                for (int k = 0; k < col; ++k) {
                    if (M[i][k] != M[j][k]) {
                        isEqual = false;
                        break;
                    }
                }
                
                vis[j] = isEqual | vis[j];
            }
        }
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.