# GFG Problem Of The Day

## Today - 30 June 2023
### Que - Is Binary Number Multiple of 3

[Question Link](https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-30654/1)


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

---

### Code (c++) 
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

---

### Contribution

I always encourage contributors to participate in the discussion forum for this repository. If you have a better solution or any queries related to the `Problem of the Day` solution, please feel free to join the discussion. By sharing your insights and ideas, we can collectively enhance our coding knowledge and problem-solving skills.

To access the discussion section and engage in conversations, please [click here](https://github.com/getlost01/gfg-potd/discussions). I look forward to hearing from you and bring up  a collaborative learning environment.

---

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

---

#### Visitors
![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)