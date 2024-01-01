## 16. Nth Catalan Number

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1)

### What are the Catalan numbers

The Catalan numbers form a sequence characterized by the following recurrence relationship:

```js
C0 = 1
C1 = 1
C2 = C0 * C1 + C1 * C0
C3 = C0 * C2 + C1 * C1 + C2 * C0
...
...
Ci = C0 * Ci-1 + C1 * Ci-2 + C2 * Ci-3 + ... + Ci-2 * C1 + Ci-1 * C0
```

In this series, each term (C_i) is calculated by combining the previous terms (C_i-1, C_i-2, ...) using multiplicative relationships.

### My Approach

To calculate the nth Catalan number, I used dynamic programming. 
- I iteratively computed the Catalan numbers up to `n` using a bottom-up approach. 
- For each `i from 2 to n`, I calculated `c[i]` by summing up the products of `c[j]` and `c[i - 1 - j]` for all valid j values. 
- The result is stored in `c[n]`, which represents the nth Catalan number.

### Explanation with Example

For instance, let's take n = 4:

```js
- C0 = 1
- C1 = 1
- C2 = C0xC1 + C1xC0 = 1*1 + 1*1 = 2
- C3 = C0xC2 + C1xC1 + C2xC0 = 1*2 + 1*1 + 2*1 = 5
- C4 = C0xC3 + C1xC2 + C2xC1 + C3xC0 = 1*5 + 1*2 + 2*1 + 5*1 = 14
```

So, the 4th Catalan number is 14.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(n^2)`, where n is the given input.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(n)`, as I used an array `c` of size `n+1` to store intermediate results.

### Code (C++)

```cpp
class Solution {
public:
    int MOD = 1e9 + 7;
    int findCatalan(int n) 
    {
        long long c[n + 1] = {0};
        c[0] = c[1] = 1;
		
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                c[i] = (c[i] + (c[j] * c[i - 1 - j])) % MOD;
            }
        }

        return (int)c[n];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.