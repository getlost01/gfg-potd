## 12. Perfect Numbers

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/perfect-numbers3207/1)

### My Approach

A straightforward brute-force method that involves identifying all factors that divide the given number. Subsequently, these factors are summed, and the resulting sum is compared to `n` to check whether they both are equal.

- To determine if a number is perfect, I iterate through all numbers from 2 to the square root of the given number.
	- For each divisor `i`, I check 
		- if it divides `n`. If it does, I add `i` to our sum.
	- Additionally, if `n` is not equal to `i` (to avoid counting the same factor twice)
		- if it I add `n/i` to the sum.
- After looping through all potential divisors, I compare the sum to `n`. If they are equal, the number is perfect.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(sqrt(n))`, where `n` is the input number. This is because we iterate up to the square root of `n` to find divisors.
- **Auxiliary Space Complexity**: `O(1)`. We use a constant amount of extra space for the `sum` variable.

### Code (C++)
```cpp
class Solution {
public:
    int isPerfectNumber(long long n) {
        if (n == 1)
            return 0;
        long long sum = 1;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                sum += i;
                if (n / i != i)
                    sum += n / i;
            }
        }
        return sum == n;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.