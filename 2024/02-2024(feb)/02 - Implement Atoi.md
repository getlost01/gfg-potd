## 02. Implement Atoi
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/implement-atoi/1)

### My Approach
I have implemented the Atoi function using a simple iteration through the input string. Here's a breakdown of the steps:

1. Initialize a variable `n` to store the converted integer.
2. Iterate through the characters of the string.
   - If it's the first character and it's a '-', skip it since it represents a negative number.
   - If the character is a digit, update `n` by multiplying it by 10 and adding the digit.
   - If the character is not a digit, return -1 as the input is invalid.
3. Return the final integer, considering the sign.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(N), where N is the length of the input string. We iterate through the string once.
- **Auxiliary Space Complexity**: O(1), as we use a constant amount of space for variables.

### Code (C++)
```cpp
class Solution {
public:
    int atoi(string s) {
        int n = 0; 
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s[i] == '-') 
                continue;
            if (s[i] >= '0' && s[i] <= '9')
                n = n * 10 + s[i] - '0';
            else 
                return -1; 
        }
        return (s[0] == '-') ? -n : n;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
