## 08. Print Matrix in Snake Pattern
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

To print a given matrix in a snake pattern, 
- I use a toggle variable to switch the direction of traversal (left to right or right to left) for each row. 
- I iterate through the matrix row by row, adding the elements to the `out` vector in the specified order based on the toggle value. After processing a row, I toggle the direction for the next row.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N*N)`, where `N` is the number of rows (assuming the matrix is square).
- **Auxiliary Space Complexity**: `O(N*N)`, as we use the `out` vector to store the result.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> snakePattern(vector<vector<int>> matrix) {
        bool toggle = false;
        vector<int> out;
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            if (toggle) {
                for (int j = n - 1; j >= 0; --j) {
                    out.push_back(matrix[i][j]);
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    out.push_back(matrix[i][j]);
                }
            }
            toggle = !toggle;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.