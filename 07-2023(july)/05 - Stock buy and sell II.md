## 05. Stock buy and sell II

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1)


### My Approach

Our first intuition for this problem is to use a **greedy** approach. However, we soon realize that there are many cases where the greedy approach fails. Therefore, we need to consider all possibilities to solve this problem using **DP**.

To begin solving this, I have to derive a recurrence relation for this problem.

**Note:** In the following explanation, `i`represents the current index, and `canBuy` indicates the current situation where you can either `buy` or have already bought shares (which means you need to `sell` it).

-   Let's assume that at any index of the array, you have the choice to either **buy** or **sell** shares. We need to consider the possibilities:

    1. First, we **don't involve the share trading** at the current index and move forward with the **same** buying/selling condition.
    2. If you **can buy** shares, then you buy the share (decreasing the sum by the price of the share) and set `canBuy` to `0`, indicating that you now want to sell the shares.
    3. If you **can sell** shares (means `canBuy = 0`), then you add the sum to the price of the share (indicating that you sell the share and store the profit/loss in the sum), and now set `canBuy` to `1`, meaning that you are now able to buy shares again.

- At each recursive step, you need to return the maximum value obtained from either the first condition (**don't involve in trading**), the second condition (**buy share**), or the combination of the first condition(**don't involve in trading**) and third condition (**sell shares**).


By considering these possibilities, we can effectively solve the problem.

Here is the code with the recurrence relation, but this time it result in a Time Limit Exceeded **(TLE)** due to large number of recursion involvement.

### Recurrence recursive code (c++) (Gives TLE)
```cpp

class Solution {
public:
    int check(int i, int n, vector<int>& prices, int sum, int canBuy) {
        if (i == n) // Base case
            return sum;

        int out = check(i + 1, n, prices, sum, canBuy);

        if (canBuy) { 
            out = max(out, check(i + 1, n, prices, sum - prices[i], 0)); // For Buying
        } else {
            out = max(out, check(i + 1, n, prices, sum + prices[i], 1)); // For Selling 
        }

        return out;
    }

    int stockBuyAndSell(int n, vector<int>& prices) {
        return check(0, n, prices, 0, 1);
    }
};

```
### Optimized approach
To optimize this recursive code, we can use the Tabulation method of Dynamic Programming (DP) instead of the **top-down** recursive approach. By utilizing the **bottom-up** Tabulation approach, we can improve the efficiency of the solution. It's important to note that the **recurrence relation remains the same for both approaches**.

### Time and Auxiliary Space Complexity

- **Time Complexity** :  `O(n)` since we are traversing only n * 2 times
- **Auxiliary Space Complexity** : `O(n*2)` auxiliary space complexity for 2-d DP array

### Code (C++) (Tabulation)
```cpp

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int dp[n][2];
        
        dp[n][1] = dp[n][0] = 0; // Base Case
        
        for(int i = n-1; i>=0; --i){
            for(int canBuy = 0; canBuy<2;++canBuy){
                dp[i][canBuy] = dp[i+1][canBuy];
                if(canBuy)
                    dp[i][canBuy] = max(dp[i+1][0] - prices[i], dp[i][canBuy]); // For buying
                else
                    dp[i][canBuy] = max(dp[i+1][1] + prices[i], dp[i][canBuy]); // For selling
            }
        }
        
        return dp[0][1];
    }
};

```


### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
