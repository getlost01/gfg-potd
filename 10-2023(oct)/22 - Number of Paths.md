## 22. Number of Paths
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/number-of-paths0926/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

The problem statement implies that this question is simple DP, but due to the constraints, it requires a highly optimized solution, which is not intuitive. At first, I also did not get the answer. But through internet get help to find a solution.

To solve this problem, I used a combination formula to calculate the number of paths from the top-left corner to the bottom-right corner of an MxN grid. 
- I start iteration through the rows of the grid, and for each row, I calculate the [binomial coefficient](https://cp-algorithms.com/combinatorics/binomial-coefficients.html "binomial coefficient") (n choose k), where n is the sum of the row and column indices, and k is the row index. I used modular arithmetic to handle large numbers.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(M)`, where `M` and `N` are the dimensions of the grid. 
- **Auxiliary Space Complexity**: `O(1)`. We only use a constant amount of extra space.

### Code (C++)
```cpp
class Solution {
public:
    int mod = 1e9 + 7;

    long long modInv(long long a, long long b) {
        return 1 < a ? b - modInv(b % a, a) * b / a : 1;
    }

    long long numberOfPaths(int m, int n) {
        long long out = 1;

        for (int i = 0; i < m - 1; i++) {
            long long inverse = modInv(i + 1, mod);
            out = (out * (i + n)) % mod;
            out = (out * inverse) % mod;
        }

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.