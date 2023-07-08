## 10. Arranging the Array

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/arranging-the-array1131/1)

### My Approach

To arrange the given array such that all negative numbers appear first followed by positive numbers, I have used the following approach:

- Create two separate vectors, `neq` and `pos`, to store the negative and positive numbers, respectively.
- Traverse the given array and for each element, if it is negative, push it into the `neq` vector; otherwise, push it into the `pos` vector.
- Calculate the size of the `neq` vector.
- Iterate from index 0 to `sz-1` and assign the elements from the `neq` vector to the original array.
- Iterate from index `sz` to `n-1` and assign the elements from the `pos` vector to the original array.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` since we traverse the given array once to separate negative and positive numbers and then assign the elements back to the original array.
- **Space Complexity**: `O(n)` since we use two separate vectors, `neq` and `pos`, to store the negative and positive numbers, respectively.

### Code (C++)

```cpp
class Solution {
public:
    void Rearrange(int arr[], int n) {
        vector<int> neq, pos;
        for(int i = 0; i < n; ++i) {
            if(arr[i] < 0) {
                neq.push_back(arr[i]);
            } else {
                pos.push_back(arr[i]);
            }
        }
        int sz = neq.size();
        for(int i = 0; i < sz; ++i)
            arr[i] = neq[i];
        for(int i = sz; i < n; ++i)
            arr[i] = pos[i - sz];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.