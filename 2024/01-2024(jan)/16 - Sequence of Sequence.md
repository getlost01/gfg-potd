## 16. Sequence of Sequence
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

- Create a 2D vector dp of size (m+1) x (n+1).
- Initialize dp[i][1] to 1 for 1 <= i <= m.
- Use two nested loops for sequence length (j) and current number (i).
- Outer loop: 2 to n, Inner loop: 1 to m.
- Update dp[k][j] by adding dp[i][j-1] for k = 2*i to m.
- Use modulo 1000000007 for all calculations.
- Accumulate results in the last row (dp[i][n]) for 1 <= i <= m.
- Return the sum as the final result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(m*n^2)`, due to the three nested loops

- **Auxiliary Space Complexity**: `O(m*n)`, due to the the dynamic programming table

### Code (C++)

```cpp
class Solution{
public:
    int numberSequence(int m, int n)
    {
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for (int i=1;i<=m;i++)
            dp[i][1]=1;
        for (int j=2;j<=n;j++)
        {
            for (int i=1;i<=m;i++)
            {
                for (int k=i*2;k<=m;k++)
                {
                    dp[k][j]=(dp[k][j]+dp[i][j-1])%1000000007;
                }
            }
        }
        int result=0;
        for (int i=1;i<=m;i++)
            result = (result+dp[i][n])%1000000007;
        return result;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
