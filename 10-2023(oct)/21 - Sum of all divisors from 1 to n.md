## 21. Sum of all divisors from 1 to n
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
By obsevation, you will notice that each number appears a total of (N/i) times.

To find the sum of all divisors from 1 to N, 
- I iterate through numbers from 1 to N and add up the contributions from each number by `((N/i)*i)`

### Explain with example
Let's take N = 6 as an example.

- For i = 1, it is a divisor of 1, 2, 3, 4, 5, and 6, so it contributes 1 + 1 + 1 + 1 + 1 + 1 = 6 to the sum.
- For i = 2, it is a divisor of 2, 4, and 6, so it contributes 2 + 2 + 2 = 6 to the sum.
- For i = 3, it is a divisor of 3 and 6, so it contributes 3 + 3 = 6 to the sum.
- For i = 4, it is a divisor of 4, so it contributes 4 to the sum.
- For i = 5, it is a divisor of 5, so it contributes 5 to the sum.
- For i = 6, it is a divisor of 6, so it contributes 6 to the sum.

Adding all these contributions gives the final sum, which is 6 + 6 + 6 + 4 + 5 + 6 = 33, which is the sum of divisors from 1 to 6.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)` - We iterate through numbers from 1 to N.
- **Auxiliary Space Complexity**: `O(1)` - We use a constant amount of extra space.

### Code (C++)
```cpp
class Solution {
public:
    long long sumOfDivisors(int N) {
        long long out = 0;
        for (int i = 1; i <= N; ++i) {
            out += (N / i) * i;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.