## 26. Minimum Operations
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

- Create a DP array dp of size n + 1 to store the minimum number of operations to reach each number from 0 to n
- Initialize dp[0] to 0 since it takes 0 operations to reach 0 from 0
- Iterate from 1 to n and for each number i ->
  - Check if i is even, update dp[i] with the minimum between dp[i] and dp[i / 2] + 1 since you can reach i by doubling the previous number
  - Always update dp[i] with the minimum between dp[i] and dp[i - 1] + 1 since you can also reach i by adding 1 to the previous number
- Return dp[n] as the minimum number of operations to reach n

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` refers to the input number
- **Auxiliary Space Complexity**: `O(N)`, where `N` refers to the input number

### Code (C++)
```cpp
class Solution
{
public:
    int minOperation(int n)
    {
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for (int i=1;i<=n;i++)
        {
            if (i%2==0)
            {
                dp[i] = min(dp[i], dp[i/2]+1);
            }
            dp[i] = min(dp[i], dp[i-1]+1);
        }
        return dp[n];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
