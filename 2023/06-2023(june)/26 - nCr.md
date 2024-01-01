## 26. nCr (Combination)

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/ncr1019/1)

### My Approach

To calculate the combination value (nCr), I have used the following approach:

- The simple formula for calculating combinations is `C(n, r) = n! / (r! * (n - r)!)`, which represents the number of ways to choose `r` items from a set of `n` items.
- To optimize the calculation, we determine the maximum value between `(n - r)` and `r` and eliminate common factors from the numerator and denominator. In the code, `b` represents `max(n-r, r)` and `a` represents `min(n-r, r)`.
- After eliminating common factors, the formula becomes `(n * (n - 1) * (n - 2) * ... * (b + 1)) / (a!)`.
- To avoid overflow and optimize the calculation further, we perform modulo operations during the intermediate steps.
- First, we calculate the modular inverses of `(a * (a - 1) * ... * 1)` using the Extended Euclidean Algorithm and multiply them together using the modulo operation.
- Finally, we multiply the numerator `(n * (n - 1) * (n - 2) * ... * (b + 1))` with the modular inverses and return the result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where n is the value of `n`. We need to calculate the factorials and modular inverses for `(a!)` and perform multiplication operations.
- **Auxiliary Space Complexity**: `O(1)` as we are not using any extra space that scales with the input.

### Code (C++)

```cpp
class Solution {
public:
    int MOD = 1e9 + 7;

    int modInverse(int num) {
        int y = 0, x = 1;
        int mod = MOD;

        while (num > 1) {
            int quo = num / mod;
            int t = mod;

            mod = num % mod;
            num = t;
            t = y;

            y = x - quo * y;
            x = t;
        }

        if (x < 0)
            x += MOD;

        return x;
    }

    int modMultiply(int a, int b) {
        a %= MOD;
        b %= MOD;
        return ((long long)a * b) % MOD;
    }

    int nCr(int n, int r) {
        if (n < r)
            return 0;
        
        // Determine the smaller value between (n-r) and r
        int a = min(n - r, r);
        int b = max(n - r, r);

        // Now we have to simplify and calculate (n * (n-1) * (n-2) * ... * (b+1)) / (a!)
        int ans = 1;
        for (int i = n; i > b; --i) 
            ans = modMultiply(ans, i);

        // Calculate the modular inverse for (a!) and multiply it with the answer
        for (int i = 2; i <= a; ++i) 
            ans = modMultiply(ans, modInverse(i));

        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.