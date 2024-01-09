## 09. Search Pattern (KMP-Algorithm)
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/search-pattern0205/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
I have implemented the Knuth-Morris-Pratt (KMP) algorithm for efficient pattern searching in a given text. The algorithm uses a preprocessing step to construct the Longest Prefix Suffix (LPS) array, which is then used during the actual pattern matching.

##### Step 1: Building the LPS Array
I created a function `getLSP` to calculate the LPS array for the given pattern. This array is crucial for efficient pattern matching.

##### Step 2: Pattern Search
I implemented the `search` function to perform the actual pattern search. It uses the LPS array to optimize the matching process and keeps track of the occurrences of the pattern in the text.

For effective understanding please refer [here](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/ "here")

### Time and Auxiliary Space Complexity
- **Time Complexity**: The time complexity of the KMP algorithm is `O(m + n)`, where m is the length of the text and n is the length of the pattern. This is because each character of the text and pattern is compared at most twice.
- **Auxiliary Space Complexity**: The space complexity is `O(n)`, where n is the length of the pattern. This is due to the LPS array.

### Code (C++)
```cpp
class Solution {
public:
    void getLSP(string& pat, vector<int>& lsp) {
        int sz = 0, i = 1;
        lsp[0] = 0;
        while (i < pat.size()) {
            if (pat[i] == pat[sz]) lsp[i++] = ++sz;
            else if (sz == 0) lsp[i++] = 0;
            else sz = lsp[sz - 1];
        }
    }

    vector<int> search(string pat, string txt) {
        int n = pat.size(), m = txt.size();
        vector<int> ls(n), ans;

        getLSP(pat, ls);

        int i = 0, j = 0;
        while (i < m) {
            if (txt[i] == pat[j]) {
                ++i;
                ++j;
            }
            if (j == n) {
                ans.push_back(i - j + 1);
                j = ls[j - 1];
            } else if (i < m && txt[i] != pat[j]) {
                if (!j) i++;
                else j = ls[j - 1];
            }
        }
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.