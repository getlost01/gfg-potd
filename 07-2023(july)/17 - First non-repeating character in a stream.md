## 17. First non-repeating character in a stream

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)

### Approach

To find the first non-repeating character in a stream, follow these steps:

- Create a counter array, `cnt`, of size 26 to count the occurrences of characters in the input string. Initialize it with zeros.
- Initialize an empty vector called `last` to store the order of characters based on their first occurrence.
- Iterate through each character in the input string `A`.
	- Check if the current character is the first occurrence. If it is, add it to the `last` vector.
	- Find the first character in the `last` vector that has occurred only once.
	- If there are no characters with a single occurrence in the `last` vector, add '#' to the output string.
	- Otherwise, add the first occurrence element from the `last` vector to the output string.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where n is the length of the input string. We iterate through the string once.
- **Auxiliary Space Complexity**: `O(26)`, as the space used for `cnt` and `last` is constant, having a size of `26`.

### Code (C++)
```cpp
class Solution {
public:
    string FirstNonRepeating(string A) {
        vector<int> cnt(26, 0);
        vector<char> last;
        int firstOccur = 0;
        string out = "";

        for (int i = 0; i < A.size(); ++i) {
            cnt[A[i] - 'a']++;
            
            if (cnt[A[i] - 'a'] == 1)
                last.push_back(A[i]);
            
            while (firstOccur < last.size() && cnt[last[firstOccur] - 'a'] > 1) 
                ++firstOccur;
            
            if (firstOccur == last.size()) {
                out += '#';
            } else {
                out += last[firstOccur];
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.