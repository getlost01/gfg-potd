## 02. Largest Sum Subarray of Size at least K
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
I solve the problem using a sliding window approach.
- Initialize a vector `pre` of length `n` to store the prefix sum of the input array.
- Calculate the prefix sum and store it in the `pre` vector.
- Initialize sum with the sum of the first `k` elements and ans with the same value.
- Iterate from `k to n`, and in each iteration:
  - Calculate the sum of the subarray ending at index i.
  - Update sum with the maximum of the current sum and the sum of the previous k elements plus the current element.
  - Update ans with the maximum of the current sum and the previous ans.
- Return the final value of ans as the result.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(n)`, where n is the size of the input vector.
- **Auxiliary Space Complexity** : `O(n)`, where n is the size of the pre vector.

### Code (C++)
```cpp
class Solution {
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long int> pre(n, 0);
        pre[0] = a[0];

        for (int i = 1; i < n; ++i)
            pre[i] = pre[i - 1] + a[i];

        long long int sum = pre[k - 1];
        long long int ans = sum;

        for (int i = k; i < n; i++) 
        {
            long long int cur = pre[i] - pre[i - k];
            sum = max(cur, sum + a[i]);
            ans = max(ans, sum);
        }

        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
