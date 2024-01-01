## 30. Is Binary Number Multiple of 3

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-30654/1)

### My approach
- Through observation, it has been determined that odd powers of `2` yield a remainder of `2` when divided by `3`, while even powers yield a remainder of `1`. For instance:

```txt
- 2^0 % 3 = 1
- 2^1 % 3 = 2
- 2^2 % 3 = 1
- 2^3 % 3 = 2
.... so on
```

- For any given binary string, we can determine the final remainder by calculating the sum of remainders corresponding to each `set` bit. For example:

```txt
- 11 (3) ->   2 + 1 = 3
- 110 (6) -> 1 + 2 = 3
- 1111 (15) -> 2 + 1 + 2 + 1 = 6
- 1010100 (84) -> 1 + 1 + 1 = 3
- 10110111 (183) -> 2 + 2 + 1 + 1 + 2 + 1 = 9
```

- Therefore, through the calculation of remainders for every set bit in the provided binary string, we can ascertain the ultimate remainder. Finally, it is crucial to verify whether the `final remainder` is divisible by `3` or not.

### Time and Auxiliary Space Complexity

- **Time Complexity**:  `O(N)`, where `N` is the length of the binary string. We traverse the binary string once to calculate the remainders.
- **Auxiliary Space Complexity**: `O(1)` since we are not using any extra space that scales with the input.

### Code (C++)

```cpp
class Solution {
public:
    int isDivisible(string s) {
        int rem = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (i % 2)
                    rem += 2;
                else
                    rem++;
            }
        }
        
        return rem % 3 == 0;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.