## 07 Least Prime Factor

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1)

### My Approach
To solve the problem, I have used a simple brute force approach to find the least prime factor for each number up to `n`. Here are the steps I followed:

- I implemented the `findFactor` function, which takes an integer `n` as input and returns its least prime factor.
- Within the `findFactor` function, I first check if `n` is less than 2. If it is, I return `n` itself.
- Then, I iterate from 2 to the square root of `n` (inclusive) and check if `n` is divisible by `i`. If it is, I return `i` as the least prime factor.
- If no prime factor is found in the range, I return `n` as the least prime factor.
- Finally, I implemented the `leastPrimeFactor` function, which takes an integer `n` as input and returns a vector `out` containing the least prime factor for each number from 0 to `n`.
- Within the `leastPrimeFactor` function, I initialized the vector `out` with size `n+1`.
- Then, I iterated from 0 to `n` and assigned the least prime factor of each number to the corresponding index in the `out` vector.
- Finally, I returned the `out` vector.

### Time and Auxiliary Space Complexity
- **Time Complexity**:  `O(n*sqrt(n))`, where `n` is the given number. This is because for each number from `0 to n`, we iterate up to the square root of the number to find its least prime factor.
- **Auxiliary Space Complexity**: `O(n)` since we are using a vector `out` of size `n+1` to store the least prime factors for each number.

### Code (C++)
```cpp
class Solution {
  public:
    int findFactor(int n){
        if(n<2) return n;
        for(int i = 2;i<=sqrt(n);++i ){
            if(n%i == 0)
                return i;
        }
        return n;
    }
    
    vector<int> leastPrimeFactor(int n) {
        vector<int> out(n+1);
        for(int i = 0;i<=n;++i)
            out[i] = findFactor(i);
        return out;
    }
};
```

### Contribution and Support
For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.