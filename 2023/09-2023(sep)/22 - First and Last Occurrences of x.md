## 22. First and Last Occurrences of x

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1)

### My Approach
I have used a binary search approach to find the first and last occurrences of the element `x` in the given sorted array. Here are the steps:

- Implement a `lower_bound` function using binary search to find the first occurrence of `x`. 
	- The `lower_bound` function will return the index of the first element greater than or equal to `x`.
- Check if the element at the index returned by `lower_bound` is equal to `x`. If not, return `{-1, -1}` to indicate that `x` is not present in the array.
- Implement an `upper_bound` function using binary search to find the last occurrence of `x`. 
	- The `upper_bound` function will return the index of the `first element greater than x`. Subtract 1 from this index to get the index of the last occurrence of `x`.
- Return a vector containing the indices of the first and last occurrences of `x`.

### Time and Auxiliary Space Complexity

- **Time Complexity:** Both the `lower_bound` and `upper_bound` functions use binary search, which has a time complexity of `O(log n)`, where `n` is the size of the array. Thus, the overall time complexity of the `find` function is O(log n).

- **Auxiliary Space Complexity:** The `find` function uses a constant amount of auxiliary space, so the space complexity is `O(1)`.

### Code (C++)
```cpp
class Solution {
public:
    int lower_bound(int arr[], int n, int x) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] >= x)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }

    int upper_bound(int arr[], int n, int x) {
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] > x)
                r = m;
            else
                l = m + 1;
        }
        return r - 1;
    }

    vector<int> find(int arr[], int n, int x) {
        int firstOccur = lower_bound(arr, n, x);
        if (arr[firstOccur] != x)
            return {-1, -1};

        int lastOccur = upper_bound(arr, n, x);
        return {firstOccur, lastOccur};
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.