## 11. Lucky Numbers

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1)

### My Approach

An observation based question, when you try few examples you get a sequence formula.
- To determine if a number is lucky, I start with a counter `cnt` set to 2.
- I then enter a loop that continues until `cnt` is less than or equal to `n`.
	- Inside the loop, I check if `n` is divisible by `cnt`. If it is, I return `false` because a lucky number cannot have any divisors other than 1.
	- If `n` is not divisible by `cnt`, I subtract `n` divided by `cnt` from `n` and increment `cnt` by 1.
- After the loop, if we haven't returned `false`, I return `true` because the number is a lucky number.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this algorithm is `O(sqrt(n))`, where n is the input number.
- **Auxiliary Space Complexity**: The algorithm uses a constant amount of extra space, so the auxiliary space complexity is O(1).

### Code (C++)
```cpp
class Solution {
public:
    bool isLucky(int n) {
        int cnt = 2;
        while(cnt <= n){
            if(n % cnt == 0)
                return false;

            n -= n/cnt;
            ++cnt;
        }

        return true;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.