## GFG Problem Of The Day

### 🎉 Announcement
I have created a Git Book that contains all previous editorials for my GFG-POTD solutions. You can visit **[here](https://gl01.gitbook.io/gfg-editorials/)** to access it and refer to my previous solutions. In the future, I intend to establish a contribution flow, where others can contribute their solutions to this Git Book. I would appreciate hearing your thoughts and views on this in the [discussion section](https://github.com/getlost01/gfg-potd/discussions).

----
### Today - 09 August 2023
### Que - Largest Prime Factor

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1)

### My Approach

To find the largest prime factor of a given number `n`,
- I iterate from `2` up to the square root of `n`. 
	- During this iteration, I repeatedly divide `n` by `i` as long as `n` is divisible by `i`, and keep track of the largest factor encountered. 
- Finally, I return the largest factor, which is also the largest prime factor of `n`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The loop runs from `2` to the square root of `n`, which results in a time complexity of `O(sqrt(n))`.
- **Auxiliary Space Complexity**: `O(1)` as I am using a constant amount of extra space to store the result.

### Code (C++)
```cpp
class Solution {
public:
    long long int largestPrimeFactor(int n) {
        int out = 2;
        int checkUpto = sqrt(n);
        for (int i = 2; i <= checkUpto; ++i) {
            while (n % i == 0) {
                n = n / i;
                out = max(out, i);
            }
        }
        out = max(out, n);
        return out;
    }
};
```
### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.


![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
