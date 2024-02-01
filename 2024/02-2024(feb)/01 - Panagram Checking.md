## 01. Panagram Checking

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

1. **Vector Initialization**: Create a vector `f` of size 26, initialized with zeros. This vector is used to keep track of the occurrence of each letter in the alphabet.

    ```cpp
    std::vector<int> f(26, 0);
    ```

2. **Iterate Through the String**: Iterate through each character in the input string.

    ```cpp
    for (auto i : s) {
    ```

3. **Convert to Lowercase**: Convert the current character to lowercase.

    ```cpp
    char cur = std::tolower(i);
    ```

4. **Check if Character is a Lowercase Letter**: If the character is a lowercase letter, update the corresponding index in the vector `f` to 1.

    ```cpp
    if (cur >= 'a' && cur <= 'z') {
        f[cur - 'a'] = 1;
    }
    ```

5. **Check Pangram Condition**: Check if all elements in the vector `f` are set to 1. This indicates that all lowercase letters are present in the input string.

    ```cpp
    return std::accumulate(f.begin(), f.end(), 0) == 26;
    ```

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity is O(n), where n is the length of the input string. This is because each character is processed once.
  
- **Auxiliary Space Complexity**: The auxiliary space complexity is O(1) since the size of the vector `f` is constant (26).


### Code (C++)

```cpp
class Solution {
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(std::string s) {
        std::vector<int> f(26, 0);

        for (auto i : s) {
            char cur = std::tolower(i);

            if (cur >= 'a' && cur <= 'z') {
                f[cur - 'a'] = 1;
            }
        }

        return std::accumulate(f.begin(), f.end(), 0) == 26;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
