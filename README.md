## GFG Problem Of The Day

---

### Year-End Gratitude
🎉 Wishing you a fantastic New Year's Eve! 🎉 

As we say goodbye to 2023, I just want to say a big thank you to all of you who visited my GFG POTD repo in the last `7 months`. Your daily presence has been a constant source of motivation to do consistently POTD. Thanks a ton! 🙏

## Highlights 

Over the past seven months, I've been sharing my daily GFG POTD solutions. It's been great to see some of you share your solutions and even contribute to the repo. With an average of `600` daily views, this journey has been absolutely fantastic! 🌟

<img width="540" src="https://github.com/getlost01/gfg-potd/assets/79409258/4a83e6af-9e3c-498b-8468-92b7a6be3123">

Awesome achievements, right? Your interest fueled my dedication. Massive shoutout to all coders and learners! Your support means a lot.

Excited for `2024` and more coding adventures. Feel free to comment or share ideas.

**Wishing you a `HAPPY NEW YEAR - 2024` in advance. Hope the journey continues! 🚀**

---

### Today - 31 December 2023
### Que - New Year Resolution
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/good-by-2023/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
This problem is an improvised version of the target sum problem, and I approached it using a recursive method with memoization (DP) to explore all possible coin combinations. 
Here are the steps to do so:
- The recursive function `solve` is used, taking parameters such as the current index `i`,`n`, the current sum `sum`, `coins`, and a vector `dp` to store intermediate results.
- The function checks if the current sum is a valid solution (2024 or divisible by 20 or 24), returning true if so.
- Base cases are set: if the index exceeds the number of coins or the sum surpasses 2024, it returns false.
- At each index, two conditions are considered: 'take' or 'not take.' Two recursive calls are made 
	- One for 'not take,' where the index is increased with the same sum.
	- The other is for 'take,' where both the sum and index are incremented. 
	- These recursive calls evaluate all cases, returning true or false. 
- Memoization is used at every step to reduce redundant computations.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n * sum)`, where n is the number of coins and sum is the target sum
- **Auxiliary Space Complexity**: `O(n * sum)` due to the memoization table.

### Code (C++)
```cpp
class Solution {
public:
    bool solve(int i, int& n, int sum, int coins[], vector<unordered_map<int,bool>>& dp){
        if(sum == 2024 || (sum && (sum%20 == 0 || sum%24 == 0)))
            return true;
        
        if(i == n || sum > 2024)
            return false;
        
        if(dp[i].find(sum) != dp[i].end())
            return dp[i][sum];
        
        int nt = solve(i+1, n, sum, coins, dp);
        if(nt)
            return dp[i][sum] = nt;
        
        return dp[i][sum] = solve(i+1, n, sum + coins[i], coins, dp);
    }
    
    int isPossible(int n , int coins[]) 
    {
        vector<unordered_map<int,bool>> dp(n);
        return solve(0,n,0,coins, dp);
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

