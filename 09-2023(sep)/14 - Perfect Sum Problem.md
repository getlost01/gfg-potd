## 14. Perfect Sum Problem

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1)

### My Approach

I have solved the Perfect Sum Problem using recursion with memoization. Here's how my approach works:

- We define a recursive function `solve` that takes in the current index `i`, the remaining sum `sum`, and a memoization table `dp`. This function calculates the number of ways to obtain the given `sum` using elements from the array `arr` starting from index `i`.
-  **Base case:** 
	- If `sum` becomes 0, we have found a valid combination, so we return 1 to count it.
	- If we have reached the end of the array `arr` (i >= n), or if `sum` becomes negative, we return `0` as there are no more elements to consider or the sum cannot be achieved.
	- We check if the result for the current state (i, sum) is already calculated and stored in the `dp` array. If so, we return the cached result to avoid redundant calculations.
- We initialize two variables `t` and `nt` to count the number of ways by taking and not-taking the current element `arr[i]`, respectively.
- If the current element `arr[i]` is less than or equal to `sum`, we can include it in the sum. So, we recursively call the `solve` function for the next index `i + 1` and the reduced sum `sum - arr[i]`, and add this count to `t`.
- We also recursively call the `solve` function for the next index `i + 1` and the same sum `sum`, and add this count to `nt`.
- Finally, we update the `dp` array with the total count for the current state (i, sum) as `(t + nt) % mod`, where `mod` is a constant defined as 1e9 + 7. We return this count.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(n * sum)`, where `n` is the number of elements in the `arr` array, and `sum` is the target sum. This is because we have a recursive function with two parameters, and we memoize the results, so each state is calculated only once.

- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(n * sum)` as well, due to the memoization table `dp`, which stores the results for all possible combinations of indices and sums.

### Code (C++)
```cpp
class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int arr[], int n, int i, int sum, vector<vector<int>>& dp) {
        if (sum == 0)
            return 1;

        if (i >= n)
            return 0;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        long long t = 0;
        long long nt = solve(arr, n, i + 1, sum, dp);

        if (sum >= arr[i])
            t = solve(arr, n, i + 1, sum - arr[i], dp);

        return dp[i][sum] = (t + nt) % mod;
    }

    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        sort(arr, arr + n);
        int out = solve(arr, n, 0, sum, dp);
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.