## 17. Max Sum without Adjacents

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

To find the maximum sum of elements in an array for this question, I use a dynamic programming approach. The idea is to maintain two variables, `lastPrev` and `prev`, representing the maximum sums excluding and including the last element, respectively. I iterate through the array, updating these variables at each step to consider the current element or skip it.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where n is the size of the array.
- **Auxiliary Space Complexity**: `O(1)`, as I only use a constant amount of extra space.

### Code (C++)

```cpp
class Solution {
public:
    int findMaxSum(int *arr, int n) {
        int lastPrev = 0;
        int prev = arr[0];
        int curr = 0;

        for (int i = 1; i < n; ++i) {
            curr = max(prev, arr[i] + lastPrev);
            lastPrev = prev;
            prev = curr;
        }

        return max(lastPrev, prev);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.