## 29. Sum of bit differences
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1)

### My Approach

The approach for calculating the sum of bit differences involves iterating through each bit position (from 0 to 31 for 32-bit integers). For each bit position, count the number of elements in the array that have that bit set (1) and the number of elements that have that bit unset (0). Then, multiply the counts of 1s and 0s for that bit position and multiply it by 2, since each pair of set and unset bits contributes 2 to the sum of bit differences. Finally, accumulate these contributions for all bit positions to get the total sum of bit differences.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(32 * n)`, where n is the number of elements in the array.
- **Auxiliary Space Complexity**: The space complexity of this approach is `O(1)`, as we are using only a constant amount of extra space for storing intermediate variables.

### Code (C++)
```cpp
class Solution {
public:
    long long sumBitDifferences(int arr[], int n) {
        long long out = 0;
        for(int i=0; i<32; ++i){
            long long one = 0;
            for(int j = 0; j < n; ++j)
                if((arr[j]&(1<<i))!=0)
                    ++one;
            long long zero = n - one;
            out += 2*one*zero;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.