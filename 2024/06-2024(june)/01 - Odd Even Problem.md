## 01. Odd Even Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/help-nobita0532/1)

### My Approach
-  Initialize a vector `c` of size 26 to count the frequency of each character in the string `s`.
- Traverse through the string `s` and update the count of each character in the vector `c`.
- Initialize a counter `cnt` to zero to keep track of characters that meet the odd/even criteria.
- Iterate through the vector `c`, checking if the frequency of each character is odd or even based on the character's position in the alphabet (i.e., position % 2).
- Increment the counter `cnt` for each character that meets the condition where the frequency's odd/even status matches the character's position % 2.
- Return "ODD" if `cnt` is odd; otherwise, return "EVEN".

### Time and Auxiliary Space Complexity

- **Time Complexity**: `(O(n))`, where `( n )` is the length of the string `s`, since we are traversing the string and then iterating through a fixed-size array of length 26.
- **Auxiliary Space Complexity**: `( O(1))`, since the vector `c` has a fixed size of 26 regardless of the input size.

### Code (C++)
```cpp
class Solution {
public:
    string oddEven(string s) {
        vector<int> c(26, 0);
        for(int i = 0; i < s.size(); ++i)
            ++c[s[i] - 'a'];
            
        int cnt = 0;
        for(int i = 0; i < 26; ++i)
            if(c[i] && c[i] % 2 == (i + 1) % 2)
                ++cnt;
                
        return cnt % 2 ? "ODD" : "EVEN";
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.