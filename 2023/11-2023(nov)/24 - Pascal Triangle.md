## 24. Pascal Triangle
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pascal-triangle0652/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To generate the nth row of Pascal's Triangle, I optimize the simple brute force approach as follows:
- I initialize two vectors, `out` and `prev`, both of size n, with all elements set to 1.
- I iterate through each row, updating the elements of `out` based on the sum of the two corresponding elements from the `prev` vector.
- I also use modular arithmetic to prevent integer overflow.
- In each iteration, I update the `out` array with the values from the `prev` array.

### Explain with Example
For example, let's generate the 5th row of Pascal's Triangle:
```js
- Initialization: out = [1, 1, 1, 1, 1], prev = [1, 1, 1, 1, 1]
- After the first iteration, out = [1, 2, 1, 1, 1], prev = [1, 1, 1, 1, 1]
- After the second iteration, out = [1, 3, 3, 1, 1], prev = [1, 2, 1, 1, 1]
- After the third iteration, out = [1, 4, 6, 4, 1], prev = [1, 3, 3, 1, 1] which is the 5th row of Pascal Triangle.
```

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)`, where `n` is the number of rows.
- **Auxiliary Space Complexity**: `O(n)`, as I use two vectors of size `n`.

### Code (C++)
```cpp
class Solution {
public:
    int mod = 1e9 + 7;

    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> out(n, 1), prev(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                out[j] = (prev[j] + prev[j - 1]) % mod;
            }
            prev = out;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.