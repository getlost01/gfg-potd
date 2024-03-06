## 06. Search Pattern (Rabin-Karp Algorithm)
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1)

### My Approach
I suggest checking out this blog for a clear explanation of the Rabin-Karp Algorithm: [Rabin-Karp Algo](https://www.programiz.com/dsa/rabin-karp-algorithm).

### Time and Auxiliary Space Complexity

- **Time Complexity**:  Due to the use of hashing, the average time complexity is `O(n + m)`.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` since we only use a constant amount of extra space for storing variables and data structures.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> search(string pattern, string text) {
        vector<int> out;
        int mod = 10;
        int h = pattern.size();
        int n = text.size();
        int hashp = 0;
        int hasht = 0;
        int p = 1;
        
        for (int i = 0; i < h - 1; ++i)
            p = (p * 26) % mod;
        
        for (int i = 0; i < h; ++i) {
            hashp = ((hashp * 26) + pattern[i]) % mod;
            hasht = ((hasht * 26) + text[i]) % mod;
        }
        
        for (int i = 0; i <= n - h; ++i) {
            if (hashp == hasht) {
                int j;
                for (j = 0; j < h; ++j)
                    if (pattern[j] != text[i + j])
                        break;
                        
                if (j == h)
                    out.push_back(i + 1);
            }
            if (i < n - h) {
                hasht = (26 * (hasht - text[i] * p) + text[i + h]) % mod;
                if (hasht < 0)
                    hasht += mod;
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.