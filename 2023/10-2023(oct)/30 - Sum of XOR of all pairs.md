## 30. Sum of XOR of all pairs
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

For solving this question, I applied a property of XOR. When we XOR two set bits, the result is zero; however, if one bit is set and the other is unset, the resultant bit is set. Therefore, to solve this question, we consider all possible combinations of set and unset bits to transform them into a set bit.

To find the XOR sum of all pairs in an array, I use a bitwise method:
- I iterate through bit positions from 0 to 31 (as in int have 32-bit only). Count 1s and 0s at each position across all elements in the array. For each bit position,
	- Then I calculate the XOR contribution, which is `the count of ones times the count of zeros in that position`, multiplied by the bit value `(2^i)`. 
	- This is done for all 32 bit positions, and the results are summed to obtain the final answer.

### Explain with an example
Let's consider an example to explain the approach. Suppose we have the array [3, 6, 8, 4].

- For the 0th bit (rightmost bit):
    - Count of ones = 1 (0011)
    - Count of zeros = 3 (0110, 1000, 0100)
    - XOR contribution = 1 * 3 * 2^0 = 3

- For the 1st bit:
    - Count of ones = 2 (0011, 0110)
    - Count of zeros = 2 (1000, 0100)
    - XOR contribution = 2 * 2 * 2^1 = 8

- For the 2nd bit:
    - Count of ones = 2 (0110, 0100)
    - Count of zeros = 2 (0011, 1000)
    - XOR contribution = 2 * 2 * 2^2 = 16

- For the 3rd bit (leftmost bit):
    - Count of ones = 1 (1000)
    - Count of zeros = 3 (0011, 0110, 0100)
    - XOR contribution = 1 * 3 * 2^3 = 24

Summing all the XOR contributions: 3 + 8 + 16 + 24 = 51

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(32 * n)`, where `n` is the number of elements in the array. This is because we iterate through each bit position for each element in the array.
- **Auxiliary Space Complexity**: `O(1)`, as we use a fixed amount of additional space.

### Code (C++)
```cpp
class Solution {
public:
    long long int sumXOR(int arr[], int n) {
        long long int out = 0;
        for (int i = 0; i < 32; ++i) {
            long long int ones = 0;
            int mask = 1 << i;
            for (int j = 0; j < n; ++j) {
                if ((arr[j] & mask) != 0) {
                    ones++;
                }
            }
            out += (ones * (n - ones) * mask);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.