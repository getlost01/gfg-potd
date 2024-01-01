## 14. Check if strings are rotations of each other or not
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1)

![](https://badgen.net/badge/Level/Basic/green)

### My Approach
To check if two strings, `s1` and `s2`, are rotations of each other, 
- I concatenate `s1` with itself to create a new string `s`. 
- Then, I check if `s2` is a substring of `s` using the `find` function. If the index is not -1, then `s2` is a rotation of `s1`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the length of `s1`.
- **Auxiliary Space Complexity**: `O(N)`, as we create a new string by concatenation.

### Code (C++)
```cpp
class Solution {
public:
    bool areRotations(string s1, string s2) {
        string s = s1 + s1;
        return s.find(s2) != -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.