# GFG Problem Of The Day

## Today - 2 July 2023
### Que - Copy Set Bits in Range

[Question Link](https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1)


### My approach

This is a simple bit masking question where we need to generate a mask to filter out specific bits from `y` and then perform a bitwise OR operation (`x or y`) to copy the values of `y` into `x`.

To create the mask, follow these steps:
- First, determine the length of the filter mask.
- Create the mask by left-shifting `1` by the mask length.
- Obtain the desired mask by subtracting 1 from the mask and left-shifting it by `l - 1`.
- Once the mask is ready, apply it to filter out the relevant bits from `y`, and perform a bitwise OR operation with `x` to copy the filtered values into `x`.
   
**Example:**
```
Given:
- x = 1090 (10001000010)
- y = 1211 (10010111011)
- l = 2
- r = 6

Steps:

1. Since l = 2 and r = 6 are inclusive in the range, 
   maskLen = 5.

2. Calculate the mask:
   - Initialize mask as 1 shifted left by maskLen: mask = 1 << 5 = 32 (100000)

   - Subtract 1 from mask: mask = mask - 1 = 31 (011111)
     (We obtain a mask with the required length of 5 ones)

   - Shift the mask towards the left boundary by (l - 1): mask = mask << (l - 1) = (0111110)
     (This is our required mask)
 
 3. Filter out y value:
    y' = y & mask = (10010111011) & (0111110) = (0111010)

 4. Copy x or y:
    Result = x | y' = (10001000010) | (0111010) = 1146 (10001111010)
```

#### Code (C++):
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

---

### Contribution

I always encourage contributors to participate in the discussion forum for this repository. If you have a better solution or any queries related to the `Problem of the Day` solution, please feel free to join the discussion. By sharing your insights and ideas, we can collectively enhance our coding knowledge and problem-solving skills.

To access the discussion section and engage in conversations, please [click here](https://github.com/getlost01/gfg-potd/discussions). I look forward to hearing from you and bring up  a collaborative learning environment.

---

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

---

#### Visitors
![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)