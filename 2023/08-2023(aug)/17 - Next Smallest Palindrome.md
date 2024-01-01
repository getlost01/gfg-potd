## 17. Next Smallest Palindrome

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/next-smallest-palindrome4740/1)

### My Approach

To solve this problem I use some constructive algo approach, which consists of the following steps.

- Create a copy vector `out` from the given `num` array for the output.
- Iterate through the first half of the `out` array and make it a palindrome by mirroring values.
- Compare `out` with the `num` array to determine if `out` is greater than `num`.
- If `out` is greater than `num`, no further operation is needed, and we return `out`.
- If `out` is not greater than `num`, find the middle indices of the `out` array.
- To get just greater values, Increment the numbers from the `middle` indices towards the `corners` until a non-9 digit is encountered.
	- If any non-9 digit occurs then just increase it by 1and return `out`.
- If in out array all digits are 9, convert the array to `[1, 0, 0, ..., 0, 1]` form.

### Explanation with Example

Consider the input array: `[1, 2, 3, 4, 5]`

```js
- Make the first half of out a palindrome: [1, 2, 3, 2, 1]
- Compare with num: [1, 2, 3, 2, 1] < [1, 2, 3, 4, 5]
- Increment middle values: [1, 2, 4, 2, 1]
- Result: [1, 2, 4, 2, 1]
```

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity is primarily determined by iterating over the out array and the num array, which both have `n` elements. So, the time complexity is `O(n)`.
- **Auxiliary Space Complexity**: The additional space used is for the `out` array, which has the same size as the input array. Hence, the auxiliary space complexity is `O(n)`.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> generateNextPalindrome(int num[], int n) {
        vector<int> out(num, num + n); 		// Copy num array for output
        
        int i = 0, j = n - 1;

        while (i < j) { 		// Convert 'out' array into a palindrome
            out[j] = out[i];
            ++i;
            --j;
        }

        bool isBig = false;
        for (int it = n / 2; it < n; ++it) { 		// Check if 'out' is greater than 'num'
            if (out[it] > num[it]) {
                isBig = true;
                break;
            }
            if (out[it] < num[it])
                break;
        }

        if (isBig)		 // If 'out' is greater, no further operation needed
            return out;

        i = (n % 2) ? n / 2 : (n / 2 - 1);  		// Mids of the out array
        j = n / 2;

        while (i >= 0) { 		// Incrementing numbers from the middle to the corners
            if (out[i] < 9) {
                out[i] = out[j] = out[i] + 1;
                return out;
            }
            out[i] = out[j] = 0;
            --i;
            ++j;
        }

        out[0] = 1; 		// If all digits are 9, convert to [1, 0, 0, ..., 0, 1]
        out.push_back(1);

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.