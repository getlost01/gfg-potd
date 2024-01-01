## 08. Finding the Kth Permutation

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-kth-permutation-0932/1)

### My Approach

To find the Kth permutation of numbers from 1 to N, I have used the following approach:

- Start with an initial string `s` containing the numbers from 1 to N.
- Implement a permutation function `perm` to find the next permutation based on the logic below:
  - Start from the rightmost digit and find the first pair of adjacent digits where the left digit is smaller than the right digit.
  - After finding such a digit pair, find the just greater value from the left digit.
  - Swap the left digit with the just greater digit.
  - Sort all the digits to the right of the swapped digit in ascending order.
- In the `kthPermutation` function, initialize the string `s` with numbers from 1 to N.
- Iterate `k-1` times and call the `perm` function to get the next permutation of `s`.
- Finally, return the resulting string `s`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: We perform `K-1` iterations of the `perm` function, where each iteration takes O(NlogN) time due to the sorting operation. Therefore, the overall time complexity is `O(KNlogN)`.
- **Auxiliary Space Complexity**: `O(N)` since we are using a string `s` to store the numbers from 1 to N.

### Code (C++)

```cpp
class Solution {
public:
    string s = "";

    void perm(int n) {
        int i, j;
        for (i = n - 2; i >= 0; --i) {
            if (s[i] < s[i + 1])
                break;
        }
        for (j = n - 1; j > i; --j) {
            if (s[j] > s[i])
                break;
        }
        swap(s[j], s[i]);
        sort(s.begin() + i + 1, s.end());
    }

    string kthPermutation(int n, int k) {
        for (int i = 1; i <= n; ++i)
            s += (char)('0' + i);
        while (--k)
            perm(n);

        return s;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.