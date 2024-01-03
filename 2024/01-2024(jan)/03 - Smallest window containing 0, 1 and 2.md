## 03. Smallest window containing 0, 1 and 2
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To find the smallest window containing 0, 1, and 2, I used a sliding window approach. Here are the steps:
- Initialize a vector `pos` to store the last positions of 0, 1, and 2 in the string. Initialize `out` to `INT_MAX`.
- Iterate through the string, updating the positions of 0, 1, and 2 in the `pos` vector.
- For each character, calculate the minimum and maximum positions in the `pos` vector.
- If the minimum position is not `-1`, update `out` with the minimum window size.
- Return the minimum window size if found, otherwise return -1.

### Time and Auxiliary Space Complexity

- **Time Complexity:** `O(N)`, where `N` is the length of the input string. The algorithm iterates through the string once.
  
- **Auxiliary Space Complexity:** `O(1)`, as the size of the `pos` vector is constant.

### Code (C++)

```cpp
class Solution {
public:
    int smallestSubstring(string S) {
        vector<int> pos(3, -1);
        int out = INT_MAX;
        
        for(int i = 0; i < S.size(); ++i) {
            pos[S[i] - '0'] = i;
            
            int nin = INT_MAX, nax = 0;
            for(auto it: pos) {
                nin = min(nin, it);
                nax = max(nax, it);
            }    
            
            if(nin != -1)
                out = min(out, nax - nin + 1);
        }
        
        return out == INT_MAX ? -1 : out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
```