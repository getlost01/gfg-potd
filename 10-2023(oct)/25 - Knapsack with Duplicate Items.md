## 25. Knapsack with Duplicate Items
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

- Create a 1D DP array of size (W + 1) to store the maximum values for different weights.
- Initialize the DP array with zeros.
- Iterate through each item and for each item, iterate through each weight from its weight (wt[i]) to the maximum weight (W).
- Update the DP array by taking the maximum of the current value in the DP array at weight j and the value of the current item plus the value in the DP array at weight (j - wt[i]).
- The final value in the DP array at weight W will represent the maximum profit that can be obtained.
- Return the maximum profit as the result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N*W)`, where `N` represents the number of items, and `W` represents the weight limit of the knapsack
- **Auxiliary Space Complexity**: `O(W)`, where `W` represents the weight limit of the knapsack

### Code (C++)
```cpp
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1, 0);
        for (int i=0; i<N; i++)
        {
            for (int j=wt[i]; j<=W; j++)
            {
                dp[j] = max(dp[j], dp[j-wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
