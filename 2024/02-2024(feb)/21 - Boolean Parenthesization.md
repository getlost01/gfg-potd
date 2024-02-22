## 21. Boolean Parenthesization
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1)

### My Approach
- Initialize a 3D array dp with dimensions n x n x 2 to store subproblem solutions.
- Set the modulo value as 1003.
- If i == j, set dp[i][j][1] to 1 if s[i] == 'T' and dp[i][j][0] to 1 if s[i] == 'F'.
- Otherwise, initialize both dp[i][j][1] and dp[i][j][0] to 0.
- Iterate over subproblems in a bottom-up manner from smaller subexpressions to the entire expression.
- Use nested loops with indices i and j to represent the subexpression boundaries and k to iterate over possible operators between symbols.
- Update values based on the operator:
- If s[k+1] == '&', update dp[i][j][1] and dp[i][j][0] accordingly.
- If s[k+1] == '|', update dp[i][j][1] and dp[i][j][0] accordingly.
- If s[k+1] == '^', update dp[i][j][1] and dp[i][j][0] accordingly.
- The final result is stored in dp[0][n-1][1], representing the number of ways the expression can be parenthesized to evaluate to true.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N^3)`
- **Auxiliary Space Complexity**: `O(N^2)`

### Code (C++)
```cpp
class Solution{
public:
    int countWays(int n, string s)
    {
        int dp[n][n][2];
        const int mod=1003;
        for(int i=n-1;i>-1;i-=2)
        {
            for(int j=i;j<n;j+=2)
            {
                if(i==j)
                {
                    dp[i][j][1]=s[i]=='T';
                    dp[i][j][0]=s[i]=='F';
                }
                else
                {
                    dp[i][j][1]=dp[i][j][0]=0;
                    for(int k=i;k<j;k+=2)
                    {
                        int f1=dp[i][k][1], f0=dp[i][k][0], s1=dp[k+2][j][1], s0=dp[k+2][j][0];
                        if(s[k+1]=='&')
                        {
                            dp[i][j][1]=(dp[i][j][1]+(f1*s1)%mod)%mod;
                            dp[i][j][0]=(dp[i][j][0]+(f1*s0)%mod+(f0*s1)%mod+(f0*s0)%mod)%mod; 
                        }
                        else if(s[k+1]=='|')
                        {
                            dp[i][j][1]=(dp[i][j][1]+(f1*s0)%mod+(f0*s1)%mod+(f1*s1)%mod)%mod; 
                            dp[i][j][0]=(dp[i][j][0]+(f0*s0)%mod)%mod;
                        }
                        else
                        {
                            dp[i][j][1]=(dp[i][j][1]+(f1*s0)%mod+(f0*s1)%mod)%mod;
                            dp[i][j][0]=(dp[i][j][0]+(f1*s1)%mod+(f0*s0)%mod)%mod;
                        }
                    }
                }
            }
        }
        return dp[0][n-1][1];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
