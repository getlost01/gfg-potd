## 16. String's Count
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints1135/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To count the number of strings that can be formed using 'a', 'b', and 'c' under given conditions, I have used a mathematical formula that represents the total count of strings. The formula is derived based on the possible combinations of these characters.

1. The first term `(1)` represents the case where there is no 'b' or 'c' in the string.
2. The second term `(2 * n)` represents the case where 'b' appears once in the string.
3. The third term `(n * (n - 1))` represents the case where 'b' appears twice in the string.
4. The fourth term `((n * (n - 1)) / 2)` represents the case where 'c' appears once in the string.
5. The fifth term `(n * (n - 1) * (n - 2)) / 2)` represents the case where 'b' appears once and 'c' appears once in the string.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(1)
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
long long int countStr(long long int n){
    return 1 + 2 * n + (n * (n - 1)) + ((n * (n - 1)) / 2) + (n * (n - 1) * (n - 2)) / 2;
}
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.