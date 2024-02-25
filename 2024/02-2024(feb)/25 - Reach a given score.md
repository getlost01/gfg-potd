## 25. Reach a given score
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1)

### My Approach
In this problem, we are tasked with reaching a given score using three possible moves: adding 3, adding 5, or adding 10 to the current score. 
To solve this, I use dynamic programming. 
- I initialize a vector `dp` of size `n + 1`, where `dp[i]` represents the number of ways to reach the score `i`.
- Then, start with `dp[0] = 1` since there is one way to reach a score of 0 (by not making any move). 
- Iterate through scores from 3 to `n`, adding the ways to reach the current score using three moves: add 3, add 5, and add 10. Use separate loops to prevent duplication caused by iterating in one loop.
- Finally, return `dp[n]`, which represents the number of ways to reach the given score.

### Time and Auxiliary Space Complexity
- **Time Complexity**: O(n), where n is the given score.
- **Auxiliary Space Complexity**: O(n), additional space is used to store the dynamic programming array.

### Code (C++)
```cpp
class Solution {
public:
    long long int count(long long int n)
    {
        vector<long long int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 3; i <= n; i++)
            dp[i] += dp[i - 3];
        for (int i = 5; i <= n; i++)
            dp[i] += dp[i - 5];
        for (int i = 10; i <= n; i++)
            dp[i] += dp[i - 10];

        return dp[n];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.