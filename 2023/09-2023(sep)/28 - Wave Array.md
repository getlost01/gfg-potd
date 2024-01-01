## 28. Wave Array

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1)

### My Approach
To convert the given array into a wave array, we can iterate through the array and swap adjacent elements in pairs. This will ensure that every even-indexed element is greater than its adjacent odd-indexed element.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where `n` is the number of elements in the array. We iterate through the array once to perform the swaps.
- **Auxiliary Space Complexity**: `O(1)`, as we use a constant amount of extra space for swapping elements.

### Code (C++)
```cpp
class Solution {
public:
    void convertToWave(int n, vector<int>& arr) {
        for (int i = 0; i < n - 1; i += 2) {
            swap(arr[i], arr[i + 1]);
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.