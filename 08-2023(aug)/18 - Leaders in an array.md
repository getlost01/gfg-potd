## 18. Leaders in an array

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1)

### My Approach

To find the leaders in an array, my approach follows these steps:

- Traverse the array from right to left.
- Maintain a variable to keep track of the maximum element encountered so far.
- If the current element is greater than or equal to the maximum element encountered so far, add it to the output vector of leaders.

### Explanation with Example

Let's consider an example to illustrate the approach:

Input array: `[16, 17, 4, 3, 5, 2]`
Output leaders: `[17, 5, 2]`

Starting from the right end of the array, we encounter `2` which is the maximum among the remaining elements. So, `2` is a leader. Next, `5` is the maximum among the remaining elements, so it's also a leader. Finally, `17` is the maximum among the remaining elements, making it a leader as well.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm iterates through the array once in reverse order, which takes `O(n)` time, where `n` is the size of the array.
- **Auxiliary Space Complexity**: The extra space used is for the output vector, which stores the leaders. This takes `O(k)` space, where `k` is the number of leaders in the array.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> leaders(int a[], int n) {
        vector<int> out;
        int nax = -1;

        for (int i = n - 1; i >= 0; --i) {
            if (nax <= a[i]) {
                nax = a[i];
                out.push_back(a[i]);
            }
        }

        reverse(out.begin(), out.end());
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.