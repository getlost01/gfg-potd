## 07. Number of subarrays with maximum values in given range
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
To solve this question and count the number of subarrays, I maintaining a window `[i, j]` such that all elements in the window are in the range `[L, R]`. Then, I iterate through the array. 
- For each element `a[j]`, I check if it falls within the specified range. If it does, I update the `range` of window and continue. If `a[j]` is greater than `R`, I reset the `range` of window and update the starting index `i` to `j + 1`. The count is updated with the current `range` value at each step.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(N), where N is the number of elements in the array.
- **Auxiliary Space Complexity**: `O(1)`, as no extra space is used.

### Code (C++)
```cpp
class Solution{
public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        long out = 0, range = 0;
        long i = 0;
        
        for (long j = 0; j < n; ++j)
        {
            if (a[j] >= L && a[j] <= R)
                range = j - i + 1;
            else if (a[j] > R)
                range = 0, i = j + 1;

            out += range;
        }
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.