## 16. Sequence of Sequence
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
Due to the smaller constraints, we can only use a recursive approach. This problem falls into the category of either `take` or `not take`.
- Base Case: If `m < n`, return 0, as there cannot be a sequence of length `n` in a string of length less than `n`.
- Base Case: If `n == 0`, return 1, as there is always one way to have an empty sequence.
- Recursively calculate the number of sequences for two cases:
    - Take `t`: Decreasing the sequence length by 1 and dividing the length of the string by 2.
    - Not Take `nt`: Keeping the sequence length the same and decreasing the string length by 1.
- Return the sum of `t` and `nt`.

### Time and Auxiliary Space Complexity
- **Time Complexity**: Exponential, as the recursive approach leads to repeated calculations.
- **Auxiliary Space Complexity**: O(n), where n is the depth of the recursion stack.

### Code (C++)
```cpp
class Solution {
public:
    int solve(int n, int m) {
        if (m < n)
            return 0;
        if (n == 0)
            return 1;

        int t = solve(n - 1, m / 2);
        int nt = solve(n, m - 1);

        return t + nt;
    }

    int numberSequence(int m, int n) {
        return solve(n, m);
    }
};
```

### Contribution and Support
For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.