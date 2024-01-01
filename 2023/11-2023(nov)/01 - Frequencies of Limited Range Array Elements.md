## 01. Frequencies of Limited Range Array Elements
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

We can make it simpler by using the modulo operation and performing some mathematical operations on the array. Here's how it works:

- Main objective is to modify an array to count the frequencies of elements.
- I increment values at the indices corresponding to the elements in the original array.
- I use an `offset` to distinguish between the modified values and the original values. 
- After processing the array, I restore the original values by dividing them by the `offset`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the size of the array.
- **Auxiliary Space Complexity**: `O(1)`, as I'm modifying the input array in-place.

### Code (C++)
```cpp
class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        int offset = P + 1;

        for (auto i : arr) {
            int val = (i - 1) % offset;
            if (val < N) {
                arr[val] += offset;
            }
        }
        
        for (int i = 0; i < N; ++i) {
            arr[i] /= offset;
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.