## 10. Number of paths in a matrix with k coins

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1)

### My Approach

1. Initialization:
- Define movement directions: dr[]={1, 0} and dc[]={0, 1}.
- Use lambda function valid to check matrix boundaries.

2. Dynamic Programming Setup:
- Initialize a 3D DP array dp of size n x n x k+1 with -1.

3. Recursive Helper Function:
- Define helper(r, c, sum) to calculate ways.
- Base Case:
  - If at bottom right, return 1 if sum equals coins, else return 0.
- If DP array has a value, return it.
- Initialize dp[r][c][sum] to 0.
- If coins at current cell <= sum:
  - Iterate over directions, add ways from valid neighbors with reduced sum.

4. Main Function:
- Call helper(0, 0, k).

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(N^3 * K)` due to the 3D DP array and the recursion.
  
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N^3 * K)` due to the 3D DP array.

### Code (C++)
```cpp
class Solution {
public:
    long long numberOfPath(int n, int k, vector<vector<int>> arr)
    {
        int dr[]={1, 0};
        int dc[]={0, 1};
        auto valid=[&](int x, int y)->bool
        {
            if(x<0 || x>=n || y<0 || y>=n)
                return 0;
            return 1;
        };
        vector<vector<vector<long long>>>dp(n, vector<vector<long long>>(n, vector<long long>(k+1, -1)));
        function<long long(int, int, int)>helper=[&](int r, int c, int sum)->long long
        {
            if(r==n-1 and c==n-1)
                return dp[r][c][sum]=sum==arr[r][c];
            if(dp[r][c][sum]!=-1)
                return dp[r][c][sum];
            dp[r][c][sum]=0;
            if(arr[r][c]<=sum)
            {
                for(int dir=0;dir<2;dir++)
                {
                    int nr=r+dr[dir];
                    int nc=c+dc[dir];
                    if(valid(nr, nc))
                        dp[r][c][sum]+=helper(nr, nc, sum-arr[r][c]);
                }            
            }
            return dp[r][c][sum];
        };
        return helper(0, 0, k);
    }
    
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
