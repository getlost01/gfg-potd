## 15. Better String
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/better-string/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach
The main trick to find the count of subsequences is this: for every extra character we add to the string, the count of subsequences doubles. This works when the words in the string don't repeat. However, if there are repetitions, we need to subtract the count of subsequences formed just before the last occurrence of that character. So, by following this method, we can solve the problem in a very efficient way.

To do this, I followed these steps:
- I created a function called `distSubSeq` to find the count of unique subsequences in a given string.
	- This function uses dynamic programming and keeps track of the count of subsequences before the last occurrence of each character using a map called `last`.
	- I go through each word in the string, checking if the current word has appeared earlier. Meanwhile, I also calculate a new count, which is twice the current count.
	- If the current word has occurred before, I subtract the count of subsequences created before its last occurrence. This helps eliminate duplicate subsequences and keeps only distinct ones.
- The `betterString` function then compares the counts of distinct subsequences for two strings and returns the one with the higher count.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the length of the input string.
- **Auxiliary Space Complexity**: `O(D)`, where `D` is the number of distinct characters in the input string.

### Code (C++)
```cpp
class Solution {
public:
    int distSubSeq(string s)
    {
        unordered_map<char, int> last;
        int count = 1;

        for (auto ch : s) {
            int newCount = 2 * count;

            if (last.find(ch) != last.end())
                newCount -= last[ch];

            last[ch] = count;
            count = newCount;
        }
        return count;
    }

    string betterString(string s1, string s2) {
        int distSubSeq1 = distSubSeq(s1);
        int distSubSeq2 = distSubSeq(s2);

        return distSubSeq2 > distSubSeq1 ? s2 : s1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.