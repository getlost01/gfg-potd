## 26. Minimum Operations
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
In this problem, we just need to count the '0' and '1' bits in the given number 'n'. We add one for each '1' bit and perform multiple operations for all the bits.

To find the minimum operations for a given number `n`, I perform the following steps:
1. Initialize a variable `out` to -1.
2. While `n` is not zero:
   - If `n` is odd (i.e., `n % 2` is 1), increment `out`.
   - Divide `n` by 2.
   - Always increment `out`.
3. Return the value of `out`.

This approach efficiently counts the minimum operations required to reach 1 from `n` by either subtracting 1 or dividing by 2.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(log n)` - The while loop iterates until `n` becomes 0, which typically takes log base 2 of `n` steps.
- **Auxiliary Space Complexity**: `O(1)` - The algorithm uses a constant amount of extra space.

### Code (C++)
```cpp
class Solution {
public:
    int minOperation(int n) {
        int out = -1;
        while (n) {
            if (n % 2)
                ++out;
            n /= 2;
            ++out;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.