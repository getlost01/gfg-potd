## 14. Largest subsquare surrounded by X
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1)

### My Approach
To solve this problem, I create two additional matrices, col and row, to store the count of consecutive 'X's in the columns and rows respectively.
- Then, I iterate over each cell of the matrix to find the largest subsquare surrounded by 'X' characters.
- For each cell, we calculate the minimum of the counts of consecutive 'X's in its corresponding column and row. This gives us the size of the largest subsquare with the current cell as its bottom-right corner.
- We then iterate over decreasing sizes of subsquares starting from this minimum size and check if all the cells in the subsquare are surrounded by 'X' characters. If they are, we update the maximum size found so far.
- Finally, we return the maximum size of the subsquare found.

### Time and Auxiliary Space Complexity
- **Time Complexity**: O(n^2) where n is the size of the input matrix.
- **Auxiliary Space Complexity**: O(n^2) for the auxiliary matrices `col` and `row`.

### Code (C++)

```cpp
class Solution {
public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> col(n,vector<int>(n,0));
        vector<vector<int>> row(n,vector<int>(n,0));
        
        for(int i=0;i<n;++i){
            int sum=0;
            for(int j=n-1;j>=0;--j){
                sum = (a[i][j] == 'O')? 0 : sum + 1;
                col[i][j]=sum;
            }
        }
        
        for(int j=0;j<n;++j){
            int sum=0;
            for(int i=n-1;i>=0;--i){
               sum = (a[i][j] == 'O')? 0 : sum + 1;
               row[i][j]=sum;
            }
        }
        
        int out=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int sq = min(col[i][j],row[i][j]);
                while(sq > out)
                {
                    if((col[i+sq-1][j])>=sq && (row[i][j+sq-1])>=sq)
                        out=sq;
                    
                    --sq;
                }
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.