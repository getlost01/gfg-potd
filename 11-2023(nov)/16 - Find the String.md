## 16. Find the String
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-string/1)

![](https://badgen.net/badge/Level/Hard/red)

### Solution Recommendation
At first glance I was not able to solve this question on my own then, on search I found that this question is a standard [De Bruijn sequence](https://en.wikipedia.org/wiki/De_Bruijn_sequence "De Bruijn sequence").

For a clear explanation, I strongly recommend checking out this [GFG article](https://www.geeksforgeeks.org/de-bruijn-sequence-set-1/ "GFG article"). 

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(k^n)`, where `k` is the number of choices for each character and `n` is the size of substring. 
- **Auxiliary Space Complexity**: `O(k^n*n)`, due to the set storing visited nodes in set `seen`.

### Code (C++)
```cpp
class Solution {
public:
    void dfs(int k, string prev, unordered_set<string> &seen, string &edges) {
        for (char i = '0'; i <= ('0' + k - 1); i++) {
            string cur = prev + i;
            if (seen.find(cur) == seen.end()) {
                seen.insert(cur);
                dfs(k, cur.substr(1), seen, edges);
                edges += i;
            }
        }
    }

    string findString(int n, int k) {
        unordered_set<string> seen;
        string startingNode = string(n - 1, '0');
        string edges;
        dfs(k, startingNode, seen, edges);

        string ret = edges + startingNode;
        return ret;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.