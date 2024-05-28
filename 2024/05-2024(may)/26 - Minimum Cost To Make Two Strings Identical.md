## 26. Minimum Cost To Make Two Strings Identical
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1)

### My Approach
- Longest Common Subsequence (LCS) :
  - Compute the length of the longest common subsequence (LCS) of the two strings x and y.
  - Use a 2D DP table dp of size (n+1)x(m+1) where n is the length of x and m is the length of y.
  - Initialize dp[i][0] and dp[0][j] to 0 for all valid i and j because the LCS of any string with an empty string is 0.
  - Fill the dp table :
    - If characters match (x[i-1] == y[j-1]), set dp[i][j] = dp[i-1][j-1] + 1.
    - If characters do not match, set dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
  - The value at dp[n][m] gives the length of the LCS.
- Calculate Minimum Cost :
  - Subtract the length of the LCS from the lengths of x and y to find the number of characters to delete from each string to make them identical.
  - The total cost is the sum of the deletion costs for these characters.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N*M)`
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N*M)`.

### Code (C++)

```cpp
class Solution {
  public:
    int lcs(string x, string y)
    {
        int n=x.length(), m=y.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(x[i-1]==y[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

    int findMinCost(string x, string y, int costX, int costY)
    {
        int length=lcs(x,y);
        return costX*((x.length()-length))+(costY*(y.length()-length));
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
