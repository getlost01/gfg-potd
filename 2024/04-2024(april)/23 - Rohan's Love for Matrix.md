## 23. Rohan's Love for Matrix
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1)

### My Approach
- Initialize two variables prev1 and prev2 to store the values of the first and second elements of the matrix respectively.
- Iterate from 2 to n to calculate the nth power of the matrix.
- Inside the loop, calculate the next element curr of the matrix as the sum of the previous two elements (prev1 and prev2) modulo 1000000007.
- Update prev1 and prev2 with the values of prev2 and curr respectively.
- After the loop, return the value of prev2, which represents the first element of the resulting matrix an.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`
- **Auxiliary Space Complexity** : `O(1)`

### Code (C++)

```cpp
class Solution {
  public:
    int firstElement(int n)
    {
        int prev1=0, prev2=1;
        for (int i=2;i<=n;i++)
        {
            int curr=(prev1+prev2)%1000000007;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
