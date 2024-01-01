## 11. Isomorphic Strings
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To determine if two strings are isomorphic, 
- I create two maps, `mp1` and `mp2`, to store the mapping from characters in `str1` to `str2` and vice versa. 
- I iterate through both strings simultaneously, updating the mappings. 
- If at any point, the mapping doesn't hold, I return false. 
- If the entire iteration completes without any mismatches, the strings are isomorphic.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the length of the input strings.
- **Auxiliary Space Complexity**: `O(N)`, as we use two unordered maps.

### Code (C++)
```cpp
class Solution {
public:
    bool areIsomorphic(string str1, string str2) {
        if (str1.size() != str2.size())
            return false;

        unordered_map<char, char> mp1, mp2;
        for (int i = 0; i < str1.size(); i++) {
            mp1[str1[i]] = str2[i];
            mp2[str2[i]] = str1[i];
        }

        for (int i = 0; i < str1.size(); i++) {
            if ((mp1[str1[i]] != str2[i]) || (mp2[str2[i]] != str1[i]))
                return false;
        }
        return true;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.