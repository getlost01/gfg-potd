## 29. Check if a string is repetition of its substring of k-length
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
This GFG question is a little unclear. In simple terms, it's asking if we can turn a given string into a repeating one by replacing it just once at positions `i` and `j` so that all substrings of length k become repetitive.
```
Example:
s = "ababcdabab"
k = 2
so in this we can replace 0th index substring "ab" with 5th index substring "cd"
```

To solve this question here are steps:
- First check if the length of the string is divisible by `k` or not. 
	- If not, it's impossible to form substrings of length `k` evenly. 
	- If it is divisible, we iterate through the string and insert substrings of length `k` into an unordered_set. 
	- The final check is whether the size of the set is less than or equal to 2, indicating that there are only one or two unique substrings of length `k`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(n)` where n is the length of the input string. We iterate through the string once.
- **Auxiliary Space Complexity** : `O(n/k)` for the unordered_set, where k is the length of the substring.

### Code (C++)
```cpp
class Solution {
public:
    int kSubstrConcat(int n, string s, int k) {
        if (n % k > 0)
            return 0;

        unordered_set<string> st;
        for (int i = 0; i < n / k; ++i)
            st.insert(s.substr(i * k, k));

        return st.size() <= 2;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.