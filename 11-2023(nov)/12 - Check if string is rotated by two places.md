## 12. Check if string is rotated by two places
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To check if a string is rotated by two places, 
- I compare the original string `s1` and check if the first string is equal to either of the two possible rotations of the second string `s2`. 
	- The rotations are done by taking two characters from the end and placing them at the beginning, or taking two characters from the beginning and placing them at the end.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the length of the strings.
- **Auxiliary Space Complexity**: `O(1)` as we use a constant amount of additional space.

### Code (C++)
```cpp
class Solution {
public:
    bool isRotated(string s1, string s2) {
        if (s1 == s2.substr(2) + s2.substr(0, 2))
            return true;
        if (s1 == s2.substr(s2.size() - 2) + s2.substr(0, s2.size() - 2))
            return true;

        return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.