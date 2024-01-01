## 5. Count number of substrings

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1)

### My Approach
To count the number of substrings in a given string `s` with exactly `k` distinct characters, we can break it down into two steps:

1. First, find the number of substrings with at most `k` distinct characters.
2. Then, subtract the number of substrings with at most `k-1` distinct characters from the above count.

I used a sliding window approach (similar to moving two pointers) to achieve this. Here's how it works:

- I kept a count called `cnt` to keep track of the valid substrings and used an array called `freq` (with 26 slots, one for each alphabet letter) to keep track of the frequency of characters in the current window.
- I had two pointers, `i` and `j`, initially set to the start of the string. Additionally, I used a variable called `diff` to count the number of distinct characters in the current window.
- I went through the string from left to right using the pointer `j`.
   - For each character `s[j]`, I increased its frequency in the `freq` array and checked if it was not in the current window before (meaning `freq[s[j] - 'a'] == 1`). If so, I incremented the `diff` by 1, indicating the addition of a new distinct character.
   - After adding the character `s[j]`, I checked if `diff` was greater than `k`.
     - If it was, I moved the `i` pointer from the left end of the window, decreased the frequency of the character at `s[i]`, and checked if its frequency became zero (i.e., `freq[s[i] - 'a'] == 0`). If so, I decreased `diff` by 1, showing that a distinct character was removed from the window.
   - At each step, I added `j - i + 1` to `cnt`, representing the count of valid substrings ending at `s[j]`.
- Finally, I returned the value of `cnt`, which represents the count of valid substrings with at most `k` distinct characters.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm iterates through the string once with two pointers, so the time complexity is `O(N)`, where `N` is the length of the input string `s`.

- **Auxiliary Space Complexity**: The algorithm uses an array `freq` of size `26` to store the frequency of characters, which is a constant space requirement. Therefore, the auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution {
public:
    long long int countAtMostK(string s, int k) {
        long long int cnt = 0;
        int freq[26] = {0};
        int i = 0, diff = 0;

        for (int j = 0; j < s.size(); ++j) {
            if (!freq[s[j] - 'a'])
                ++diff;
            ++freq[s[j] - 'a'];

            while (diff > k && i <= j) {
                --freq[s[i] - 'a'];
                if (!freq[s[i] - 'a'])
                    --diff;
                ++i;
            }
            cnt += j - i + 1;
        }

        return cnt;
    }

    long long int substrCount(string s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.