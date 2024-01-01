## 15. Partition Equal Subset Sum

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1)

### My Approach

For solving the "Subset Sum Problem," which is a classic dynamic programming problem. We have to determine if it's possible to partition an array into two subsets such that the sum of elements in both subsets is equal.

- I start by calculating the total sum of all elements in the input array. If the sum is `odd`, it's impossible to partition the array into two subsets with equal sums, so I return `false` immediately.

- I create a 2D DP array `dp`, where `dp[i][target]` represents whether it's possible to achieve a sum of `target` using the first `i` elements of the array.

- I use a recursive function `canPart` to fill the DP array. For each element in the array, I have two options:
   - Take the element into the subset by subtracting its value from the target sum.
   - Skip the element and move to the next one.
   - I recursively explore both options, and if I find a path that leads to the target sum, I set `dp[i][target]` to true.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(N * target)`, where `N` is the number of elements in the input array, and target is the target sum we are trying to achieve. 
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N * target)` as well because of the DP array.

### Code (C++)

```cpp
class Solution {
public:
    bool canPart(int& N, int i, int arr[], int target, vector<vector<int>>& dp){
        if(target == 0)
            return true;
        
        if(i >= N)
            return false;
           
        if(target >= arr[i]){
            bool take = canPart(N,i+1,arr,target - arr[i], dp);
            if(take)
                return dp[i][target] = true;
        }
        
        bool notTake = canPart(N,i+1,arr,target, dp);
        return dp[i][target] = notTake;
    }
    
    bool equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i<N;++i){
            sum += arr[i];
        }
        if(sum % 2 != 0) // If the sum is odd, it's impossible to partition into equal subsets.
            return false;
            
        int target = sum/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return canPart(N,0,arr,target, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.