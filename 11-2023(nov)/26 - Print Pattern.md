## 26. Print Pattern
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-pattern3549/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To generate this specific pattern based on a given integer `N`, 
- I use a do-while loop to iteratively add and subtract a value (`toggle`) from `N`. 
- I toggle the sign of `toggle` each time it goes below or equal to 0. 
- This continues until `c` becomes equal to `N`, and I store each intermediate result in the `out` vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the input integer.
- **Auxiliary Space Complexity**: `O(N)`, as we store the pattern in a vector.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> pattern(int N) {
        if (N <= 0)
            return {N};
            
        int toggle = -5;
        int c = N;
        vector<int> out;
        
        do {
            out.push_back(c);
            c += toggle;
            if (c <= 0)
                toggle = -toggle;
        } while (c != N);
        
        out.push_back(N);
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.