## 18. Ticket Counter

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/ticket-counter-2731/1)

### My Approach

To solve the given problem, which involves calculating the left and right boundaries of a given number `N` after performing a maximum of `OP` equal operations, I have used the following approach:

- Calculate the number of operations (`op`) by dividing `N` by `k`.
- Determine the left boundary (`left`) by multiplying `op/2` with `k`. This represents the leftmost value after performing an even number of operations.
- Determine the right boundary (`right`) by subtracting `(op/2)*k` from `N` and adding 1. This represents the rightmost value after performing an even number of operations.
- Check if the difference between the right and left boundaries is greater than `k`. If it is, return the leftmost value from the right boundary, which is `left + k + 1`.
- If the difference is not greater than `k`, return the rightmost value from the left boundary, unless the difference is 1, in which case subtract 1 from the right boundary.

### Time and Auxiliary Space Complexity

The time and auxiliary space complexity of this approach is `O(1)` since it only involves simple calculations and comparisons.

### Code (C++)

```cpp
class Solution {
public:
    int distributeTicket(int n, int k) {
        int op = n / k;
        int left = (op / 2) * k;
        int right = n - (op / 2) * k + 1;
        
        if (right - left > (k + 1))
            return left + k + 1;
        
        return right - (right - left != 1);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.