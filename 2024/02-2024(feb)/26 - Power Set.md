## 26. Power Set
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/power-set4302/1)

### My Approach
- We use a recursive function to generate all possible subsequences of the given string.
- At each step of recursion, we have two choices: either include the current character in the subsequence or exclude it.
- We recursively call the function with the next index and both choices.
- We store all generated subsequences in a vector.
- Finally, we sort the vector to ensure lexicographically sorted output.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(2^N * N)`, where `N` is the length of the input string. This is because there are `2^N` subsets, and for each subset, there can be up to N characters.
- **Auxiliary Space Complexity**: `O(2^N * N)`, the space required to store all subsets.

### Code (C++)
```cpp
class Solution {
public:
    vector<string> out;
    string curr;
    
    void subSeq(int i, string &s) {
        if (i == s.size()) {
            if (curr.size())
                out.push_back(curr);
            return;
        }
        
        curr.push_back(s[i]);
        subSeq(i + 1, s);
        curr.pop_back();
        subSeq(i + 1, s);
    }
    
    vector<string> AllPossibleStrings(string s) {
        subSeq(0, s);
        sort(out.begin(), out.end());
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.