## 31. Move all zeroes to the end of the array
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

To move all zeroes to the end of the array, I use a two-pointer approach. 
- I maintain two pointers, `i` and `j`. 
- Pointer `i` is used to iterate through the array and move non-zero elements to the front of the array. 
- Pointer `j` keeps track of the position where we should place the next non-zero element. 
- Once we have moved all non-zero elements to the front, I fill the remaining positions with zeroes.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where `n` is the number of elements in the array.
- **Auxiliary Space Complexity**: `O(1)`, as we are not using any extra data structures.

### Code (C++)
```cpp
class Solution {
public:
    void pushZerosToEnd(int arr[], int n) {
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j]) {
                arr[i++] = arr[j];
            }
        }

        for (; i < n; ++i) {
            arr[i] = 0;
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.