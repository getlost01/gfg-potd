## 26. Additive sequence
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/additive-sequence/1)

### My Approach
This problem can be solved using backtracking. We iterate through the string `s` and try to find the first two numbers that form a valid additive sequence. Once we find such a pair, we recursively check if the rest of the string forms a valid additive sequence starting from the sum of the first two numbers. If we can successfully form a valid additive sequence, we return true; otherwise, we continue searching for other pairs of numbers.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n*n*n)` where n is the length of the input string `s`.
- **Auxiliary Space Complexity**: `O(n)` for the recursion stack.

### Code (C++)

```cpp
class Solution {
public:
    bool solve(int ii, string &s, int n) {
        if (ii >= n)
            return true;

        int a = 0, b = 0;
        for (int i = ii; i < n; ++i) {
            a = a * 10 + (s[i] - '0');
            b = 0;
            for (int j = i + 1; j < n; ++j) {
                b = b * 10 + (s[j] - '0');
                string c = to_string(a + b);
                if (c.size() <= n - j - 1)
                    if (c == s.substr(j + 1, c.size()))
                        if (solve(j + c.size() + 1, s, n))
                            return true;
            }
        }
        return false;
    }

    bool isAdditiveSequence(string n) {
        return solve(0, n, n.size());
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.