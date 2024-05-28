## 23. K-Palindrome
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1)

### My Approach
- Reverse the input string str to get revStr.
- Use dynamic programming to compute the minimum number of deletions required to transform str into revStr.
- Create a 2D array dp of size (n+1)x(n+1) where n is the length of the string.
- Initialize dp[i][0] to i and dp[0][j] to j for all valid i and j.
- Fill the dp array by comparing characters of str and revStr:
  - If characters match, set dp[i][j] = dp[i-1][j-1].
  - If characters don't match, set dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]).
- The value at dp[n][n] gives the minimum number of deletions needed.
- Check if this value is less than or equal to 2*k to determine if the string is a K-palindrome.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N^2)`
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N^2)`.

### Code (C++)

```cpp
class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        string revStr=str;
        reverse(revStr.begin(), revStr.end());
        return (isKPalDP(str, revStr, n, n)<=k*2);
    }

private:
    int isKPalDP(string str1, string str2, int m, int n)
    {
        int dp[m+1][n+1];
        for (int i=0;i<=m;i++)
        {
            for (int j=0;j<=n;j++)
            {
                if (i==0)
                    dp[i][j]=j;
                else if (j==0)
                    dp[i][j]=i;
                else if (str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
