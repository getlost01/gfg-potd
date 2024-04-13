## 13. Reverse Bits

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reverse-bits3556/1)

### My Approach

For this problem, I'm using a straightforward approach. I iterate through each bit of the given number `x`. In each iteration, I extract the least significant bit of `x` using the bitwise AND operator (`x & 1`). I add this bit to the result variable `out`. Then, I left shift `out` by one bit to make space for the next bit. Finally, I right shift `x` by one bit to move to the next bit position. I repeat this process for 31 iterations, as we are considering the 32-bit representation of `x` (assuming a 32-bit integer).

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(1) - Since the number of iterations (31) is fixed and independent of the input size.
- **Auxiliary Space Complexity**: O(1) - No extra space is used; the space complexity remains constant.

### Code (C++)

```cpp
class Solution {
  public:
    long long reversedBits(long long x) {
        long long out = 0;
        for(int i = 0; i < 31; ++i)
            out += x & 1,
            out <<= 1,
            x >>= 1;
            
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.