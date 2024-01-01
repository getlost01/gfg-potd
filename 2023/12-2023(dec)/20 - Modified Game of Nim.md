## 20. Modified Game of Nim
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/variation-in-nim-game4317/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
This problem is a variation of the classic Nim game. The key observation is that if the XOR of all the elements in the array is 0, the first player will always win; otherwise, the winner depends on whether the number of elements is even or odd.

Here are the steps for impolementing above logic
- Calculate the XOR of all elements in the array.
- If XOR is 0, return 1 (indicating the first player wins).
- If XOR is not 0, return 1 if the number of elements is even; otherwise, return 2.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` - We iterate through the array once.
- **Auxiliary Space Complexity**: `O(1)` - We use only a constant amount of extra space.

### Code (C++)
```cpp
class Solution {
public:
    int findWinner(int n, int A[]) {
        int XOR = 0;
        for(int i = 0; i < n; i++)
            XOR ^= A[i];

        if(XOR == 0)
            return 1;

        return n % 2 == 0 ? 1 : 2;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.