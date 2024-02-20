## 20. Word Break
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/word-break1352/1)

### My Approach

- Create an unordered_set dict from the vector B for efficient word lookup.
- Create a dynamic programming array dp of size n + 1, where n is the length of string A.
- Initialize dp[0] to true since an empty string is always considered segmented.
- Iterate over each character in string A from 1 to n.
- For each index i, iterate over the substring from 0 to i-1 (denoted by index j).
- Check if the substring A[j:i] is present in the dictionary (dict) and if dp[j] is also true.
- If both conditions are met, set dp[i] to true, indicating that the substring A[0:i-1] can be segmented.
- If dp[n] is true, return 1, indicating that the entire string can be segmented, otherwise, return 0.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(len(A)^2)` due to the nested loops iterating over substrings.
- **Auxiliary Space Complexity**: `O(len(A))` for the dynamic programming array dp and `O(len(B))` for the unordered_set dict.

### Code (C++)

```cpp
class Solution
{
public:
    int wordBreak(string A, vector<string> &B)
    {
        unordered_set<string>dict(B.begin(), B.end());
        int n=A.length();
        vector<bool>dp(n+1, false);
        dp[0]=true;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (dp[j] && dict.find(A.substr(j, i-j))!=dict.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        if (dp[n])
            return 1;
        else return 0;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
