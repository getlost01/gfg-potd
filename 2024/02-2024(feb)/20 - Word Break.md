## 20. Word Break
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/word-break1352/1)

### My Approach
- In this problem, we want to determine if a given string A can be segmented into one or more words from a provided dictionary B.
- We define a recursive function `can` that checks whether a substring starting at index `i` in string A can be segmented into words from the dictionary.
- The function iterates through each word in the dictionary and checks if it matches the substring starting at index `i` in A.
- If a match is found, we recursively call the `can` function with the updated index `i + str.size()` to check the remaining substring.
- If the end of the string is reached (`i == A.size()`), we return true indicating that the entire string A can be segmented into words from the dictionary.
- If no match is found, we return false.
- Finally, we call the `can` function with an initial index of 0 to start the recursive process and return its result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of the `can` function is O(N * M), where N is the length of string A and M is the maximum length of words in the dictionary.
- **Auxiliary Space Complexity**: The space complexity is `O(N)`, where `N` is the length of string A, due to the recursive calls that consume stack space.

### Code (C++)
```cpp
class Solution {
public:
    bool can(int i, string& A, vector<string> & B){
        if(i == A.size())
            return true;
            
        for(auto str: B){
            if(str.size() <= (A.size() - i) && A.substr(i, str.size()) == str){
                if(can(i + str.size(), A, B))
                    return true;
            }
        }
        
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
       return can(0,A,B);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.