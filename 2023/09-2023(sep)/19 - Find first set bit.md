## 19. Find first set bit

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1)

### My Approach

### Bruteforce Approach
Simply iterate over all the bits of the number and check if the bit is set or not.If the bit is set, break loop and return the position of the bit.

#### Time and Auxiliary Space Complexity
- **Time Complexity** : `O(log(n))` - The solution has a logarithmic time complexity as it iterates over all the bits of the number.
- **Auxiliary Space Complexity** : `O(1)` - The solution uses a constant amount of additional space for variables, regardless of the input size.

#### Code (C++)
```cpp
class Solution
{
public:
    unsigned int getFirstSetBit(int n)
    {
        int cnt = 0;
        while(n){
            cnt++;
            if(n&1)
                break;
            n >>= 1;
        }
        return cnt;
    }
};
```

### Optimized Approach
To find the position of the first set bit, I'm using bitwise operations.
- I'm using the expression `1 + log2(n & ~ (n - 1))` to calculate the position of the first set bit.

#### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(1)` - The solution has a constant time complexity as it performs a fixed number of operations, regardless of the input size.
- **Auxiliary Space Complexity** : `O(1)` - The solution uses a constant amount of additional space for variables, regardless of the input size.

#### Code (C++)
```cpp
class Solution {
public:
    unsigned int getFirstSetBit(int n) {
        return 1 + log2(n & ~ (n - 1));
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.