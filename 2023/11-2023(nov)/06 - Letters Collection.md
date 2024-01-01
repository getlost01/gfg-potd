## 06. Letters Collection
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/c-letters-collection4552/1)

### My Approach
To solve this problem, I just found the left, right, up, and down boundaries for the given cell and then added the elements present in those boundaries.

To do so I follow these steps
- Initialize an empty vector called `out` to store the results.
- For each query, iterate through the cells in the matrix within a 'hop' distance from the given coordinates `(x, y`).
	- For each cell `(i, j)` within the `hop` distance, check if it is within the boundaries of the matrix `(i.e., i >= 0, i < n, j >= 0, and j < m)`.
	- If the conditions are met, add the values of the matrix cells at `(i, y - hop)` and `(i, y + hop)` to the `sum` if `j` is within bounds. Similarly, add the values of the matrix cells at `(x - hop, j)` and `(x + hop, j)` to the `sum` if i is within bounds.
	- Append the `sum` to the `out` vector for the current query.
Return the `out` vector containing the results for all queries.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(q * (hop^2))` where `q` is the number of queries and 'hop' is the hop distance.
- **Auxiliary Space Complexity**: The auxiliary space is used to store the results in the out vector, which takes `O(q)` space.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[]) {
        vector<int> out;
        
        for(int k = 0; k < q; ++k){
            int sum = 0;
            int hop = queries[k][0];
            int x = queries[k][1];
            int y = queries[k][2];
            
            for(int i = x - hop; i <= x + hop; ++i){
                if(i >= 0 && i < n){
                    if(y - hop >= 0)
                        sum += mat[i][y - hop];
                    if(y + hop < m)
                        sum += mat[i][y + hop];
                }
            }
                
            for(int i = y - hop + 1; i < y + hop; ++i){
                if(i >= 0 && i < m){
                    if(x - hop >= 0)
                        sum += mat[x - hop][i];
                    if(x + hop < n)
                        sum += mat[x + hop][i];
                }
            }
                
            out.push_back(sum);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.