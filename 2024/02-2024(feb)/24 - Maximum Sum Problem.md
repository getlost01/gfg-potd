## 24. Maximum Sum Problem

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1)

### My Approach
For this problem, I used dynamic programming to iteratively calculate the maximum sum for each number up to n. 
- Initialize a vector dp with size n+1, initialized with zeros.
- Loop through numbers from 1 to n.
	- For each number i, determine dp[i] as the larger value between the sum of dp[i/2], dp[i/3], and dp[i/4], and i itself.
	- This process helps us in getting whether breaking i into i/2, i/3, and i/4 yields the maximum sum at each iteration.
- Return dp[n] as the maximum sum.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where n is the input number.
- **Auxiliary Space Complexity**: `O(n)`, as we use a vector of size n+1 to store the dynamic programming values.

### Code (C++)
```cpp
class Solution {
public:
    int maxSum(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i/2] + dp[i/3] + dp[i/4];
            dp[i] = max(dp[i], i);
        }
        return dp[n];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.