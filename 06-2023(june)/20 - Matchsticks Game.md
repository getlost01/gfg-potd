## 20. Matchsticks Game

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/-matchsticks-game4906/1)

### My Approach

To solve the matchsticks game, I have used the following approach:

- It is observed that if the number `n` is a multiple of `5`, then player `B` will win because player `A` will have to pick the last matchstick and player `B` will always have a winning move.
- Otherwise, if `n` is not a multiple of `5`, player `A` will choose a number equal to `n%5` to ensure their victory. This way, player `A` can force player `B` into a losing position by making the remaining number a multiple of `5` in the next turn.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(1)` because the calculations are performed in constant time.
- **Auxiliary Space Complexity**: `O(1)` as we are not using any extra space that scales with the input.

### Code (C++)

```cpp
class Solution {
public:
    int matchGame(long long n) {
        if(n % 5)
            return n % 5;
        
        return -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.