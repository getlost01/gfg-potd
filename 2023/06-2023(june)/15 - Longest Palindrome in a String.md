## 15. Longest Palindrome in a String

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1)

### My Approach

To find the longest palindrome in a given string, I have used the following approach:

- I implemented a straightforward approach using `two pointers` to identify substrings and determine whether they are palindromic.
- To optimize efficiency and avoid unnecessary checks, I started with larger substrings and gradually reduced their size.
- I initialized an output string `out` with the first character of the input string `s`.
- I also initialized a variable `ms` to store the maximum length of the palindromic substring found so far, which is initially set to 1 (length of the first character).
- I iterated over the string `s` using two nested loops. The outer loop starts from the first character and goes up to the second-to-last character, while the inner loop starts from the last character and goes down to the character next to the current outer loop index.
- For each combination of indices, I checked if the substring from `i` to `j` (inclusive) is a palindrome by comparing the characters at the corresponding indices using the `ispalin` helper function.
- If the current substring is a palindrome and its length is greater than `ms`, I updated `ms` with the new maximum length and stored the substring in `out` using the `substr` function.
- Finally, I returned the `out` string containing the longest palindromic substring.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N^3)`, where N is the length of the input string. This is because we have nested loops that iterate over all possible substrings of `s`, resulting in a cubic time complexity.
- **Auxiliary Space Complexity**: `O(1)` since we are not using any extra space that scales with the input.

### Code (C++)

```cpp


class Solution {
  public:
    bool ispalin(string& s, int i ,int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;

            ++i; --j;
        }
        return true;
    }

    string longestPalin (string s) {
        int n = s.size();
        string out;
        out.push_back(s[0]);
        int ms = 1;
        for(int i = 0; i<n-1 ;++i){
            for(int j = n-1; j>i; --j){
                if((j-i+1)>ms && ispalin(s,i,j)){
                    ms = j-i+1;
                    out = s.substr(i,j-i+1);
                }
            }
        }
        return out;
        
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.