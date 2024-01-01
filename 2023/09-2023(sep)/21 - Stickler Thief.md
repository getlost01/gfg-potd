## 21. Stickler Thief

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1)

### My Approach
I will use dynamic programming to solve this problem. I will maintain a dynamic programming array `dp`, where `dp[i]` represents the maximum sum of stolen items up to the `i`-th item. 

By intuition, we have to skip the `i-1` element to add with the current `i`th number. To address this, we checked previous maximum possibilities from either `i-2` or `i-3` and added them to our current number.

- Initialize a vector `dp` of size `n` with all elements set to 0.
- Iterate through the items in the array:
  - If `i` is greater than or equal to 2, add `dp[i-2]` to `dp[i]`. This represents the maximum sum excluding the previous item.
  - If `i` is greater than or equal to 3, compare `dp[i]` with `dp[i-3]`. If `dp[i-3]` is larger, update `dp[i]` with this value. This ensures that we don't select adjacent items.
  - Add the value of the current item `arr[i]` to `dp[i]`.
  - Update the `out` variable with the maximum of `out` and `dp[i]`. This keeps track of the overall maximum sum.
- Finally, return `out`, which contains the maximum sum of stolen items.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm iterates through the input array once, so the time complexity is `O(n)`, where `n` is the number of items in the array.
- **Auxiliary Space Complexity**: We use an additional vector `dp` of size n to store the dynamic programming values, so the auxiliary space complexity is `O(n)`.

### Code (C++)
```cpp
class Solution {
public:
    int FindMaxSum(int arr[], int n) {
        vector<int> dp(n, 0);
        int out = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i >= 2)
                dp[i] = dp[i - 2];
            if (i >= 3)
                dp[i] = max(dp[i], dp[i - 3]);

            dp[i] += arr[i];
            out = max(out, dp[i]);
        }
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.