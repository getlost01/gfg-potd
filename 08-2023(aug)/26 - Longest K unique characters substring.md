## 26. Longest K unique characters substring

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)

### My Approach

I have used a sliding window technique to find the longest substring with at most K unique characters.
- I maintained a sliding window represented by two pointers, `i` and `j`.
- I used a hash map `cnt` to keep track of the frequency of characters within the window.
- I incremented `c` whenever a new unique character was encountered within the window.
- When `c` exceeded `k`, I moved the starting `i` pointer to shrink the window and maintain at most `k` unique characters.
- I updated the `out` variable whenever `c` became equal to `k` to keep track of the longest valid substring.

### Explanation with example

Let's take the input string `"aabacbebebe"` and `k = 3` as an example:

```js
- [ a ]abacbebebe , c = 1, out = -1
- [ aa ]bacbebebe , c = 1, out = -1
- [ aab ]acbebebe , c = 2, out = -1
- [ aaba ]cbebebe , c = 2, out = -1
- [ aabac ]bebebe , c = 3, out = 5 // here c == k so out value updates
- [ aabacb] ebebe , c = 3, out = 6
- [ aabacbe ]bebe , c = 4, out = 6 // here c > k so we try to remove one element from the starting pointer
- aaba[ cbe ]bebe , c = 3, out = 6 
- aaba[ cbeb ]ebe , c = 3, out = 6 
- aaba[ cbebe ]be , c = 3, out = 6 
- aaba[ cbebeb ]e , c = 3, out = 6 
- aaba[ cbebebe ] , c = 3, out = 7 
```
Hence the Longest `K = 3` unique characters substring for this string is `7`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The code runs in `O(N)` time, where `N` is the length of the input string `s`. This is because both the `i` and `j` pointers traverse the string once.
- **Auxiliary Space Complexity**: The code uses an unordered_map `cnt` to store character frequencies, which can have at most `K` unique characters. Therefore, the space complexity is `O(K)`.
  
### Code (C++)
```cpp
class Solution {
public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> cnt;
        int i = 0, n = s.size();
        int c = 0, out = -1;

        for (int j = 0; j < n; ++j) {
            if (cnt[s[j]] == 0)
                ++c;

            ++cnt[s[j]];

            while (c > k && i < j) {
                --cnt[s[i]];
                if (cnt[s[i]] == 0)
                    --c;
                ++i;
            }

            if (c == k)
                out = max(out, j - i + 1);
        }

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.