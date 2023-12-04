## 04. Sum-string
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-string3151/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach
I checked all possible combinations of substrings to find a valid sum-string. I iterate through the string, considering all possible splits into three substrings (`num1`, `num2`, and `currSum`). I add `num1` and `num2` using a helper function (`add`), and then compare the result with `currSum`. If they match, I continue the process recursively.
To solve this, the functions are as follows:

1. **Addition Function (`add`):**
   - Takes two strings representing numbers and performs addition digit by digit.
   - Handles carry during addition.
   - Returns the result as a string.

2. **Solver Function (`solve`):**
   - Takes a string `s` and indices `i`, `j`, and `k`.
   - Extracts three substrings from `s` (num1, num2, currSum).
   - Adds `num1` and `num2` using the `add` function.
   - Compares the result with currSum.
   - Recursively calls itself with updated indices.
   - Returns true if the entire string is a valid sum string.

3. **Main Function (`isSumString`):**
   - Iterates through all possible pairs of indices `(j, k)`.
   - Calls `solve` to check if the string is a valid sum string.
   - Returns true if any valid sum string is found.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N^3)`, where N is the length of the input string.
  - The nested loops iterate over all possible pairs of indices `(j, k)`.
  - In the worst case, the `solve` function has a time complexity of `O(N)` per call.
- **Auxiliary Space Complexity**: `O(N)`, where `N` is the length of the input string.
  - The recursive calls and string manipulations contribute to space complexity.

### Code (C++)
```cpp
class Solution {
public:
    string add(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res;

        while (i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --i;
            --j;
        }
        while (i >= 0) {
            int sum = (num1[i] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --i;
        }
        while (j >= 0) {
            int sum = (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --j;
        }
        if (carry)
            res += carry + '0';
            
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool solve(string& s, int i, int j, int k) {
        string num1 = s.substr(i, j - i);
        string num2 = s.substr(j, k - j);
        string sum = add(num1, num2);

        int n = sum.size();
        int len = k + n;

        if (len > s.size())
            return false;

        string currSum = s.substr(k, n);

        if (currSum != sum)
            return false;
        if (len == s.size())
            return true;
        return solve(s, j, k, len);
    }

    int isSumString(string& s) {
        int n = s.size();
    
        for (int j = 1; j < n; ++j) 
            for (int k = j + 1; k < n; ++k) 
                if (solve(s, 0, j, k))
                    return true;

        return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.