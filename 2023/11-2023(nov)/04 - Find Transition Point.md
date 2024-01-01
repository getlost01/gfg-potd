## 04. Find Transition Point
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

To find the transition point (the point where `0` changes to `1`) in a sorted array, I employ a binary search approach. I simply locate the lower bound of `1` in the given array, and this is our desired answer.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(log n)`, where `n` is the size of the input array. This is because binary search has a logarithmic time complexity.
- **Auxiliary Space Complexity**: `O(1)`. The algorithm uses a constant amount of extra space for variables, regardless of the size of the input.

### Code (C++)
```cpp
class Solution {
public:
    int transitionPoint(int arr[], int n) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            
            if (arr[m] < 1)
                l = m + 1;
            else
                r = m;
        }
        
        return arr[l] ? l : -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.