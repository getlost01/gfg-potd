## 27. Anti Diagonal Traversal of Matrix
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-diagonally1623/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
To traverse the anti-diagonals of the matrix, 
- I used a helper function `fill` that starts at a given position `(i, j)` and moves diagonally down until it reaches the border of the matrix.
- I called this `fill` function for the `top row` and `rightmost column` to cover all the anti-diagonals.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N*N)`, where N is the total number of rows and columns in the matrix. We visit each element exactly once.
- **Auxiliary Space Complexity**: `O(N*N)`, where N is the total number of rows and columns in the matrix. This is the space required to store the output vector.

### Code (C++)
```cpp
class Solution {
public:
    void fill(int i, int j, vector<vector<int>>& mat, vector<int>& out){
        while(i < mat.size() && j >= 0){
            out.push_back(mat[i][j]);
            ++i;
            --j;
        }
    }
    vector<int> antiDiagonalPattern(vector<vector<int>>& mat) 
    {
        vector<int> out;
        int n = mat.size();
        for(int j = 0; j < n; ++j)
            fill(0, j, mat, out);
        
        for(int i = 1; i < n; ++i)
            fill(i, n-1, mat, out);
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.