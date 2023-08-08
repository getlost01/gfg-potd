## 08. Fraction pairs with sum 1

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/fraction-pairs-with-sum-1/1)

### My Approach

To solve this problem, we can follow these steps:

- Create a map to store simplified rational numbers, where the key is a `pair` representing the numerator and denominator, and the value is the count of occurrences.
- For each input fraction `(num[i], den[i])`, calculate the greatest common divisor (GCD) of `num[i]` and `den[i]` using `__gcd()` function, and then insert the simplified fraction into the map after dividing numerator and denominator by gcd.
- Iterate through the map, and for each entry `(nume, deno) -> cnt`:
   - If `cnt` is not zero, calculate the new numerator `newNume = deno - nume` we find this required numerator in our map since by adding this numerator we can easily make your pair sum = 1.
	   - If `nume` is equal to `newNume`, add `(cnt * (cnt - 1)) / 2` to the final result to count pairs that sum up to 1.
	   - Otherwise, if `(newNume, deno)` exists in the map, add `cnt * mp[{newNume, deno}]` to the result and set `mp[{newNume, deno}]` to zero.

### Time and Auxiliary Space Complexity

- **Time Complexity** : If `n` is the number of fractions, the insertion and iteration take `O(n log n)` time due to the map operations.
- **Auxiliary Space Complexity** : `O(n)` due to the space required for the map to store simplified fractions.

### Code (C++)

```cpp
class Solution {
public:
    int countFractions(int n, int num[], int den[]) {
        map<pair<int, int>, int> mp;

        for (int i = 0; i < n; ++i) {
            int gcd = __gcd(num[i], den[i]);
            ++mp[{num[i] / gcd, den[i] / gcd}];
        }

        int out = 0;

        for (auto i : mp) {
            int nume = i.first.first;
            int deno = i.first.second;
            int cnt = i.second;

            if (cnt) {
                int newNume = deno - nume;
                if (nume == newNume) {
                    out += (cnt * (cnt - 1)) / 2;
                } else if (mp.find({newNume, deno}) != mp.end()) {
                    out += cnt * mp[{newNume, deno}];
                    mp[{newNume, deno}] = 0;
                }
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.