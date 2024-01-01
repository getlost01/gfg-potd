## 17. Print first n Fibonacci Numbers

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1)

### My Approach

Simple go with the flow of question statement.

- If n <= 2, return a vector containing n ones.
- Otherwise, initialize a vector 'out' of size n and set the first two elements to 1 (since the first two Fibonacci numbers are always 1).
- Use a loop to calculate the remaining Fibonacci numbers and store them in the 'out' vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The loop runs for `n` iterations to calculate the Fibonacci numbers, which is `O(n)`.
- **Auxiliary Space Complexity**: I use a vector of size `n` to store the Fibonacci numbers, which is `O(n)`.

### Code (C++)

```cpp
class Solution {
public:
    vector<long long> printFibb(int n) 
    {
        if(n <= 2)
            return vector<long long>(n, 1);
            
        vector<long long> out(n);
        out[0] = out[1] = 1;
        
        for(int i = 2; i < n; ++i) {
            out[i] = out[i - 1] + out[i - 2];
        }
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.