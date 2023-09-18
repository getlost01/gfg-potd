## 18. Power of 2

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1)

### My Approach

To determine if a given number `n` is a power of two, I use the following logic:

- Check if `n` is not zero (`n != 0`).
- Use a bitwise AND operation between `n` and `(n - 1)`. 
	- If the result is zero, then `n` is a power of two because in binary representation, a power of two has only one bit set to 1 (e.g., 2^0 = 1, 2^1 = 2, 2^2 = 4, etc.), and `(n - 1)` will have all lower bits set to 1. The bitwise AND of `n` and `(n - 1)` will be zero in this case.

### With example
Let's consider an example to illustrate this approach:

```
- Input: n = 8
- Binary representation of 8 = (1000)
- Binary representation of (8 - 1) = 7 = (0111)
- Bitwise AND of 8 and 7 = (1000 & 0111), which is (0000).
- Since the result is 0, we can conclude that 8 is a power of two.
```

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(1)`, The algorithm involves only a single bitwise operation, which is a constant-time operation.
- **Auxiliary Space Complexity**: `O(1)`, The algorithm uses a constant amount of additional space for variables, regardless of the input size.

### Code (C++)
```cpp
class Solution {
public:
    bool isPowerofTwo(long long n){
        return n && ((n & (n - 1)) == 0);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.