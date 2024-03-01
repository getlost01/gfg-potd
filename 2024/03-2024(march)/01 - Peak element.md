## 01. Peak element
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/peak-element/1)

### My Approach
I used binary search to find the peak element. This method relies on the fact that there's a point where the sequence starts increasing and then starts decreasing.
- We initialize two pointers, `left` and `right`, representing the start and end of the array, respectively.
- We then enter a loop where we calculate the middle index.
- If the middle element is less than its adjacent element to the right, it means the peak element must be on the right side of the middle element. So, we move `left` to `mid + 1`.
- Otherwise, if the middle element is greater than or equal to its adjacent element to the right, it means the peak element must be on the left side of the middle element or could be the middle element itself. So, we move `right` to `mid`.
- We keep doing this until `left` is less than `right`, at which point `left` will be pointing to the peak element.
  
### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of the binary search approach is `O(log n)`, where n is the number of elements in the array.
- **Auxiliary Space Complexity**: The space complexity is `O(1)` as we are using only a constant amount of extra space.

### Code (C++)
```cpp
class Solution {
public:
    int peakElement(int arr[], int n) {
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.