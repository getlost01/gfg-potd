## 10. Number following a pattern
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
To generate the minimum number following a given pattern, 
- I iterate through the input string `S` and create a vector of pairs to store consecutive characters and their counts. 
- Then, I construct the output string based on this information. 
- The key idea is to increment or decrement the numbers in the output string based on whether the corresponding character in the input is `I` or `D`.
	- After observing some pattern I found that when decrementing, we need to include `count + 1` in our output, and when incrementing, we should use `count - 1` characters in the output.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where N is the length of the input string.
- **Auxiliary Space Complexity**: `O(N)`, for storing the pairs representing consecutive characters and their counts.

### Code (C++)
```cpp
class Solution{   
public:
    string printMinNumberForPattern(string S){
        vector<pair<char, int>> col;
        char curr = S[0];
        int c = (S[0] == 'I');
        
        for (auto i: S){
            if (i == curr)
                ++c;
            else{
                col.push_back({curr, c});
                c = 1;
                curr = i;
            }
        }               
        if (S.back() == 'I')
            ++c;
        col.push_back({curr, c});
        
        string out;
        c = 1;
        for (auto i: col){
            char op = i.first;
            int cnt = i.second + (op == 'D'? 1: -1);
            string temp;
            while (cnt--){
                temp += (char)('0' + c++);
            }
            if (op == 'D')
                reverse(temp.begin(), temp.end());
            out += temp;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.