## 1. Boundary Traversal of Matrix

The problem of boundary traversal of a matrix can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1)

### Approach

To perform the boundary traversal of a matrix, I followed these steps:

- Initialize an empty vector `out` to store the boundary elements.
- Initialize variables `i` and `j` to track the current position in the matrix, both starting at 0.
- Traverse the top row from left to right, incrementing `j` while adding elements to `out`.
- Increment `i` and decrement `j` to position at the last column if there is more than one row.
- If there are more than one rows and more than one columns, traverse the rightmost column from top to bottom while decrementing `i` and adding elements to `out`.
- If there are more than one rows, return to the first column by incrementing `j` and traverse the bottom row from bottom to top while decrementing `i` and adding elements to `out`.
- Return the `out` vector as the result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(N + M)`, where `N` is the number of rows in the matrix and `M` is the number of columns in the matrix. We visit each element of the matrix once.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N+M)` because we only use a single vector to store the result.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> boundaryTraversal(vector<vector<int>>& matrix, int n, int m) {
        vector<int> out;
        int i = 0, j = 0;
        for(; j < m; ++j) out.push_back(matrix[i][j]);
        ++i; --j;
		
        if(n > 1) {
            for(; i < n; ++i) out.push_back(matrix[i][j]);
            --i; --j;
			
            if(m > 1) {
                for(; j >= 0; --j) out.push_back(matrix[i][j]);
                --i; ++j;
				
                for(; i > 0; --i) out.push_back(matrix[i][j]);
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.