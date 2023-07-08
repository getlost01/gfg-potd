## 19. Rearranging an Array with O(1) Extra Space

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1)

### My Approach

To rearrange an array with O(1) extra space, I have used the following approach:

- Given the constraint that the maximum value of `n` is `10^5`, along with a `long long` array called `arr`, we can leverage this constraint to store both the old and new numbers within the same array elements.
- Each array element will consist of a 10-digit number, where the first 5 digits represent the new number obtained after rearrangement, and the last 5 digits represent the old number.
- Initially, we set both the new and old numbers at the same index during the iteration. To identify the new number, we consider the first 5 digits of the 10-digit number and obtain the desired number by dividing it by `10^5`.

### Example:
#### Input:
```
10
2 8 4 1 9 5 3 0 7 6
```
We can store the array numbers as:
```
400002 700008 900004 800001 600009 500005 100003 200000 7 300006
```
By dividing these numbers by `10^5`, we obtain the desired values:

#### Output:
```
4 7 9 8 6 5 1 2 0 3
```
### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`
- **Auxiliary Space Complexity**: `O(1)`

### Code (C++)

```cpp
class Solution{
    public:
    void arrange(long long arr[], int n) {
        long long offset = 1e5;
        for (int i = 0; i < n; i++) {
            arr[i] = (arr[arr[i]] % offset) * offset + arr[i];
        }
        // Set the array with new value as "newValue = newvalue*offset + oldValue"

        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / offset;
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.