## 28. Bleak Numbers
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/bleak-numbers1552/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

To determine if a number is bleak, follow these steps:
- Iterate from 1 to the logarithm base 2 of the given number.
	- For each iteration, find the value `x` for the `i`th set bit by subtracting `i` from the given number.
	- Count the set bits in `x` and check if the sum of set bits and the result is equal to the original number `n`.
	- If such a combination exists, return 0 (indicating it is not bleak).
- If no such combination is found, return 1 (indicating it is bleak).

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(log2(n))` where 'n' is the input number. We iterate through numbers from `1` to `log2(n)`.
- **Auxiliary Space Complexity**: `O(1)`, as we use only a few variables for calculations.

### Code (C++)
```cpp
class Solution {
public:
    int is_bleak(int n) {
        for(int i = 1; i <= log2(n); ++i) {
            int x = n - i;
            int setBits = __builtin_popcount(x);
            if(setBits + x == n)
                return 0;
        }
        return 1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.