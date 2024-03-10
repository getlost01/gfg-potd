## 10. Remove all duplicates from a given string
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1)

### My Approach.
Simple straightforward questions.
- I use an unordered_set to keep track of characters encountered.
- Iterate through the input string.
- If the current character is not in the set, add it to the output string and insert it into the set.
- Return the output string.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`, where N is the length of the input string. We iterate through the string once.
- **Auxiliary Space Complexity** : `O(N)`, where N is the length of the input string.

### Code (C++)
```cpp
class Solution {
public:
    string removeDuplicates(string str) {
        unordered_set<char> st;
        string out;
        for(auto i : str){
            if(st.find(i) == st.end()){
                out += i;
                st.insert(i);
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.