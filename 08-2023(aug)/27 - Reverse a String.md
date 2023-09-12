## 27. Reverse a String

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/reverse-a-string/1)

### My Approach

Simply used a two-pointer approach to reverse the given string.
- I initialized two pointers, `i` and `j`, to the start and end of the string respectively.
- I swapped the characters at these pointers and moved `i` forward and `j` backward until they met in the middle of the string.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this algorithm is `O(N/2)`, where `N` is the length of the input string. This is because we only need to swap characters up to the middle of the string.
- **Auxiliary Space Complexity**: The algorithm uses only a constant amount of extra space for the two pointers and the swapping operation, so the space complexity is `O(1)`.

### Code (C++)
```cpp
class Solution
{
public:
    string reverseWord(string str)
    {
        int i = 0, j = str.size() - 1;
        while (i < j)
        {
            swap(str[i], str[j]);
            ++i;
            --j;
        }

        return str;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.