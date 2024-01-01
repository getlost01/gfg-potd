## 18. Game of XOR

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/game-of-xor1541/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

In this problem, I used XOR property and some observations:
- XOR of any even occurrences of a number is zero.
- By observing arrays of different sizes, I found the number of occurrences for each index:
```
for n = 1:  1
for n = 2:  2 2
for n = 3:  3 4 3
for n = 4:  4 6 6 4
for n = 5:  5 8 9 8 5
for n = 6:  6 10 12 12 10 6
```
From the above observation, we can conclude:
- If the array length is even, return 0 since all even occurrences result in an XOR value of 0.
- If the array length is odd, iterate through the array and XOR all odd occurrence indices, as the XOR of odd occurrences gives the number itself.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the length of the array.
- **Auxiliary Space Complexity**: `O(1)`

### Code (C++)

```cpp
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        if (N % 2 == 0)
            return 0;

        int XOR = 0;
        for (int i = 0; i < N; i += 2)
            XOR ^= A[i];
        return XOR;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
