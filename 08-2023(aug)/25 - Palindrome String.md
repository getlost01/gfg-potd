## 25. Palindrome String

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/palindrome-string0817/1)

### My Approach

I have implemented a two-pointer approach. 
- I start with two pointers, one at the beginning of the string (`i`) and one at the end of the string (`j`). 
- I iterate through the string, comparing characters at these two pointers. If they ever differ, I return `false` as it's not a palindrome.
- If I successfully reach the middle of the string without finding any differing characters, I return `true`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where `n` is the length of the input string `S`. We traverse half of the string to determine if it's a palindrome.
- **Auxiliary Space Complexity**: `O(1)`, as we are using a constant amount of extra space to store `i` and `j`.

### Code (C++)

```cpp
class Solution {
public:
    int isPalindrome(string S) {
        int i = 0, j = S.size() - 1;
        while (i < j) {
            if (S[i] != S[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.