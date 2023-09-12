## 05. Chocolate Distribution Problem

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1)

### My Approach

To find the minimum difference between the maximum and minimum chocolates distributed to students, I used a greedy by sorting the given array of chocolates. Then, we take a window of size `m` and slide it over the sorted array. We keep track of the minimum difference encountered during this process.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(n log n)` time, where `n` is the number of elements in the input array `a`.
- **Auxiliary Space Complexity** : `O(1)` as we are using a constant amount of extra space.

### Code (C++)

```cpp
class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        sort(a.begin(), a.end());
        long long minDiff = a[m - 1] - a[0];
        for (int i = 1; i <= n - m; ++i) {
            minDiff = min(minDiff, a[m + i - 1] - a[i]);
        }
        return minDiff;
    }   
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.