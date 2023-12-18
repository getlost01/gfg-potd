## 18. Game of XOR

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

- Use a loop to iterate through each element of the array.
- For each element at index i, calculate its frequency in all possible subarrays. The formula for frequency is (i + 1) * (N - i).
- If the calculated frequency is odd, it means the element at index i contributes to the XOR of the result.
- If the frequency is odd, XOR the corresponding element at index i with the current result.
- After iterating through all elements, the final result is the XOR of the values of all subarrays.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where n is the size of the array.
- **Auxiliary Space Complexity**: `O(1)`, as I only use a constant amount of extra space.

### Code (C++)

```cpp
class Solution {
  public:
    int gameOfXor(int N , int A[])
    {
        int ans=0;
        for (int i = 0; i < N; ++i)
        {
            int num=(i+1)*(N-i);
            if (num%2==1)
                ans^=A[i];
        }
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
