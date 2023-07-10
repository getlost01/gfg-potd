## 10. Transpose of Matrix

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1)

### My Approach

The problem of transposing a matrix can be solved by using two index variables, i and j. We can iterate over `i` from `0 to n - 1` and `j` from `i to n - 1` to avoid unnecessary repetition.
- In each iteration, we swap the elements `mat[i][j]` with `mat[j][i]`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)` since a nested loops run for n iterations, where `n` is the size of the matrix.
- **Auxiliary Space Complexity**: `O(1)` since these operations were performed in-place, meaning it does not require any additional space.

### Code (C++)

```cpp

class Solution
{   
    public:
    void transpose(vector<vector<int>>& mat, int n)
    { 
        for(int i = 0; i<n;++i){
            for(int j = i; j<n;++j){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.