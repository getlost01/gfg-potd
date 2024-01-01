## 3. Column Name from a Given Column Number

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1)

### My Approach

To convert a given column number to an Excel column name, I follow these steps:
- Create a vector `code` of characters to represent the alphabet, where `code[i]` corresponds to the character for the column number `i` (0 to 25).
- Initialize the first element `code[0]` as 'Z' because in Excel, the last column is 'Z'.
- Iterate while `n` is greater than 0:
   - Append the character represented by `code[n % 26]` to the output string `out`.
   - If `n % 26` is 0, decrement `n` by 1 to handle cases like column 26 ('Z').
   - Divide `n` by 26 to move to the next column.
- Reverse the `out` string to get the correct column name.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(log(n))`, The loop runs for the number of digits in `n` in base `26`, which is equivalent to `O(log(n))`.
- **Auxiliary Space Complexity**: `O(log(n))`, The space required to store the output string `out` is proportional to the number of digits in `n` in base `26`.

### Code (C++)

```cpp
class Solution {
public:
    string colName(long long int n) {
        string out;
        vector<char> code(26);
        for (int i = 1; i < 26; ++i)
            code[i] = (char)('A' + i - 1);
        code[0] = 'Z';

        while (n) {
            out += code[n % 26];
            if (n % 26 == 0)
                --n;
            n /= 26;
        }

        reverse(out.begin(), out.end());
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.