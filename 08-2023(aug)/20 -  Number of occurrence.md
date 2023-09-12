## 20. Number of occurrence

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1)

### My Approach

To deal with the constraints in this problem, I have use a binary search approach. 

- Implement a `lower bound` function to find the first occurrence of `x` in the sorted array.
- Implement an `upper bound` function to find the first element greater than `x`.
- Calculate the count of `x` by subtracting the lower bound index from the upper bound index.


### Explanation with Example

Consider the array: `[2, 4, 4, 4, 6, 8, 9, 10]` and the element `x = 4`.

- `lower_bound(arr, n, x)` returns the index of the first occurrence of `4`, which is 1.
- `upper_bound(arr, n, x)` returns the index after the last occurrence of `4`, which is 4.

Therefore, the frequency of 4 in the array is `4 - 1 = 3`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(log n)`, where `n` is the size of the array. Binary search takes logarithmic time.
- **Auxiliary Space Complexity** : `O(1)`, as the extra space used is constant.

### Code (C++)

```cpp
class Solution{
public:
    int lower_bound(int arr[], int n, int x) {
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            
            if(x <= arr[m])
                r = m;
            else
                l = m + 1;
        }
            
        return l;
    }

    int upper_bound(int arr[], int n, int x) {
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(x >= arr[m])
                l = m + 1;
            else
                r = m;
        }
        
        if(l < n && arr[l] <= x)
            l++;
            
        return l;
    }
    
    int count(int arr[], int n, int x) {
        int start = lower_bound(arr, n, x);
        if(arr[start] != x)
            return 0;
           
        int last = upper_bound(arr, n, x);
        
        return last - start;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.