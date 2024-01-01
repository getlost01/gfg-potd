## 25. Knapsack with Duplicate Items
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

Honestly, if you're not familiar with dynamic programming, I strongly recommend checking out Striver's tutorials for learning DP. He's has provided the well explaining solution for this problem. Just [click here ](https://takeuforward.org/data-structure/unbounded-knapsack-dp-23)to take a look at it.

For now, I solve this knapsack problem with duplicate items using dynamic programming. Here's my approach:

- Create a vector `dp` of size `W+1` and initialize all elements to 0. `dp[i]` will store the maximum value that can be obtained with a knapsack of capacity `i`.
- Iterate through each item from `0` to `N-1`, where `N` is the number of items.
- For each item, iterate through the weights from `wt[i]` to `W`, where `W` is the maximum knapsack capacity.
- Update `dp[w]` by taking the maximum of its current value `dp[w]` and the value of the current item plus the value obtained by using the remaining capacity `w - wt[i]`.
- Finally, return `dp[W]`, which will contain the maximum value that can be obtained with the given items and their weights.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N * W)`, where `N` is the number of items and `W` is the maximum knapsack capacity.
- **Auxiliary Space Complexity**: `O(W)`, where `W` is the maximum knapsack capacity.

### Code (C++)
```cpp
class Solution {
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < N; i++) {
            for (int w = wt[i]; w <= W; w++) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.