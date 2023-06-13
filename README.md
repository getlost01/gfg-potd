# GFG Problem Of The Day

## Today - 12 June 2023
### Que - Rod Cutting

[Question Link](https://practice.geeksforgeeks.org/problems/rod-cutting0840/1)


### My intutuion
By intuition it is a dp problem. For better understanding visit [this tutorial](https://iq.opengenus.org/rod-cutting-problem/).


### Code (c++)
```
class Solution{
  public:
    int cutRod(int price[], int n) {
        int dp[n+1];
        dp[0] = 0;
        for(int i = 1;i<=n;++i){
            dp[i] = -1;
            for(int j = 0;j<i;++j){
                dp[i] = max(dp[i], price[j] + dp[i-j-1]);
            }
        }
        return dp[n];
    }
};
```