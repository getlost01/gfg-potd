## 28. Check if a number is divisible by 8
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1)

### My Approach
After analyzing the pattern, we've observed that if the last three digits of a number are divisible by 8, then the entire number is also divisible by 8. Therefore, let's solve this question using that approach.
- I extract the last three digits of the given string.
- I convert these last three digits to an integer.
- I check if this integer is divisible by 8.
- If it is divisible by 8, I return 1; otherwise, I return -1.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(1), as the operations are constant time operations.
- **Auxiliary Space Complexity**: O(1), as no extra space is used other than a few variables.

### Code (C++)
```cpp
class Solution {
public:
    int DivisibleByEight(string s) {
        int n = s.size();
        int l = stoi(s.substr(max(n - 3, 0)));
        return l % 8 == 0 ? 1 : -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.