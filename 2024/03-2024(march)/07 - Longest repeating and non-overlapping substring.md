## 07. Longest repeating and non-overlapping substring
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1)

### My Approach
For this problem, I utilized a sliding window approach. Here are the steps:
- Initialize variables `nax`, `i`, `j`, and `out`.
- Iterate through the string `s` using two pointers `i` and `j`.
- Within the loop, create substrings of `s` starting from index `i` and ending at index `j`.
- Check if the length of the current substring is greater than `nax` and if the substring repeats later in the string.
- Update `nax` and `out` accordingly.
- Slide the window by incrementing `i` or `j` based on the condition.
- Return the longest repeating and non-overlapping substring.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)`, where n is the length of the input string. This complexity arises from generating all possible substrings and checking for repeats.
- **Auxiliary Space Complexity**: `O(1)`, as we are not using any extra space that grows with the input size.

### Code (C++)

```cpp
class Solution {
public:
    string longestSubstring(string s, int n) {
        int nax = 0, i = 0, j = 0;
        string out = "-1";
    
        for( ; i < n && j < n; ++j) {
            string str = s.substr(i, j - i + 1);
    
            if (nax < str.size() && s.find(str, j + 1) != string::npos) {
                nax = str.size();
                out = str;
            } else 
                ++i;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.