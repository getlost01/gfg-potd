## 19. Subarray with given sum

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1)

### My Approach

To solve this I am using a two-pointer approach to find the subarray with the given sum.

- Initialize two pointers, `i` and `j`, for starting and ending pointers respectively. Initially, both point to the beginning of the array.
- Initialize a variable `sum` to keep track of the current sum of elements between `i` and `j`.
- Iterate through the array with ending pointer `j`, adding each element to `sum`.
	- If `sum` becomes greater than the target sum `s`, increment `i` and subtract `arr[i]` from `sum` until `sum` is less than or equal to `s`.
	- If `sum` becomes equal to `s`, we have found a subarray with the given sum. Record the indices `i+1` and `j+1` (1-based indices) and return them.
- If the loop completes without finding a subarray, return `[-1]` to indicate no such subarray exists.

### Explanation with Example

Suppose we have an array `arr = [1, 2, 3, 7, 5]` and the target sum `s = 12`.
```cpp
-> 1, 2, 3, 7, 5		, sum = 1
   -
-> 1, 2, 3, 7, 5		, sum = 3 
   ----
-> 1, 2, 3, 7, 5		, sum = 6
   -------
-> 1, 2, 3, 7, 5		, sum = 13 here we increase staring pointer to make sum <= s
   ----------
-> 1, 2, 3, 7, 5		, sum = 12 here sum == s so we return our i, j values
      -------
```
so the answer for the above example is `2, 4`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm uses a single pass through the array, so the time complexity is `O(n)`, where `n` is the size of the input array.
- **Auxiliary Space Complexity**: The algorithm uses a constant amount of extra space for variables, so the auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        vector<int> out;
        int i = 0;
        long long sum = 0;
        
        for (int j = 0; j < n; ++j) {
            sum += arr[j];
            while (sum > s && i < j) {
                sum -= arr[i];
                ++i;
            }
            if (sum == s) {
                out.push_back(i + 1);
                out.push_back(j + 1);
                return out;
            }
        }
        
        out.push_back(-1);
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.