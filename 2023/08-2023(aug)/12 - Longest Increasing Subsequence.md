## 12. Longest Increasing Subsequence

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1)

### My Approach

Usually, the Longest Increasing Subsequence is a common problem solved using the `O(n^2)` dynamic programming approach. However, the twist in this question is the required time complexity of `O(nlogn)`, which adds a level of complexity.

Let's now explore how I approached and solved this challenge.

- I start by creating an empty vector called `dp` which will hold the elements identified in the longest increasing subsequence up to that point.
- Next, I iterate through the input array `a`.
  - If the current element `a[i]` is larger than the last element in `dp`, I add `a[i]` to the end of the `dp` vector.
  - However, if `a[i]` is not larger, I employ the `lower_bound` function to locate the appropriate position for `a[i]` within the `dp` vector, and then replace the element at that position with `a[i]`.
- The length of the longest increasing subsequence is simply the size of the `dp` vector.

**I understand that this method is an unconventional approach to solving dynamic programming problems. However, for a much better explanation, I recommend to Striver's explanation of this solution, which can be accessed by clicking [here](https://www.youtube.com/watch?v=on2hvxBXJH4&t=16s "Click here to view").**

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n*log(n))` due to the binary search operation in `lower_bound`.
- **Auxiliary Space Complexity**: `O(n)` for the `dp` vector.

### Code (C++)

```cpp
class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp;
        
        dp.push_back(a[0]);
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > dp.back())
                dp.push_back(a[i]);
            else
            {
                auto it = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
                dp[it] = a[i];
            }
        }

        return dp.size();
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.