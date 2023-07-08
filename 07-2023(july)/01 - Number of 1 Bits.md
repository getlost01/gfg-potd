## 01. Number of 1 Bits

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/set-bits0143/1)

### My approaches
Since this question is relatively simple and can be solved in multiple ways, I would like to present two commonly used approaches.

### Approach 1:
The first approach involves iterating through the bits of the binary representation of the number and counting the set bits. Here how it works:

   - We repeatedly `right-shift` the number by `1 bit` and add the `rightmost` bit to the counter variable `cnt` if it is `1` counter increased . If the bit is `0`, the counter remains unchanged.

#### Example
```cpp
   if [n = 18 (10010)]
   - 10010     , cnt = 0
   - 1001      , cnt = 1
   - 100       , cnt = 1
   - 10        , cnt = 1
   - 1         , cnt = 2
 ```

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(log(n))`, as we iterate through all the bits of `n`, which totals to `log(n`).
- **Auxiliary Space Complexity** : `constant` as it does not depend on variables


### Code (C++) 
```cpp

class Solution {
public:
    int setSetBit(int x, int y, int l, int r) {
        int maskLen = r - l + 1;
        int mask = (1 << maskLen) - 1;
        mask = mask << (l - 1);
        y = y & mask;
        return (x | y);  
    }
};

```
### Approach 2:
The second approach utilizes the standard library function `__builtin_popcount(n)` in C++ to count the number of set bits. This approach involves a concise one-liner code using the built-in function.

### Code (C++):
```cpp
class Solution {
  public:
    int setBits(int n) {
        return __builtin_popcount(n);
    }
};
```

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(k)`, where k is the number of bits.
- **Auxiliary Space Complexity** : `constant` as it does not depend on variables

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
