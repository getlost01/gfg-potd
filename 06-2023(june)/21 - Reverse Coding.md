## 21. Reverse Coding

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/reverse-coding2452/1)

### My Approach

To solve this problem, I have used a simple approach based on the formula for the sum of natural numbers.

- The formula `(n*(n+1))/2` gives the sum of the first `n` natural numbers.
- In the given code, I calculate the sum using this formula and return the result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(1)` since the calculation of the sum of natural numbers can be done in constant time.
- **Auxiliary Space Complexity**: `O(1)` as there is no extra space used that scales with the input.

### Code (C++)

```cpp
class Solution {
public:
    int mod = 1e9 + 7;
    int sumOfNaturals(int n) {
        long long sum = n;
        sum = (sum * (sum + 1)) % mod;
        sum /= 2;
        
        return sum;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.