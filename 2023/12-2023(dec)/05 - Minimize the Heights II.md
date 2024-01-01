## 05. Minimize the Heights II
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
Simply greddy approach, I start by sorting the array. Then, for each element, I consider two possibilities:
- Getting max after adding `k` to the current element and subtracting `k` from the maximum element.
- Getting min after subtracting `k` from the current element and adding `k` to the minimum element.
I update the minimum difference (`out`) by comparing it with the difference obtained from the above two possibilities.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(nlog n)` for sorting `arr` array.
- **Auxiliary Space Complexity**: `O(1)`, as no extra space is used.


### Code (C++)
```cpp
class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        int out = arr[n - 1] - arr[0];

        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - k >= 0) {
                int nax = max(arr[i] + k, arr[n - 1] - k);
                int nin = min(arr[i + 1] - k, arr[0] + k);
                out = min(out, nax - nin);
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.