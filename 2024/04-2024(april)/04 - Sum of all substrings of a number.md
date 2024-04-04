## 04. Sum of all substrings of a number
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1)

### My Approach
To calculate the sum of all substrings of a number, I iterated through the string from right to left. At each iteration, I updated the sum by adding the contribution of the current digit to all substrings ending at that position. This contribution is calculated by multiplying the digit value by the position of the digit in the string, the number of substrings ending at that position, and a multiplier that depends on the position. Finally, I took the sum modulo the given mod value to prevent integer overflow.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where n is the length of the input string. This complexity arises due to the single pass through the input string.
- **Auxiliary Space Complexity**: `O(1)`. The space complexity is constant as we only use a few variables regardless of the input size.

### Code (C++)
```cpp
class Solution {
public:
    long long sumSubstrings(string s){
        long long sum = 0;
        int mod = 1e9+7;
        int n = s.size();
        long mul = 1; 
        for (int i = n - 1; i >= 0; --i) {
            sum += ((s[i] - '0') * mul * (i + 1)) % mod;
            sum %= mod;
            mul = (mul * 10 + 1) % mod; 
        }
        return sum;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.