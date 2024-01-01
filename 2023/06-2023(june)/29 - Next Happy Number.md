## 29. Next Happy Number

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/next-happy-number4538/1)

### My Approach

To find the next happy number after a given number `n`, I have used the following approach:

- I start with the next number `nextNum` after `n` and iterate until I find a happy number.
- To determine if a number is happy or not, I calculate the sum of the squares of its digits. If the sum becomes a single-digit element (`1` or `7`), the number is considered happy.
- I check if `n` itself is a happy number by using the `isHappy` function.
- If `n` is already a happy number, I return `n` as the next happy number.
- Otherwise, I increment `nextNum` by 1 and check if it is a happy number using the `isHappy` function. I continue this process until I find a happy number.
- Finally, I return the first happy number encountered.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach depends on the value of `nextNum`, which is the number of iterations required to find the next happy number after `n`. In the worst case, `nextNum` can be large, resulting in a time complexity of `O(nextNum)`. However, on average, the number of iterations required is relatively small.
- **Auxiliary Space Complexity**: `O(1)` since we are not using any extra space that scales with the input.

### Code (C++)

```cpp
class Solution {
public:
    bool isHappy(int n) {
        if (n == 1 || n == 7)
            return true;

        int next, sum;
        next = sum = n;

        while (next > 9) {
            sum = 0;

            while (next > 0) {
                int digit = next % 10;
                next /= 10;
                sum += digit * digit;
            }

            if (sum == 1 || sum == 7)
                return true;

            next = sum;
        }

        return false;
    }

    int nextHappy(int n) {
        int nextNum = n + 1;

        while (!isHappy(nextNum))
            nextNum++;

        return nextNum;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.