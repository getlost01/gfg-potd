## 23. Maximum sum increasing subsequence
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

To find the maximum sum increasing subsequence, I use dynamic programming. I maintain a `dp` array of the same size as the input array `arr`. `dp[i]` represents the maximum sum of increasing subsequence ending with `arr[i]`. 

To getting your Maximum Here is Bottom Up DP approach.
- I initialize `dp` with the values of `arr`. 
- Then, I iterate through the elements of `arr`. 
	- For each element, I iterate through the previous elements and check if they are smaller than the current element. 
	- If yes, I update `dp[i]` to be the maximum between its current value and `dp[j] + arr[i]`, where `j` is the index of a smaller element. 
- Finally, I find the maximum value in the `dp` array, which represents the maximum sum increasing subsequence.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)`, where `n` is the size of the input array `arr`. This is because we have a nested loop.
- **Auxiliary Space Complexity**: `O(n)` for the `dp` array.

### Code (C++)
```cpp
class Solution {
public:
    int maxSumIS(int arr[], int n) {
        vector<int> dp(arr, arr + n);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        int out = 0;
        for (auto i : dp) {
            out = max(out, i);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.