## 29. Check whether K-th bit is set or not
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To check whether the K-th bit is set in an integer `n`, I use a bit manipulation technique. 
- I create a mask with the K-th bit set to 1 by left-shifting 1 by K positions.
- Then, I perform a bitwise AND operation between `n` and the mask. If the result is greater than 0, it means the K-th bit is set; otherwise, it's not set.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(1)` - The time complexity is constant because the number of operations is not dependent on the size of the input.
- **Auxiliary Space Complexity**: `O(1)` - The auxiliary space complexity is constant because we use a fixed amount of memory for the mask and the result.

### Code (C++)
```cpp
class Solution {
public:
    bool checkKthBit(int n, int k) {
        int mask = 1 << k; 
        return (n & mask) > 0;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.