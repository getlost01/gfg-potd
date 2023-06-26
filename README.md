# GFG Problem Of The Day

## Today - 26 June 2023
### Que - nCr

[Question Link](https://practice.geeksforgeeks.org/problems/ncr1019/1)

---

### My approach
- The simple formula for calculating combinations is `C(n, r) = n! / (r! * (n - r)!)`, which represents the number of ways to choose `r` items from a set of `n` items.
- To optimize the calculation, we determine the maximum value between `(n - r)` and `r` and eliminate common factors from the numerator and denominator, in code `b` represents `max(n-r, r)` & `a` represents `min(n-r, r)`.
- After eliminating common factors, the formula becomes `(n * (n - 1) * (n - 2) * ... * (b + 1)) / (a!)`.
- Modulo multiplies these `(n * (n - 1) * (n - 2) * ... * (b + 1))` to obtain the numerator of the combination formula.
- To obtain the final answer, we calculate the modular inverses of `(a * (a - 1) * ... * 1)` and multiply them together using the modulo operation.

---

### Code (c++) 
```cpp
class Solution {
public:
    int MOD = 1e9+7;

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

        // Now we have simplify calculate (n * (n-1) * (n-2) * ... * b+1) / (a!)
        int ans = 1;
        for (int i = n; i > b; --i) 
            ans = modMultiply(ans, i);

        // Calculate modular inverse for (a!) and multiply it with the answer
        for (int i = 2; i <= a; ++i) 
            ans = modMultiply(ans, modInverse(i));

        return ans;
    }
};
```

---

### Contribution

I always encourage contributors to participate in the discussion forum for this repository. If you have a better solution or any queries related to the `Problem of the Day` solution, please feel free to join the discussion. By sharing your insights and ideas, we can collectively enhance our coding knowledge and problem-solving skills.

To access the discussion section and engage in conversations, please [click here](https://github.com/getlost01/gfg-potd/discussions). I look forward to hearing from you and bring up  a collaborative learning environment.

---

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

---

#### Visitors
![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)