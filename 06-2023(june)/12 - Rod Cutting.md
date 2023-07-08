## 12. Rod Cutting

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/rod-cutting0840/1)

### My Intuition

By intuition, this problem can be solved using dynamic programming (DP) techniques. The basic idea is to find the maximum possible value obtainable by cutting a rod of length `n` into smaller pieces and selling them according to their respective lengths. For a detailed understanding, you can refer to [this tutorial](https://iq.opengenus.org/rod-cutting-problem/).

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)` because we use nested loops to calculate the values of `dp[i]` for each length from 1 to n.
- **Auxiliary Space Complexity**: `O(n)` because we use an additional array `dp` of size `n+1` to store the optimal values.

### Code (C++)

```cpp
class Solution{
  public:
    int cutRod(int price[], int n) {
       	int dp[n][n+1];
    	for(int i=0;i<=n;++i)
    		dp[0][i] = i*price[0];
    	
    	for(int i = 1; i<n;++i){
    		for(int rs = 0; rs<=n;++rs){
    			int ntake = dp[i-1][rs];
    			int take = 0;
    			if(rs>=i+1)
    				take = dp[i][rs - i - 1] + price[i];
    			
    			dp[i][rs] = max(take,ntake);
    		}
    	}
    
    	return dp[n-1][n];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.