# GFG Problem Of The Day

## Today - 1 July 2023
### Que - Number of 1 Bits

[Question Link](https://practice.geeksforgeeks.org/problems/set-bits0143/1)


### My approaches
Since this question is relatively simple and can be solved in multiple ways, I would like to present two commonly used approaches.

#### Approach 1:
The first approach involves iterating through the bits of the binary representation of the number and counting the set bits. Here how it works:

   - We repeatedly `right-shift` the number by `1 bit` and add the `rightmost` bit to the counter variable `cnt` if it is `1` counter increased . If the bit is `0`, the counter remains unchanged.
   
**Example:**
   ```cpp
   if [n = 18 (10010)]
   - 10010     , cnt = 0
   - 1001      , cnt = 1
   - 100       , cnt = 1
   - 10        , cnt = 1
   - 1         , cnt = 2
   ```

- **Time complexity:** `O(log(n))`, as we iterate through all the bits of `n`, which totals to `log(n`).
- **Space complexity:** `O(1)`

#### Code (C++):
```cpp
class Solution {
  public:
    int setBits(int n) {
        int cnt = 0;
        while(n){
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
};
```

#### Approach 2:
The second approach utilizes the standard library function `__builtin_popcount(n)` in C++ to count the number of set bits. This approach involves a concise one-liner code using the built-in function.

#### Code (C++):
```cpp
class Solution {
  public:
    int setBits(int n) {
        return __builtin_popcount(n);
    }
};
```

- **Time complexity:** `O(k)`, where k is the number of bits.
- **Space complexity:** `O(1)`

---

### Contribution

I always encourage contributors to participate in the discussion forum for this repository. If you have a better solution or any queries related to the `Problem of the Day` solution, please feel free to join the discussion. By sharing your insights and ideas, we can collectively enhance our coding knowledge and problem-solving skills.

To access the discussion section and engage in conversations, please [click here](https://github.com/getlost01/gfg-potd/discussions). I look forward to hearing from you and bring up  a collaborative learning environment.

---

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

---

#### Visitors
![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)