## 26. Print Pattern
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-pattern3549/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To make this pattern, I followed a recursive technique with backtracking.
- I kept reducing N by 5 in a loop until it got to 0 or less.
- While doing this, I added the current N value to the output vector twice. Once before making the recursive call and once after.
- The pattern comes from the sequence of values added to the vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the input integer.
- **Auxiliary Space Complexity**: `O(N)`, as we store the pattern in a vector.

### Code (C++)
```cpp
class Solution {
public:
    void solve(int n, vector<int>& out) {
        out.push_back(n);
        if (n <= 0)
            return;
        solve(n - 5, out);
        out.push_back(n);
    }

    vector<int> pattern(int N) {
        vector<int> out;
        solve(N, out);
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.