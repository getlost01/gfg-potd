## 4. Roman Number to Integer

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1)

### My Approach
To convert a Roman numeral to an integer, 
- We can iterate through the input string from left to right. 
- If the current character represents a value less than the next character, we subtract the current value from the result; otherwise, we add it to the result. By doing this, we handle for cases like IV (4) and IX (9), where a smaller value precedes a larger value.

### Time and Auxiliary Space Complexity
- **Time Complexity**: The time complexity of this algorithm is `O(n)`, where `n` is the length of the input string `str`. We iterate through the string once.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` because we use a fixed-size unordered_map and a few integer variables regardless of the input size.

```cpp
class Solution {
public:
    int romanToDecimal(string &str) {
        unordered_map<char, int> mp;
        mp['I'] = 1; 
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = str.size();
        
        int out = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mp[str[i]] < mp[str[i + 1]])
                out -= mp[str[i]];
            else
                out += mp[str[i]];
        }
        
        return out;
    }
};
```

### Contribution and Support
For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.