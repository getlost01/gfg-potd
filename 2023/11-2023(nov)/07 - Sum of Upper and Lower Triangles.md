## 07. Sum of Upper and Lower Triangles
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To calculate the sum of the upper and lower triangles of a given square matrix, 
- I use two nested loops to iterate through each element of the matrix. 
	- I maintain two variables `out[0]` and `out[1]` to store the sums of the upper and lower triangles, respectively. 
	- If the current element is in or above the main diagonal (i.e., `i <= j`), I add it to `out[0]`. 
	- If the current element is in or below the main diagonal (i.e., `i >= j`), I add it to `out[1]`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)`, where `n` is the size of the square matrix.
- **Auxiliary Space Complexity**: `O(1)` as we only use a constant amount of space for the `out` vector.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n) {
        vector<int> out(2, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i <= j)
                    out[0] += matrix[i][j];
                if (i >= j)
                    out[1] += matrix[i][j];
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.