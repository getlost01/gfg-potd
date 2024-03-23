## 22. Fibonacci series up to Nth term
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1)

### My Approach
- Initialize an empty vector vec to store the Fibonacci series.
- Initialize variables n1 and n2 with initial Fibonacci values.
- If n is 0, push n1 into vec and return vec.
- If n is 1, push both n1 and n2 into vec and return vec.
- For i starting from 2 up to n, calculate the next Fibonacci number by adding the last two elements of vec, take modulo mod, and push it into vec.
- Return the vec vector containing the Fibonacci series.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, because it iterates N times to generate the Fibonacci series.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N)`, where N is the user input.

### Code (C++)
```cpp
class Solution {
  public:
    const int mod=1e9+7;
    vector<int> Series(int n)
    {
        vector<int>vec;
        int n1=0, n2=1;
        vec.push_back(n1);
        if (n==0)
            return vec;
        vec.push_back(n2);
        if (n==1)
            return vec;
        for (int i=2;i<=n;i++)
        {
            int num=(vec[i-1]+vec[i-2])%mod;
            vec.push_back(num);
        }
        return vec;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
