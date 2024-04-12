## 12. Sum of Products
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-products5049/1)

### My Approach
To solve this problem, we iterate through each bit position from 0 to 31. 
- For each bit position, we count the number of elements in the array that have that bit set. 
- Then, we calculate the number of pairs that can be formed using those elements, and multiply it by 2 raised to the power of the current bit position. 
- Finally, we sum these values to get the overall sum of products.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n * 32) => O(n)`
- **Auxiliary Space Complexity**: `O(1)`

### Code (C++)
```cpp
class Solution {
public:
    long long pairAndSum(int n, long long arr[]) {
        long long out = 0;
        for (int i = 0; i < 32; ++i) {
            long long cnt = 0;
            for (int j = 0; j < n; ++j)
                if (arr[j] & (1 << i)) 
                    cnt++;
            long long pairs = (cnt * (cnt - 1) / 2);
            out += pairs * (1 << i);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.