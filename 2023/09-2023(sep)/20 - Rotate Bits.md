## 20. Rotate Bits

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/rotate-bits4524/1)

### My Approach

To rotate the bits of an integer `n` by `d` positions, I followed these steps:

- Create a mask named `mask_16` to exclusively consider the lower 16 bits of `n`.
- Calculate `d` modulo 16 to address situations where `d` exceeds 16.
- To execute the left rotation, use the expression `(n << d | (n >> (16 - d)))`. 
	- This combination shifts `n` left by `d` bits and appends the rightmost bits, which are rotated from the left side due to `(n >> (16 - d))`. Then, apply the `mask_16` to eliminate any extra bits.
- Similarly, for the right rotation, employ the formula `(n >> d | (n << (16 - d)))` and apply the `mask_16`.
- Finally, return the results as a vector.

### With Example

Let's take an example to illustrate how this works:

- Input: `n = 10`, `d = 3`
- `mask_16` is `65535` (binary: `1111111111111111`).
- `d` modulo 16 is `3`.
- Left rotation: `(n << 3 | n >> (16 - 3))` results in `80` (binary: `01010000`).
- Right rotation: `(n >> 3 | n << (16 - 3))` results in `16385` (binary: `0100000000000001`).
- So, the output is `out = {80, 16385}`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this code is `O(1)` because the number of operations is constant and not dependent on the input size.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` as well. We only use a constant amount of additional space to store the results in the `out` vector.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> rotate(int n, int d) {
        int mask_16 = (1 << 16) - 1;
        d = d % 16;
        
        vector<int> out(2);
        out[0] = (n << d | n >> (16 - d)) & mask_16;
        out[1] = (n >> d | n << (16 - d)) & mask_16;
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.