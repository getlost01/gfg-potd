## 15. Flip Bits

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/flip-bits0240/1)

### My Approach

To solve this problem, I've utilized the concept a kind of sliding windows. In this approach, we initiate the tracking of the longest window that maximizes the benefits of performing flips to generate the highest possible count of `1s`.
- Initialize variables `zero`, `one`, and `max_flips` to keep track of the count of zeros, ones, and maximum consecutive flips possible with positive amount of new 1's.
- Iterate through the input array `a`.
  - If the current element is 0, increment the `zero` count.
  - If the current element is 1, decrement the `zero` count and increment the `one` count.
  - If `zero` becomes negative, reset it to 0.
  - Update `max_flips` with the maximum of `zero` and `max_flips`.
- The result will be the sum of `max_flips` and `one`, indicating the maximum consecutive flips possible while allowing some flips of 1s to 0s.

### Explanation with Example

Consider the input array: `a = {1, 0, 0, 1, 0, 0, 1}`.

```js
Initially,  zero = 0  ,  one = 0  ,  max_flips = 0

- index 0:  zero = 0  ,  one = 1  ,  max_flips = 0
- index 1:  zero = 1  ,  one = 1  ,  max_flips = 1
- index 2:  zero = 2  ,  one = 1  ,  max_flips = 2
- index 3:  zero = 1  ,  one = 2  ,  max_flips = 2
- index 4:  zero = 2  ,  one = 2  ,  max_flips = 2
- index 5:  zero = 3  ,  one = 2  ,  max_flips = 3
- index 6:  zero = 2  ,  one = 3  ,  max_flips = 3
```

The maximum benefit of consecutive flips that increase the count of 1's is `3`, resulting in a total of 1's equal to`3 + 3 = 6`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where `n` is the length of the input array.
- **Auxiliary Space Complexity**: The algorithm uses a constant amount of extra space for variables. Therefore, the auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution {
public:
    int maxOnes(int a[], int n)
    {
        int zero = 0, one = 0, max_flips = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0)
                zero++;
            else{
                zero--;
                one++;
            }

            if (zero < 0)
                zero = 0;

            max_flips = max(zero, max_flips);
        }
        return max_flips + one;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.