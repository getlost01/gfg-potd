## 09. Permutations of a given string

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1)

### My Approach

To find all the permutations of a given string, I have used the following approach:

- I start with the given string `S` and sort it in ascending order to get the lexicographically smallest permutation.
- I store the sorted string in a variable `s`.
- I initialize a vector `out` to store the permutations.
- I add `s` to `out` as the first permutation.
- I sort the string `S` in descending order to get the lexicographically largest permutation.
- I use a while loop that runs until `S` is equal to `s`.
- Inside the loop, I implement the logic to find the next permutation.
  - I start from the rightmost digit of `s` and find the first pair of adjacent digits where the left digit is smaller than the right digit.
  - I find the just greater value from the left digit in the remaining right digits.
  - I swap the left digit with the just greater digit.
  - I sort all the digits to the right of the swapped position in ascending order.
- After each iteration of the while loop, I update `s` with the next permutation and add it to `out`.
- Finally, I return the vector `out` containing all the permutations.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N! * N)`, where `N` is the length of the input string. This is because there are `N!` permutations, and for each permutation, we perform sorting operations on the remaining right digits, which takes `O(N)` time.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N)`, where `N` is the length of the input string. This is due to the space required to store the permutations in the vector `out`.

### Code (C++)

```cpp
class Solution {
public:
    string s = "";

    void perm(int n) {
        int i, j;
        for (i = n - 2; i >= 0; --i) {
            if (s[i] < s[i + 1])
                break;
        }
        for (j = n - 1; j > i; --j) {
            if (s[j] > s[i])
                break;
        }
        swap(s[j], s[i]);
        sort(s.begin() + i + 1, s.end());
    }

    vector<string> find_permutation(string S) {
        int n = S.size();
        vector<string> out;
        sort(S.begin(), S.end());
        s = S;
        out.push_back(s);
        sort(S.begin(), S.end(), greater<>());

        while (S != s) {
            perm(n);
            out.push_back(s);
        }

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.