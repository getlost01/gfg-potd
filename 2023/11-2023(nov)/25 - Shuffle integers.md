## 25. Shuffle integers
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/shuffle-integers2401/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
To shuffle the given array, I use the fact that integers can be represented with additional digits by adding an offset. 
- I iterate through the array, combining pairs of elements into a single integer by adding the remainder of the second element multiplied by a large offset. 
- After shuffling, I extract the original elements by dividing each element by the offset.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where `n` is the size of the array.
- **Auxiliary Space Complexity**: `O(1)`, as the extra space used is constant.

### Code (C++)
```cpp
class Solution {
public:
    void shuffleArray(int arr[], int n) {
        int offset = 1e5;
        for (int i = 0; i < n / 2; ++i) {
            arr[i * 2] += (arr[i] % offset) * offset;
            arr[i * 2 + 1] += (arr[n / 2 + i] % offset) * offset;
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = arr[i] / offset;
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.