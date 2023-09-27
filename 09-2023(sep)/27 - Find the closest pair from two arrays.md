## 27. Find the closest pair from two arrays
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1)

### My Approach

I have implemented a solution to find the closest pair from two arrays using a two-pointer approach. Here are the steps I followed:

- Initialize two pointers, `a` and `b`, to the start of the first and second arrays, respectively.
- Initialize a variable `nin` to store the minimum absolute difference found so far and set it to `INT_MAX`.
- Initialize an empty vector `out` to store the closest pair.
- Iterate through both arrays while `a` is less than `n` and `b` is greater than or equal to `0`.
	- Calculate the sum of the elements at the current positions of the pointers: `sum = arr[a] + brr[b]`.
	- Check if the absolute difference between `sum` and the target value `x` is less than the current minimum difference `nin`. If so, update `nin` and set `out` to the current pair `[arr[a], brr[b]]`.
	- If `sum` is greater than `x`, decrement `b` to try a smaller element from the second array. Otherwise, increment `a` to try a larger element from the first array.
	- Repeat this process until both pointers have been exhausted.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(n + m)` because we iterate through both arrays once, where `n` is the size of the first array and `m` is the size of the second array.

- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` as we use a constant amount of extra space for variables.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> out;
        int nin = INT_MAX;
        
        int a = 0, b = m - 1;
        while (a < n && b >= 0) {
            int sum = arr[a] + brr[b];
            if (abs(sum - x) < nin) {
                out = {arr[a], brr[b]};
                nin = abs(sum - x);
            }
            if (sum > x)
                --b;
            else
                ++a;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.